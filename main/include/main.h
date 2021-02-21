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

char msgTx[255] = "Running\r\n";
char msgTx_sample[255] = "Running\r\n";

unsigned char msgRx[255] = {0};
int msgRxSize = 0;

void DecodeMsgRx (unsigned char * txt);
const char * ADCmsg = "ADC\r\n";
const char * ADCref = "ADC";
const char * PWMref = "PWM";

int Reading = 0;
#endif /* __MAIN_H__ */
