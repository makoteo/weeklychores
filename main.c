/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */

#include <xc.h>
#include <string.h>

/*
#define GROUP0PINCFG16 *(char *)(0x41004450)
#define GROUP0DIR *(unsigned int *)(0x41004400)
#define GROUP0OUT *(unsigned int *)(0x41004410)
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

#define PULLEN 0x4
#define INEN 0x2

#define EPD_RST_PIN GROUP1OUT,RSTPIN
#define EPD_DC_PIN GROUP0OUT, DCPIN
#define EPD_CS_PIN GROUP0OUT, CSPIN
#define EPD_BUSY_PIN GROUP1OUT, BUSYPIN
#define EPD_CLK_PIN GROUP0OUT, CLKPIN
#define EPD_MOSI_PIN GROUP0OUT, MOSIPIN
#define EPD_LED_PIN GROUP1OUT, LEDPIN

#define SET_PIN(_group,_pin,_value) ((_value == 0) ? (_group=_group&(~_pin)) : (_group=_group|_pin))
#define DEV_Digital_Write(_pin, _value) SET_PIN(_pin,_value)
*/

//#include "DEV_Config.h"
#include "EPD_2in7.h"
#include "GUI_Paint.h"
#include <stdlib.h>

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */

/** 
  @Function
    int ExampleLocalFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Description
    Full description, explaining the purpose and usage of the function.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

  @Precondition
    List and describe any required preconditions. If there are no preconditions,
    enter "None."

  @Parameters
    @param param1 Describe the first parameter to the function.
    
    @param param2 Describe the second parameter to the function.

  @Returns
    List (if feasible) and describe the return values of the function.
    <ul>
      <li>1   Indicates an error occurred
      <li>0   Indicates an error did not occur
    </ul>

  @Remarks
    Describe any special behavior not described above.
    <p>
    Any additional remarks.

  @Example
    @code
    if(ExampleFunctionName(1, 2) == 0)
    {
        return 3;
    }
 */

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

// *****************************************************************************

/** 
  @Function
    int ExampleInterfaceFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */

void setClock(UBYTE year, UBYTE month, UBYTE day, UBYTE hour, UBYTE minute, UBYTE second){
    year = year<<2;
    month = month<<4;
    day = day<<3;
    hour = hour<<3;
    minute = minute<<2;
    while(RTC_STATUS != 0){
        delay(1);
    }
    RTC_CLOCK = 0;
    while(RTC_STATUS != 0){
        delay(1);
    }
    UDOUBLE tmp = year<<24|month<<18|day<<14|hour<<9|minute<<4|second;
    while(RTC_STATUS != 0){
        delay(1);
    }
    RTC_CLOCK = tmp;
    while(RTC_STATUS != 0){
        delay(1);
    }
}

void increaseMinute(){
    unsigned int datetime = RTC_CLOCK;
    
    unsigned int year = (datetime >> 26) & 0x000000FF;
    unsigned int month = (datetime >> 22) & 0x0000000F;
    unsigned int day = (datetime >> 17) & 0x0000001F;
    unsigned int hour = (datetime >> 12) & 0x0000001F;
    unsigned int minute = (datetime >> 6) & 0x0000003F;
    unsigned int second = datetime & 0x3F;
    minute+=5;
    if(minute > 59){
        minute-=60;
        hour+=1;
    }
    setClock(year, month, day, hour, minute, second);
}

void readClock(char *TimeAndDate){
    
    while(RTC_STATUS != 0){
        delay(1);
    }
    UDOUBLE datetime = RTC_CLOCK;
    while(RTC_STATUS != 0){
        delay(1);
    }
    
    unsigned int year = (datetime >> 26) & 0x000000FF;
    unsigned int month = (datetime >> 22) & 0x0000000F;
    unsigned int day = (datetime >> 17) & 0x0000001F;
    unsigned int hour = (datetime >> 12) & 0x0000001F;
    unsigned int minute = (datetime >> 6) & 0x0000003F;
    unsigned int second = datetime & 0x3F;

    //unsigned int tmp = 24;
    TimeAndDate[0] = 0x30 + day/10;
    TimeAndDate[1] = 0x30 + day%10;
    TimeAndDate[2] = '/';
    TimeAndDate[3] = 0x30 + month/10;
    TimeAndDate[4] = 0x30 + month%10;
    TimeAndDate[5] = '/';
    TimeAndDate[6] = 0x30 + year/10;
    TimeAndDate[7] = 0x30 + year%10;
    TimeAndDate[8] = ' ';
    TimeAndDate[9] = 0x30 + hour/10;
    TimeAndDate[10] = 0x30 + hour%10;
    TimeAndDate[11] = ':';
    TimeAndDate[12] = 0x30 + minute/10;
    TimeAndDate[13] = 0x30 + minute%10;
    TimeAndDate[14] = 0; //End of string
    //TimeAndDate[11] = 0x30 + second/10;
    //TimeAndDate[12] = 0x30 + second%10;
}

void main(){

    //ADD DCF77
    
    GROUP1DIR = GROUP1DIR|LEDPIN; //SET LED PIN AS OUTPUT
    GROUP1OUT = GROUP1OUT|LEDPIN; //SET LED HIGH
    //GROUP1OUT = GROUP1OUT^LEDPIN;
    
    GROUP0OUT = GROUP0OUT|CSPIN;
    GROUP0DIR = GROUP0DIR|CSPIN;
    
    GROUP0OUT = GROUP0OUT&(~CLKPIN);
    GROUP0DIR = GROUP0DIR|CLKPIN;
    
    GROUP0OUT = GROUP0OUT|DCPIN;
    GROUP0DIR = GROUP0DIR|DCPIN;
    
    //GROUP0PINCFG16 = GROUP0PINCFG16|PULLEN;
    GROUP0OUT = GROUP0OUT|MOSIPIN;
    //GROUP0DIR = GROUP0DIR&(~MOSIPIN);
    GROUP0DIR = GROUP0DIR|MOSIPIN;
    
    GROUP1OUT = GROUP1OUT&(~RSTPIN);
    GROUP1DIR = GROUP1DIR|RSTPIN;
    
    GROUP1OUT = GROUP1OUT|BUSYPIN;
    GROUP1PINCFG11 = GROUP1PINCFG11|PULLEN;
    GROUP1PINCFG11 = GROUP1PINCFG11|INEN;
    GROUP1DIR = GROUP1DIR&(~BUSYPIN);
    
    GROUP1OUT = GROUP1OUT|RSTPIN;
    GROUP1OUT = GROUP1OUT&(~RSTPIN);
    GROUP1OUT = GROUP1OUT|RSTPIN;
    
    //BUTTON
    //GROUP0OUT = GROUP0OUT|BUTTON1PIN;
    //GROUP0PINCFG11 = GROUP0PINCFG11|PULLEN;
    //GROUP0PINCFG11 = GROUP0PINCFG11|INEN;
    //GROUP0DIR = GROUP0DIR&(~BUTTON1PIN);
    
    
    
    //--------------------------
    
    DEV_Digital_Write(EPD_RST_PIN, 0);
    DEV_Digital_Write(EPD_RST_PIN, 1);
    DEV_Digital_Write(EPD_RST_PIN, 0);
    DEV_Digital_Write(EPD_RST_PIN, 1);
    
    //Setting PB22 (mkr zero J5.9) as GCLK_IO[0]
    GROUP1PMUX11 = GROUP1PMUX11|FUNCTION_H_LOW; //datasheet page 385, Set alternate function of PB22 as GCLK_IO[0]
    GROUP1PINCFG22 = GROUP1PINCFG22|PMUXEN; //datasheet page 387, Enable alternate function
    GENCTRL = GENCTRL|GENCTRL_OE; //datasheet page 31 & 126, Send GENCLK00 to GCLK_IO[0]
    
    //Configure 32K external oscillator
    XOSC32K = 0x007F; // datasheet page 191, Enable external 32k crystal
    
    //Connect GENCLK4 to XOSC32K and send it also to PA10 (mkr zero J4.11)
    GROUP0PMUX5 = GROUP0PMUX5|FUNCTION_H_LOW; //datasheet page 385, Set alternate function of PA10 as GCLK_IO[4]
    GROUP0PINCFG10 = GROUP0PINCFG10|PMUXEN; //datasheet page 387, Enable alternate function    
    GENDIV = 0x0000FF04;//divide 32.768khz by 255 = 128
    GENCTRL = 0x00290504; //datasheet page 31 & 126 Connect GENCLK04 to XOSC32K, Send it to GCLK_IO[4] and enable it
    
    
    //-----------------------------------------------------------------------------------------------------------------------------------------------
    FREQCORR = 0x1C;
    
    //Configure RTC
    CLKCTRL = 0x4404; //Datasheet page 123, Connect GENCLK4 to RTC
    DBGCTRL = DBGCTRL|DBGRUN; //Keep running even when debug is stopped
    RTC_CTRL = 0x070A; // Datasheet page 242, divide clock by 128 to get 1Hz, set the MODE 2 (calendar) and enable RTC
    //read CLOCK register to get date & time // Datasheet page 262
    
    UBYTE TimeAndDate[15];
    readClock(TimeAndDate);
    setClock(20,5,30,14,5,0);
    readClock(TimeAndDate);
    
    //Configure SPI SERCOM0
    GROUP0PMUX8 = GROUP0PMUX8|FUNCTION_C_LOW; //datasheet page 385, Set alternate function of PB22 as GCLK_IO[0]
    GROUP0PINCFG16 = GROUP0PINCFG16|PMUXEN; //datasheet page 387, Enable alternate function
    
    GROUP0PMUX8 = GROUP0PMUX8|FUNCTION_C_HIGH; //datasheet page 385, Set alternate function of PB22 as GCLK_IO[0]
    GROUP0PINCFG17 = GROUP0PINCFG17|PMUXEN; //datasheet page 387, Enable alternate function
    
    //DFLLCTRL = 0x02; //Enable 48MHz Clock
    GROUP0PMUX5 = GROUP0PMUX5|FUNCTION_H_HIGH; //datasheet page 385, Set alternate function of PA11 as GCLK_IO[5]
    GROUP0PINCFG11 = GROUP0PINCFG11|PMUXEN; //datasheet page 387, Enable alternate function   
    GENCTRL = 0x00090605; //datasheet page 31 & 126 Connect GENCLK05 to DFLL48M, Send it to GCLK_IO[5] and enable it
    CLKCTRL = 0x4515; //Datasheet page 123, Connect GENCLK5 to SERCOM1
    
    APBCMASK = APBCMASK|0x00000008; //Enables APBC clock for SERCOM1
    SPI_CTRLB = 0x0; //8 bit transfer page 465
    SPI_CTRLA = 0x0000000E; //Enable SPI master
    
    DEV_Module_Init();
    EPD_2IN7_Init_4Gray();
    EPD_2IN7_Clear();
    
   //i = EPD_2in7_test();
    //Create a new image cache
    UBYTE *BlackImage;
    // you have to edit the startup_stm32fxxx.s file and set a big enough heap size
    UWORD Imagesize = ((EPD_2IN7_WIDTH % 8 == 0)? (EPD_2IN7_WIDTH / 8 ): (EPD_2IN7_WIDTH / 8 + 1)) * EPD_2IN7_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        EPD_2IN7_Sleep();
        DEV_Module_Exit();
    }
    Paint_NewImage(BlackImage, EPD_2IN7_WIDTH, EPD_2IN7_HEIGHT, 270, WHITE);
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);
    //Paint_DrawRectangle(20, 70, 70, 120, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    char tmp[] = "Hi!";
    
    Paint_DrawString_EN(10, 20, tmp, &Font24, WHITE, BLACK);
    EPD_2IN7_Display(BlackImage);
    EPD_2IN7_Sleep();
    
    //delay(10);
    //clock();
    
    unsigned int i;
    while(1){
        //clock();
        EPD_2IN7_Wake();
        Paint_Clear(WHITE);
        readClock(TimeAndDate);
        Paint_DrawString_EN(10, 20, TimeAndDate, &Font24, WHITE, BLACK);
        Paint_DrawString_EN(10, 35, " ", &FontTmp, WHITE, BLACK);
        EPD_2IN7_Display(BlackImage);
        EPD_2IN7_Sleep();
        
        UBYTE button1pressed;
        for(i = 0; i < 50; i++){
            delay(500);
            DEV_Digital_Write(EPD_LED_PIN, 1);
            delay(500);
            /*button1pressed = DEV_Digital_Read(EPD_BUTTON1PIN);
            button1pressed =!(button1pressed & 0x01);
            if(button1pressed == 1){
                increaseMinute();
                EPD_2IN7_Wake();
                Paint_Clear(WHITE);
                readClock(TimeAndDate);
                Paint_DrawString_EN(10, 20, TimeAndDate, &Font24, WHITE, BLACK);
                Paint_DrawString_EN(10, 35, " ", &FontTmp, WHITE, BLACK);
                EPD_2IN7_Display(BlackImage);
                EPD_2IN7_Sleep();
            }*/
            DEV_Digital_Write(EPD_LED_PIN, 0);
        }
    
    }
    DEV_Module_Exit();
}

/* *****************************************************************************
 End of File
 */
