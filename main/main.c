#include "main.h"

void app_main(){
	PWM_init();
	TIM_init(1000);
	ADC_init();
	UART_init();
	UART_send(msgTx);
	UART_send((const char *)msgRx);

    while (1) {
		msgRxSize = UART_ReadyToReceive();
		if(msgRxSize > 0){
			UART_Receive(msgRx,msgRxSize);
			UART_send((const char *)msgRx);
			memset(msgRx,0,sizeof(msgRx));
		}
	}
}

void callback_ISR_G0T0 (void){
	PWM_updateDuty(ADC_getRaw());
}