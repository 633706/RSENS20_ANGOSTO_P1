#include "timer.h"

static void ISR_G0T0(void* arg){
	TIMERG0.int_clr_timers.t0 = 1; //reset interrupt status
   	TIMERG0.hw_timer[0].config.alarm_en = 1; //reconfigure alarm
	callback_ISR_G0T0();
}

/* static void ISR_G0T1 (void *arg){	
}
static void ISR_G1T0(void* arg){
}
static void ISR_G1T1 (void *arg){
} */

//Función para inicializar todos los timers al inicio del programa.
void TIM_init (int timer_period_s){
    timer_config_t config = {
            .alarm_en = TIMER_ALARM_EN,				//Alarm Enable
            .counter_en = TIMER_PAUSE,	//If the counter is enabled it will start incrementing / decrementing immediately after calling timer_init()
            .intr_type = TIMER_INTR_LEVEL,	//Is interrupt is triggered on timerâ€™s alarm (timer_intr_mode_t)
            .counter_dir = TIMER_COUNT_UP,	//Does counter increment or decrement (timer_count_dir_t)
            .auto_reload = TIMER_AUTORELOAD_EN,			//If counter should auto_reload a specific initial value on the timerâ€™s alarm, or continue incrementing or decrementing.
            .divider = TIMER_DIVIDER   				//Divisor of the incoming 80 MHz (12.5nS) APB_CLK clock. E.g. 80 = 1uS per timer tick
    };

    timer_init(TIMER_GROUP_0, TIMER_0, &config);
    timer_set_counter_value(TIMER_GROUP_0, TIMER_0, 0);
    timer_set_alarm_value(TIMER_GROUP_0, TIMER_0, timer_period_s * TIMER_SCALE);
    timer_enable_intr(TIMER_GROUP_0, TIMER_0);
    timer_isr_register(TIMER_GROUP_0, TIMER_0, &ISR_G0T0, NULL, 0, &s_timer_handle);

    timer_start(TIMER_GROUP_0, TIMER_0);


}



