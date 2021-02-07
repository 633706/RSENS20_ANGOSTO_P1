#include "ADC.h"

void ADC_init(){
	adc1_config_width(ADC_WIDTH_BIT_12);
	adc1_config_channel_atten(ADC_CHANNEL_6,ADC_ATTEN_DB_11);
}
int ADC_getRaw(){
	return adc1_get_raw(ADC_CHANNEL_6);
}
float ADC_getVoltage(){
	return 3.3*((float)adc1_get_raw(ADC_CHANNEL_6))/4095;
}
