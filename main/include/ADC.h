#ifndef __ADC_H__
#define __ADC_H__

#include "driver/adc.h"
#include "esp_adc_cal.h"


void ADC_init();
int ADC_getRaw();
float ADC_getVoltage();

#endif
