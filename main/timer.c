#include "timer.h"

static intr_handle_t s_timer_handle;
static intr_handle_t s_timer_handle_1;

static void ISR_G0T0(void* arg){
	TIMERG0.int_clr_timers.t0 = 1; //reset interrupt status
   	TIMERG0.hw_timer[0].config.alarm_en = 1; //reconfigure alarm
	callback_ISR_G0T0();
}

static void ISR_G0T1 (void *arg){
	TIMERG0.int_clr_timers.t1 = 1; //reset interrupt status
   	TIMERG0.hw_timer[1].config.alarm_en = 1; //reconfigure alarm
	callback_ISR_G0T1();
}
static void ISR_G1T0(void* arg){
	TIMERG1.int_clr_timers.t0 = 1; //reset interrupt status
   	TIMERG1.hw_timer[0].config.alarm_en = 1; //reconfigure alarm
	callback_ISR_G1T0();
}
static void ISR_G1T1 (void *arg){
	TIMERG1.int_clr_timers.t1 = 1; //reset interrupt status
   	TIMERG1.hw_timer[1].config.alarm_en = 1; //reconfigure alarm
	callback_ISR_G1T1();
}

//Función para inicializar todos los timers al inicio del programa.
void TIM_init (int timer_period_ms, int turnOnPeriod_ms){

    timer_config_t config = {
            .alarm_en = TIMER_ALARM_EN,
            .counter_en = TIMER_PAUSE,
            .intr_type = TIMER_INTR_LEVEL,
            .counter_dir = TIMER_COUNT_UP,
            .auto_reload = TIMER_AUTORELOAD_EN,
            .divider = TIMER_DIVIDER
    };

    timer_init(TIMER_GROUP_0, TIMER_0, &config);
    timer_set_counter_value(TIMER_GROUP_0, TIMER_0, 0);
    timer_set_alarm_value(TIMER_GROUP_0, TIMER_0, 200);//100/1000*(80e6/40e3)
    timer_enable_intr(TIMER_GROUP_0, TIMER_0);
    timer_isr_register(TIMER_GROUP_0, TIMER_0, &ISR_G0T0, NULL, 0, &s_timer_handle);


    timer_init(TIMER_GROUP_0, TIMER_1, &config);
    timer_set_counter_value(TIMER_GROUP_0, TIMER_1, 0);
    timer_set_alarm_value(TIMER_GROUP_0, TIMER_1, 400);//200/1000*(80e6/40e3)
    timer_enable_intr(TIMER_GROUP_0, TIMER_1);
    timer_isr_register(TIMER_GROUP_0, TIMER_1, &ISR_G0T1, NULL, 0, &s_timer_handle_1); 


    timer_start(TIMER_GROUP_0, TIMER_0);
    timer_start(TIMER_GROUP_0, TIMER_1);
}

void TIM_stop(void){
	timer_pause(TIMER_GROUP_0, TIMER_1);
}
void TIM_resume(void){
	timer_start(TIMER_GROUP_0, TIMER_1);
}
