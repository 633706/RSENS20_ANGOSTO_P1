#include "main.h"

void app_main(){
	UART_init();
	LED_init ();
	MPU9250_init();
	MPU9250_WhoAmI(&WhoAmI_);
	if (WhoAmI_ == 0x71){
		TIM_init(100,200);
		sprintf(msgTx_PC,"NO ERROR\r\n");		
	}else{
		sprintf(msgTx_PC,"ERROR, not running");		
	}
		
	UART_send(msgTx_PC);
	
    while (1) {
		MPU9250_get_acc(&accX,&accY,&accZ);
	}
}

//Configured to 100ms, to sample
 void callback_ISR_G0T0 (void){
	
	accX_[samples] = accX;
	accY_[samples] = accY;
	accZ_[samples] = accZ;
	samples ++;
	
	//after 10 samples send data
 	if (samples == 10){
		while (samples != 0){
			accX_mean += accX_[samples];
			accY_mean += accY_[samples];
			accZ_mean += accZ_[samples];
			samples --;
		}
		accX_mean /= 10;
		accY_mean /= 10;
		accZ_mean /= 10;
		sprintf(msgTx_PC,"X: %d\r\nY: %d\r\nZ: %d\r\n\r\n",accX_mean,accY_mean,accZ_mean);
		UART_send(msgTx_PC);
		LED_ON();
		TIM_resume();
		
	}
}

//configured to turn off LED after 200 ms.
void callback_ISR_G0T1 (void){
	LED_OFF();
	TIM_stop();
}
