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
 //Target code modded By kev

#pragma once

#define TARGET_BOARD_IDENTIFIER "SRF3"

//#define LIGHTEN_ME // make OPTIONS=LIGHTEN_ME, takes off sonar,softserial1,mag,baro,adc voltage, adc amperage, rssi

#define CONFIG_FASTLOOP_PREFERRED_ACC ACC_NONE

#define BEEPER                  PC15
#define BEEPER_INVERTED

#define USE_EXTI
#define MPU_INT_EXTI            PC13
#define USE_MPU_DATA_READY_SIGNAL
#define ENSURE_MPU_DATA_READY_IS_LOW

#define GYRO
#define USE_GYRO_MPU6050                   //sprf3
#define GYRO_MPU6050_ALIGN      CW270_DEG  //sprf3

#define ACC
#define USE_ACC_MPU6050                    //sprf3
#define ACC_MPU6050_ALIGN       CW270_DEG  //sprf3

#ifndef LIGHTEN_ME
	#define BARO
	//#define USE_BARO_BMP280
	#define USE_BARO_MS5611                    //sprf3
	//#define USE_BARO_BMP085

	#define MAG
	//#define USE_MAG_AK8975
	#define USE_MAG_HMC5883                    //sprf3
	#define MAG_HMC5883_ALIGN       CW270_DEG  //sprf3

	#define USE_MAG_DATA_READY_SIGNAL
	#define ENSURE_MAG_DATA_READY_IS_HIGH
	#define MAG_INT_EXTI            PC14

	#define SONAR
	#define SONAR_TRIGGER_PIN       PB0
	#define SONAR_ECHO_PIN          PB1
	#define SONAR_SOFTSERIAL1_EXCLUSIVE
#endif

#define USE_UART1
#define USE_UART2
#define USE_UART3

#ifndef LIGHTEN_ME
	//#define USE_VCP                  // PA11 mtr3 pin    PA12 mtr4 pin   need to add vcp to feature in target.mk
	#define USE_SOFTSERIAL1
	#define SOFTSERIAL1_RX_PIN      PB0  // PWM 5
	#define SOFTSERIAL1_TX_PIN      PB1  // PWM 6
	//#define USE_SOFTSERIAL2            // i think this if for vcp
	#define SERIAL_PORT_COUNT       4    // 6 if using vcp and softserial2
#else
	#define SERIAL_PORT_COUNT       3
#endif

#define UART1_TX_PIN            PA9
#define UART1_RX_PIN            PA10

#define UART2_TX_PIN            PA14 // PA14 / SWCLK
#define UART2_RX_PIN            PA15

#define UART3_TX_PIN            PB10 // PB10 (AF7)
#define UART3_RX_PIN            PB11 // PB11 (AF7)

#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C_DEVICE              (I2CDEV_1)

#define USE_SPI
#define USE_SPI_DEVICE_2 // PB12,13,14,15 on AF5

#define USE_FLASHFS
#define USE_FLASH_M25P16
#define M25P16_CS_PIN           PB12
#define M25P16_SPI_INSTANCE     SPI2
#define ENABLE_BLACKBOX_LOGGING_ON_SPIFLASH_BY_DEFAULT

#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ESC  // wraith32 35a esc telemetry
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ESC  // wraith32 35a esc telemetry

#ifndef LIGHTEN_ME
	#define USE_ADC
	#define ADC_INSTANCE            ADC2
	#define VBAT_ADC_PIN            PA4

	#define USE_MSP_CURRENT_METER
	#define CURRENT_METER_ADC_PIN   PA5

	#define RSSI_ADC_PIN            PB2
	
	#define OSD
	#define USE_OSD_OVER_MSP_DISPLAYPORT
	#define USE_SLOW_MSP_DISPLAYPORT_RATE_WHEN_UNARMED
#endif

#define USE_ESCSERIAL
#define ESCSERIAL_TIMER_TX_PIN  PA0 // unsure what this even does
#define USE_ESC_SENSOR

#define REMAP_TIM16_DMA
#define REMAP_TIM17_DMA

#define DEFAULT_RX_FEATURE      FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_SBUS
#define SERIALRX_UART           SERIAL_PORT_USART3
//#define SBUS_TELEMETRY_UART     SERIAL_PORT_USART3
#define DEFAULT_FEATURES        (FEATURE_TELEMETRY)

#define USE_SERIAL_4WAY_BLHELI_INTERFACE

// IO - stm32f303cc in 48pin package
#define TARGET_IO_PORTA         0xffff
#define TARGET_IO_PORTB         0xffff
#define TARGET_IO_PORTC         (BIT(13)|BIT(14)|BIT(15))
#define TARGET_IO_PORTF         (BIT(0)|BIT(1)|BIT(3)|BIT(4))

#define USABLE_TIMER_CHANNEL_COUNT 10
#define USED_TIMERS             ( TIM_N(1) | TIM_N(2) | TIM_N(3) | TIM_N(4) | TIM_N(8) | TIM_N(15) | TIM_N(16) | TIM_N(17) )
