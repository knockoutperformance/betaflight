#include <stdbool.h>
#include <stdint.h>

#include <platform.h>
#include "drivers/io.h"

#include "drivers/timer.h"
#include "drivers/timer_def.h"
#include "drivers/dma.h"

const timerHardware_t timerHardware[USABLE_TIMER_CHANNEL_COUNT] = {
    DEF_TIM(TIM2,  CH1, PA0,  TIM_USE_PWM | TIM_USE_PPM,   0), // RC_CH1 - PA0  - *TIM2_CH1
    DEF_TIM(TIM2,  CH2, PA1,  TIM_USE_PWM,                 0), // RC_CH2 - PA1  - *TIM2_CH2, TIM15_CH1N
    DEF_TIM(TIM2,  CH4, PB11, TIM_USE_PWM,                 0), // RC_CH3 - PB11 - *TIM2_CH4, UART3_RX (AF7)
    DEF_TIM(TIM2,  CH3, PB10, TIM_USE_PWM,                 0), // RC_CH4 - PB10 - *TIM2_CH3, UART3_TX (AF7)
    DEF_TIM(TIM3,  CH3, PB0,  TIM_USE_PWM,                 0), // RC_CH5 - PB0  - *TIM3_CH3, TIM1_CH2N, TIM8_CH2N
    DEF_TIM(TIM3,  CH4, PB1,  TIM_USE_PWM,                 0), // RC_CH6 - PB1  - *TIM3_CH4, TIM1_CH3N, TIM8_CH3N	           		    
  	DEF_TIM(TIM16, CH1, PA6,  TIM_USE_MOTOR,               TIMER_OUTPUT_ENABLED),  //mtr1  - m1 pin                         DMA(1,6)
  	DEF_TIM(TIM8,  CH1N,PA7,  TIM_USE_MOTOR,               TIMER_OUTPUT_ENABLED | TIMER_OUTPUT_INVERTED), //mtr2 - m2 pin   DMA(2,3)
  	DEF_TIM(TIM8,  CH2, PB8,  TIM_USE_MOTOR,               TIMER_OUTPUT_ENABLED),  //mtr3  - m5 pin                         DMA(2,5)
  	DEF_TIM(TIM17, CH1, PB9,  TIM_USE_MOTOR,               TIMER_OUTPUT_ENABLED),  //mtr4  - m6 pin					                DMA(1,7)
  	DEF_TIM(TIM4,  CH1, PA11, TIM_USE_MOTOR,               1), // PWM3 - PA11 //mtr5 - m3 pin
	  DEF_TIM(TIM4,  CH2, PA12, TIM_USE_MOTOR,               1), // PWM4 - PA12 //mtr6 - m4 pin
    DEF_TIM(TIM15, CH1, PA2,  TIM_USE_MOTOR,               1), // PWM7 - PA2  //mtr7 - m7 pin
    DEF_TIM(TIM15, CH2, PA3,  TIM_USE_MOTOR,               1), // PWM8 - PA3  //mtr8 - m8 pin
    DEF_TIM(TIM1,  CH1, PA8,  TIM_USE_MOTOR | TIM_USE_LED, 1), // GPIO_TIMER / LED_STRIP
};
