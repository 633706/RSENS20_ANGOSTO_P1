#include "main.h"

void app_main(){
	PWM_init();
	TIM_init(100);
	ADC_init();
	UART_init();
	const char * msg = "Running\r\n";
	UART_send(msg);
    while (1) {

	}
}

void callback_ISR_G0T0 (void){
	PWM_updateDuty(ADC_getRaw());
}