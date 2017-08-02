F3_TARGETS   += $(TARGET)
FEATURES    = ONBOARDFLASH

TARGET_SRC = \
            drivers/accgyro/accgyro_mpu.c \
			drivers/accgyro/accgyro_mpu6050.c
ifneq ($(OPTIONS), LIGHTEN_ME)
TARGET_SRC += \
			drivers/barometer/barometer_ms5611.c \
			drivers/compass/compass_hmc5883l.c
endif
