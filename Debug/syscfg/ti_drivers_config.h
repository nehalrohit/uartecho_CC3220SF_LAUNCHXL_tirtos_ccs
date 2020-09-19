/*
 *  ======== ti_drivers_config.h ========
 *  Configured TI-Drivers module declarations
 *
 *  The macros defines herein are intended for use by applications which
 *  directly include this header. These macros should NOT be hard coded or
 *  copied into library source code.
 *
 *  Symbols declared as const are intended for use with libraries.
 *  Library source code must extern the correct symbol--which is resolved
 *  when the application is linked.
 *
 *  DO NOT EDIT - This file is generated for the CC3220SF_LAUNCHXL
 *  by the SysConfig tool.
 */
#ifndef ti_drivers_config_h
#define ti_drivers_config_h

#define CONFIG_SYSCONFIG_PREVIEW

#define CONFIG_CC3220SF_LAUNCHXL
#ifndef DeviceFamily_CC3220
#define DeviceFamily_CC3220
#endif

#include <ti/devices/DeviceFamily.h>

#include <stdint.h>

/* support C++ sources */
#ifdef __cplusplus
extern "C" {
#endif


/*
 *  ======== ADC ========
 */

/* P59 */
extern const uint_least8_t          CONFIG_ADC_0_CONST;
#define CONFIG_ADC_0                0


/*
 *  ======== GPIO ========
 */

/* P63 */
extern const uint_least8_t          Alert_GPIO_CONST;
#define Alert_GPIO                  0
/* P18 */
extern const uint_least8_t          CONFIG_GPIO_ss_CONST;
#define CONFIG_GPIO_ss              1
/* P03 */
extern const uint_least8_t          CONFIG_IN2_CONST;
#define CONFIG_IN2                  2
/* P08 */
extern const uint_least8_t          CONFIG_GPIO_nsleep_CONST;
#define CONFIG_GPIO_nsleep          3
/* P50 */
extern const uint_least8_t          CONFIG_GPIO_fault_CONST;
#define CONFIG_GPIO_fault           4

/* LEDs are active high */
#define CONFIG_GPIO_LED_ON  (1)
#define CONFIG_GPIO_LED_OFF (0)

#define CONFIG_LED_ON  (CONFIG_GPIO_LED_ON)
#define CONFIG_LED_OFF (CONFIG_GPIO_LED_OFF)


/*
 *  ======== I2C ========
 */

/*
 *  SCL: P01
 *  SDA: P02
 *  LaunchPad I2C
 */
extern const uint_least8_t          CONFIG_I2C_TMP_CONST;
#define CONFIG_I2C_TMP              0

/* ======== I2C Addresses and Speeds ======== */
#include <ti/drivers/I2C.h>

/* ---- CONFIG_I2C_TMP I2C bus components ---- */

/* BMA222E address and max speed */
#define CONFIG_I2C_TMP_BMA222E_ADDR     (0x18)
#define CONFIG_I2C_TMP_BMA222E_MAXSPEED (400U) /* Kbps */

/* TMP006 address and max speed */
#define CONFIG_I2C_TMP_TMP006_ADDR     (0x41)
#define CONFIG_I2C_TMP_TMP006_MAXSPEED (3400U) /* Kbps */

/* CONFIG_I2C_TMP max speed (supported by all components) */
#define CONFIG_I2C_TMP_MAXSPEED   (3400U) /* Kbps */
#define CONFIG_I2C_TMP_MAXBITRATE ((I2C_BitRate)I2C_3400kHz)


/*
 *  ======== PWM ========
 */

/* P21 */
extern const uint_least8_t          CONFIG_PWM_1_CONST;
#define CONFIG_PWM_1                0
/* P64, LaunchPad LED D10 (Red) */
extern const uint_least8_t          CONFIG_PWM_Buzzer_CONST;
#define CONFIG_PWM_Buzzer           1


/*
 *  ======== SPI ========
 */

extern const uint_least8_t          CONFIG_NWP_SPI_CONST;
#define CONFIG_NWP_SPI              0
/*
 *  MOSI: P07
 *  MISO: P06
 *  SCLK: P05
 */
extern const uint_least8_t          CONFIG_SPI_0_CONST;
#define CONFIG_SPI_0                1


/*
 *  ======== Timer ========
 */

extern const uint_least8_t          CONFIG_TIMER_0_CONST;
#define CONFIG_TIMER_0              0
extern const uint_least8_t          CONFIG_TIMER_1_CONST;
#define CONFIG_TIMER_1              1
extern const uint_least8_t          CONFIG_TIMER_2_CONST;
#define CONFIG_TIMER_2              2

/*
 *  ======== UART ========
 */

/*
 *  TX: P55
 *  RX: P57
 *  XDS110 UART
 */
extern const uint_least8_t          CONFIG_UART_0_CONST;
#define CONFIG_UART_0               0


/*
 *  ======== UART2 ========
 */

/*
 *  TX: P62
 *  RX: P45
 */
extern const uint_least8_t          CONFIG_UART2_0_CONST;
#define CONFIG_UART2_0              0


/*
 *  ======== Board_init ========
 *  Perform all required TI-Drivers initialization
 *
 *  This function should be called once at a point before any use of
 *  TI-Drivers.
 */
extern void Board_init(void);

/*
 *  ======== Board_initGeneral ========
 *  (deprecated)
 *
 *  Board_initGeneral() is defined purely for backward compatibility.
 *
 *  All new code should use Board_init() to do any required TI-Drivers
 *  initialization _and_ use <Driver>_init() for only where specific drivers
 *  are explicitly referenced by the application.  <Driver>_init() functions
 *  are idempotent.
 */
#define Board_initGeneral Board_init

#ifdef __cplusplus
}
#endif

#endif /* include guard */
