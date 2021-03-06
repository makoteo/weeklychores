/*****************************************************************************
* | File      	:   DEV_Config.h
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*                Used to shield the underlying layers of each master 
*                and enhance portability
*----------------
* |	This version:   V2.0
* | Date        :   2018-10-30
* | Info        :
* 1.add:
*   UBYTE\UWORD\UDOUBLE
* 2.Change:
*   EPD_RST -> EPD_RST_PIN
*   EPD_DC -> EPD_DC_PIN
*   EPD_CS -> EPD_CS_PIN
*   EPD_BUSY -> EPD_BUSY_PIN
* 3.Remote:
*   EPD_RST_1\EPD_RST_0
*   EPD_DC_1\EPD_DC_0
*   EPD_CS_1\EPD_CS_0
*   EPD_BUSY_1\EPD_BUSY_0
* 3.add:
*   #define DEV_Digital_Write(_pin, _value) bcm2835_gpio_write(_pin, _value)
*   #define DEV_Digital_Read(_pin) bcm2835_gpio_lev(_pin)
*   #define DEV_SPI_WriteByte(__value) bcm2835_spi_transfer(__value)
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_

//#include "main.h"
//#include "stm32f1xx_hal.h"
//#include "stm32f1xx_hal_gpio.h"
#include <stdint.h>

/**
 * data
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

#define WORD int16_t
#define DOUBLE int32_t

/**
 * e-Paper GPIO
**/
/* #define EPD_RST_PIN     RST_GPIO_Port, RST_Pin
#define EPD_DC_PIN      DC_GPIO_Port, DC_Pin
#define EPD_CS_PIN      SPI_CS_GPIO_Port, SPI_CS_Pin
#define EPD_BUSY_PIN    BUSY_GPIO_Port, BUSY_Pin
*/

#define GROUP0PINCFG16 *(char *)(0x41004450)
#define GROUP0PINCFG11 *(char *)(0x4100444B)
#define GROUP0DIR *(unsigned int *)(0x41004400)
#define GROUP0OUT *(unsigned int *)(0x41004410)
#define GROUP0IN *(unsigned int *)(0x41004420)
#define CSPIN 0x200000 //Orange, 7
#define DCPIN 0x100000 //Green, 6
#define CLKPIN 0x20000 //Yellow, 9
#define MOSIPIN 0x10000 //Blue, 8

#define GROUP1PINCFG11 *(char *)(0x410044CB)
#define GROUP1DIR *(unsigned int *)(0x41004480)
#define GROUP1OUT *(unsigned int *)(0x41004490)
#define GROUP1IN *(unsigned int *)(0x410044A0)
#define RSTPIN 0x400 //White, 4
#define BUSYPIN 0x800 //Purple, 5
#define LEDPIN 0x100
#define BUTTON1PIN 0x800

#define CLKCTRL *(unsigned short *)(0x40000C02)
#define GROUP0PMUX5 *(unsigned char *)(0x41004435)
#define GROUP1PMUX11 *(unsigned char *)(0x410044BB)
#define GENCTRL *(unsigned int *)(0x40000C04)
#define GROUP0PINCFG10 *(unsigned char *)(0x4100444A)
#define GROUP1PINCFG22 *(unsigned char *)(0x410044D6)
#define XOSC32K *(unsigned short *)(0x40000814)
#define RTC_CTRL *(unsigned short *)(0x40001400)
#define GENDIV *(unsigned int *)(0x40000C08)
#define DBGCTRL *(unsigned char *)(0x4000140B)
#define RTC_CLOCK *(unsigned int *)(0x40001410)
#define RTC_STATUS *(unsigned char *)(0x40001801)

#define RTC_EVCTRL *(unsigned short *)(0x40001404)
#define RTC_INTFLAG *(unsigned char *)(0x40001408)
#define RTC_ALARM *(unsigned int *)(0x40001418)
#define RTC_MASK *(unsigned char *)(0x4000141C)
#define RTC_INTENSET *(unsigned char *)(0x40001407)
#define NVIC_ISER *(unsigned int *)(0xE000E100)
#define NVIC_ICER *(unsigned int *)(0xE000E180)
#define NVIC_ICPR *(unsigned int *)(0xE000E280)

#define SPI_CTRLA *(unsigned int *)(0x42000C00)
#define SPI_CTRLB *(unsigned int *)(0x42000C04)
#define SPI_INTFLAG *(unsigned char *)(0x42000C18)
#define SPI_DATA *(unsigned short *)(0x42000C28)
#define SPI_DRE 0x01
#define DFLLCTRL *(unsigned short *)(0x40000C24)
#define SPI_SYNCBUSY *(unsigned int *)(0x42000C1C)

#define GROUP0PMUX8 *(unsigned char *)(0x41004438)
#define GROUP0PINCFG17 *(unsigned char *)(0x41004451)
#define APBCMASK *(unsigned int *)(0x40000420)

#define GROUP0PMUX4 *(unsigned char *)(0x41004434)
#define GROUP0PINCFG8 *(unsigned char *)(0x41004448)
#define GROUP0PINCFG9 *(unsigned char *)(0x41004449)

#define I2C_CTRLA *(unsigned int *)(0x42000800)
#define I2C_CTRLB *(unsigned int *)(0x42000804)
#define I2C_BAUD *(unsigned short *)(0x4200080C)
#define I2C_ADDR *(unsigned int *)(0x42000824)
#define I2C_DATA *(unsigned short *)(0x42000828)
#define I2C_INTFLAG *(unsigned char *)(0x42000818)
#define I2C_STATUS *(unsigned short *)(0x4200081A)

#define FREQCORR *(unsigned char *)(0x4000140B)

#define SCR *(unsigned int *)(0xE000ED10)

#define FUNCTION_H_LOW 0x07
#define FUNCTION_H_HIGH 0x70
#define FUNCTION_C_LOW 0x02
#define FUNCTION_C_HIGH 0x20
#define GENCTRL_OE 0x80000
#define PMUXEN 0x1
#define DBGRUN 0x1

#define PULLEN 0x4
#define INEN 0x2

#define SLEEPDEEP 0x4

#define EPD_RST_PIN GROUP1OUT,RSTPIN
#define EPD_DC_PIN GROUP0OUT, DCPIN
#define EPD_CS_PIN GROUP0OUT, CSPIN
#define EPD_BUSY_PIN GROUP1IN, BUSYPIN
#define EPD_CLK_PIN GROUP0OUT, CLKPIN
#define EPD_MOSI_PIN GROUP0OUT, MOSIPIN
#define EPD_LED_PIN GROUP1OUT, LEDPIN

#define EPD_BUTTON1PIN GROUP0IN, BUTTON1PIN

#define SET_PIN(_group,_pin,_value) ((_value == 0) ? (_group=_group&(~_pin)) : (_group=_group|_pin))
#define DEV_Digital_Write(_pin, _value) SET_PIN(_pin,_value)

/**
 * GPIO read and write
**/
//#define DEV_Digital_Write(_pin, _value) HAL_GPIO_WritePin(_pin, _value == 0? GPIO_PIN_RESET:GPIO_PIN_SET)
//#define DEV_Digital_Read(_pin) HAL_GPIO_ReadPin(_pin) 
#define GET_PIN(_group,_pin) (((_group&_pin) == 0) ? (0):(1))
#define DEV_Digital_Read(_pin) GET_PIN(_pin) 

/**
 * delay x ms
**/
#define DEV_Delay_ms(__xms) delay(__xms);

void DEV_SPI_WriteByte(UBYTE value);

void DEV_Module_Init(void);
void DEV_Module_Exit(void);
void delay(UDOUBLE ms);
void clock(void);
#endif