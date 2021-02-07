#include "UART.h"

void UART_init (){
	uart_config_t PC_COM = {
		.baud_rate = 115200,
		.data_bits = UART_DATA_8_BITS,
		.parity = UART_PARITY_DISABLE,
		.stop_bits = UART_STOP_BITS_1,
		.flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
		.use_ref_tick = 1,
	//	.source_clk = UART_SCLK_REF_TICK,
	};
	uart_param_config(UART_NUM_0, &PC_COM);
	uart_driver_install(UART_NUM_0, 255, 255, 0, NULL, 0);
	
	 uart_set_pin(UART_NUM_0, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}

void UART_send (const char * txt){
	uart_write_bytes(UART_NUM_0,txt,strlen(txt));
}
