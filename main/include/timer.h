#ifndef __TIMER_H__
#define __TIMER_H__

#include "esp_intr_alloc.h"
#include "esp_attr.h"
#include "driver/timer.h"




//define para ajuste del compare value de manera automática
#define TIMER_DIVIDER	48000
#define TIMER_SCALE     (TIMER_BASE_CLK / TIMER_DIVIDER)

static intr_handle_t s_timer_handle;

void TIM_init (int timer_period_ms);
void TIM_updateAlarm (int timer_period_s);
void TIM_stop (void);

void callback_ISR_G0T0 (void);
void callback_ISR_G0T1 (void);
void callback_ISR_G1T0 (void);
void callback_ISR_G1T1 (void);
#endif
