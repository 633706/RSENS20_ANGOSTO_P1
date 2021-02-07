#include "PWM.h"
void PWM_init(){
	ledc_timer_config_t ledc_timer = {
		.duty_resolution = LEDC_TIMER_12_BIT, // resolution of PWM duty
		.freq_hz = 5000,                      // frequency of PWM signal
		.speed_mode = LEDC_HIGH_SPEED_MODE,           // timer mode
		.timer_num = LEDC_TIMER_0,            // timer index
	//	.clk_cfg = LEDC_AUTO_CLK,              // Auto select the source clock
	};
	ledc_timer_config(&ledc_timer);

	ledc_channel_config_t ledc_channel= {
		.channel    = LEDC_CHANNEL_0,
		.duty       = 2000,
		.gpio_num   = LEDC_HS_CH0_GPIO,
		.speed_mode = LEDC_HIGH_SPEED_MODE,
		.hpoint     = 0,
		.timer_sel  = LEDC_TIMER_0
	};
	ledc_channel_config(&ledc_channel);
}
