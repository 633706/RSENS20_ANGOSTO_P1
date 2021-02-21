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


const char * msgTx = "Running\r\n";
unsigned char msgRx[255] = {0};
int msgRxSize = 0;


#endif /* __MAIN_H__ */
