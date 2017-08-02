/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */
 //Target code modded By Kev

#include <stdint.h>

#include <platform.h>
#include "drivers/io.h"

#include "drivers/timer.h"
#include "drivers/timer_def.h"
#include "drivers/dma.h"

const timerHardware_t timerHardware[USABLE_TIMER_CHANNEL_COUNT] = {
    DEF_TIM(TIM2, CH1, PA0, TIM_USE_PPM, 0),                                     // ppm
        // Motors 1-4
    DEF_TIM(TIM16,CH1, PA6, TIM_USE_MOTOR,               TIMER_OUTPUT_ENABLED),  //mtr1  -sprf3 m1 pin                       DMA(1,6)
    DEF_TIM(TIM8, CH1N,PA7, TIM_USE_MOTOR,               TIMER_OUTPUT_ENABLED | TIMER_OUTPUT_INVERTED), //mtr2 -sprf3 m2 pin DMA(2,3)
    DEF_TIM(TIM8, CH2, PB8, TIM_USE_MOTOR,               TIMER_OUTPUT_ENABLED),  //mtr3  -sprf3 m5 pin                       DMA(2,5)
    DEF_TIM(TIM17,CH1, PB9, TIM_USE_MOTOR,               TIMER_OUTPUT_ENABLED),  //mtr4  -sprf3 m6 pin                       DMA(1,7)
    // Motors 5-6 or SoftSerial
    DEF_TIM(TIM3, CH3, PB0, TIM_USE_MOTOR,               TIMER_OUTPUT_ENABLED),  //mtr5  -sprf3 SONAR_TRIGGER_PIN            DMA(1,2)
    DEF_TIM(TIM3, CH4, PB1, TIM_USE_MOTOR,               TIMER_OUTPUT_ENABLED),  //mtr6  -sprf3 SONAR_ECHO_PIN               DMA(1,3)
    // Motors 7-8 or UART2
    DEF_TIM(TIM2, CH4, PA3, TIM_USE_MOTOR,               TIMER_OUTPUT_ENABLED),  //mtr7  -sprf3 m7 pin   UART2_RX
    DEF_TIM(TIM2, CH3, PA2, TIM_USE_MOTOR,               TIMER_OUTPUT_ENABLED),  //mtr8  -sprf3 m8 pin   UART2_TX
    // No LED for Hexa-Dshot; DMA conflict with Motor 5 (PB0); consider PPM if not used.
    DEF_TIM(TIM1, CH1, PA8, TIM_USE_LED,                 TIMER_OUTPUT_ENABLED),  //LED_STRIP                   DMA(1,2)
};
