/*****************************************************************************
* | File      	:   DEV_Config.c
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*                Used to shield the underlying layers of each master
*                and enhance portability
*----------------
* |	This version:   V2.0
* | Date        :   2018-10-30
* | Info        :
# ******************************************************************************
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
#include "DEV_Config.h"
//#include "stm32f1xx_hal_spi.h"

//extern SPI_HandleTypeDef hspi1;

void DEV_SPI_WriteByte(UBYTE value)
{
    //HAL_SPI_Transmit(&hspi1, &value, 1, 1000);
        
    UDOUBLE i;
    
    /*for(i = 0; i < 8; i++){

        if(0x80&value){
            GROUP0OUT = GROUP0OUT|MOSIPIN;
        }else{
            GROUP0OUT = GROUP0OUT&(~MOSIPIN);
        }
        
        value=value<<1;
        
        //delay(5);
        GROUP0OUT = GROUP0OUT|CLKPIN;
        //delay(5);
        GROUP0OUT = GROUP0OUT&(~CLKPIN);
        
    }*/
    
    while(SPI_SYNCBUSY != 0){

    }
    SPI_DATA = value;
}

void DEV_Module_Init(void)
{
    DEV_Digital_Write(EPD_DC_PIN, 0);
    DEV_Digital_Write(EPD_CS_PIN, 0);
    DEV_Digital_Write(EPD_RST_PIN, 1);
}

void DEV_Module_Exit(void)
{
    DEV_Digital_Write(EPD_DC_PIN, 0);
    DEV_Digital_Write(EPD_CS_PIN, 0);

    //close 5V
    DEV_Digital_Write(EPD_RST_PIN, 0);
}

void delay(UDOUBLE ms){
    UDOUBLE t;
    
    UDOUBLE loopCount = ms*84;
    
    //0 = 26.8
    //1 = 38.6
    //10 = 145
    
    //1 Loop = 38.6 - 26.8 = 11.8
    //10 Loops = 145 - 26.8 = 118.2
    
    //GROUP0OUT = GROUP0OUT|CLKPIN;
    for(t = 0; t < loopCount; t++){
        
    }
    //GROUP0OUT = GROUP0OUT&(~CLKPIN);
}

void clock(void){
    UDOUBLE i;
    for(i = 0; i < 8; i++){
        GROUP0OUT = GROUP0OUT|CLKPIN;
        GROUP0OUT = GROUP0OUT&(~CLKPIN);
    }
}
