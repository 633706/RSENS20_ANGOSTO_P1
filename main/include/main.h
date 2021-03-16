#ifndef __MAIN_H__
#define __MAIN_H__
//Librerarías estandar de  C
#include <stdio.h>
#include <string.h>
//drivers propios ESP32
#include "ADC.h"
#include "timer.h"
#include "PWM.h"
#include "UART.h"
#include "I2C.h"
#include "GPIO.h"

#include "MPU9250.h"

char msgTx_PC[255] = "Running\r\n";

int samples = 0;
uint8_t WhoAmI_ = 0;
int accX = 0;
int accY = 0;
int accZ = 0;

int accX_[10] = {0};
int accY_[10] = {0};
int accZ_[10] = {0};

int accX_mean = 0;
int accY_mean = 0;
int accZ_mean = 0;

#endif /* __MAIN_H__ */
