#include "main.h"

void app_main(){
	PWM_init();
	TIM_init((60*1000));
	ADC_init();
	UART_init();
	UART_send(msgTx);
	UART_send((const char *)msgRx);

    while (1) {
		msgRxSize = UART_ReadyToReceive();
		if(msgRxSize > 0){
			UART_Receive(msgRx,msgRxSize);
			DecodeMsgRx(msgRx);
			memset(msgRx,0,sizeof(msgRx));
		}
	}
}

void callback_ISR_G0T0 (void){
	Reading = ADC_getRaw();
	sprintf(msgTx_sample,"%d\r\n",Reading);
	UART_send(msgTx_sample);
}

void DecodeMsgRx (unsigned char * txt){
	// Message ADC\r\n
	if(strcmp((const char *)txt,ADCmsg) == 0){
		sprintf(msgTx,"%d\r\n",ADC_getRaw());
		
	// Message ADC(x)\r\n
	}else if (strstr((const char *)txt,ADCref) != NULL){
		int SampleTime = 0;
		int i = 4;
		while(txt[i] != ')'){
			SampleTime = (SampleTime*10)+(txt[i]-0x30);
			i++;
		}
			
		if(SampleTime == 0){
			TIM_stop ();
			sprintf(msgTx,"Sampling Paused\r\n");
		}else{
			TIM_updateAlarm(SampleTime);
			sprintf(msgTx,"Sample time: %d\r\n",SampleTime);
		}	
		
	// Message PWM(x)\r\n
	}else if(strstr((const char *)txt,PWMref) != NULL){
		int duty = (txt[4]-0x30)*455; //455 = 4095/9
		PWM_updateDuty(duty);

		sprintf(msgTx,"Duty: %d\r\n",duty);
	}

	UART_send(msgTx);		
	memset(msgTx,0,sizeof(msgTx));	
}
