#include "main.h"

void app_main(){
 //	PWM_init();
	TIM_init(10);
	ADC_init();
	UART_init();
	const char * msg = "Running\r\n";
	UART_send(msg);
    while (1) {

	}
}

void callback_ISR_G0T0 (void){
	char msg[255] = "";
	sprintf (msg,"ADC reading: %d\r\n",ADC_getRaw());
	UART_send(msg);
}