#ifndef __PWM_H__
#define __PWM_H__

#include "driver/ledc.h"
#include "esp_err.h"

#define LEDC_HS_CH0_GPIO       (18)

void PWM_init();

#endif
