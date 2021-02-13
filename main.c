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

//#include <sys/attribs.h>
//void __attribute__((interrupt, vector(0))) _CoreTimerHandler(void)
//{
    //DEV_Digital_Write(EPD_LED_PIN, 1);
//}
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

static char* Meniny[12][32] = {
    {"tmp"},
    {"", "Novy rok", "Alexandra, Karina", "Daniela", "Drahoslav", "Andrea", "Antonia", "Bohuslava", "Severin", "Alexej", "Dasa", "Malvina", "Ernest", "Rastislav", "Radovan", "Dobroslav", "Kristina", "Natasa", "Bohdana", "Drahomira, Mario", "Dalibor", "Vincent", "Zora", "Milos", "Timotej", "Gejza", "Tamara", "Bohus", "Alfonz", "Gaspar", "Ema", "Emil"}, 
    {"", "Tatiana", "Erika, Erik", "Blazej", "Veronika", "Agata", "Dorota", "Vanda", "Zoja", "Zdenko1", "Gabriela", "Dezider", "Perla", "Arpad", "Valentin", "Pravoslav", "Ida,Liana", "Miloslava", "Jaromir", "Vlasta", "Livia", "Eleonora", "Etela", "Roman,Romana", "Matej", "Frederik,Frederika", "Viktor", "Alexander", "Zlatica", "Radomir"},
    {"", "Albin", "Anezka", "Bohumil,Bohumila", "Kazimir", "Fridrich", "Radoslav,Radoslava", "Tomas", "Alan,Alana", "Frantiska1", "Bruno,Branislav", "Angela,Angelika", "Gregor", "Vlastimil", "Matilda", "Svetlana", "Boleslav", "Lubica", "Eduard", "Jozef", "Vitazoslav,Klaudius", "Blahoslav", "Benadik", "Adrian", "Gabriel", "Marian", "Emanuel", "Alena", "Sona", "Miroslav", "Vieroslava", "Benjamin"},
    {"", "Hugo", "Zita", "Richard", "Izidor", "Miroslava", "Irena", "Zoltan", "Albert", "Milena1", "Igor", "Julius", "Estera", "Ales", "Justina", "Fedor", "Dana,Danica", "Rudolf,Rudolfa", "Valer", "Jela", "Marcel", "Ervin", "Slavomir", "Vojtech", "Juraj", "Marek", "Jaroslava", "Jaroslav", "Jarmila", "Lea", "Anastazia"},
    {"", "Sviatok Prace", "Zigmund", "Galina,Timea", "Florian", "Lesia,Lesana", "Hermina", "Monika", "Ingrida", "Roland1", "Viktoria", "Blazena", "Pankrac", "Servac", "Bonifac", "Zofia,Sofia", "Svetozar", "Gizela,Aneta", "Viola", "Gertruda", "Bernard", "Zina", "Julia,Juliana", "Zelmira", "Ela", "Urban,Vivien", "Dusan", "Iveta", "Viliam", "Vilma", "Ferdinand", "Petrana,Petronela"},
    {"", "Zaneta", "Xenia, Oxana", "Karolina", "Lenka", "Laura", "Norbert", "Robert,Roberta", "Medard", "Stanislava1", "Margareta,Greta", "Dobroslava", "Zlatko", "Anton", "Vasil", "Vit", "Blanka,Bianka", "Adolf", "Vratislav", "Alfred", "Valeria", "Alojz", "Paulina", "Sidonia", "Jan", "Olivia,Tadeas", "Adriana", "Ladislav,Ladislava", "Beata", "Peter,Pavol,Petra", "Melania"},
    {"", "Diana", "Berta", "Miloslav", "Prokop", "Cyril,Metod", "Patrik,Patricia", "Oliver", "Ivan", "Lujza1", "Amalia", "Milota", "Nina", "Margita", "Kamil", "Henrich", "Drahomir,Rut", "Bohuslav", "Kamila", "Dusana", "Ilja,Elias", "Daniel", "Magdalena", "Olga", "Vladimir", "Jakub,Timur", "Anna,Hana,Anita", "Bozena", "Kristof", "Marta", "Libusa", "Ignac"}, 
    {"", "Bozidara", "Gustav", "Jergus", "Dominika,Dominik", "Hortenzia", "Jozefina", "Stefania", "Oskar", "Lubomira1", "Vavrinec", "Zuzana", "Darina", "Lubomir", "Mojmir", "Marcela", "Leonard", "Milica", "Elena,Helena", "Lydia", "Anabela,Liliana", "Jana", "Tichomir", "Filip", "Bartolomej", "Ludovit", "Samuel", "Silvia", "Augustin", "Nikola,Nikolaj", "Ruzena", "Nora"},
    {"", "Drahoslava", "Linda,Rebeka", "Belo", "Rozalia", "Regina", "Alica", "Marianna", "Miriama", "Martina1", "Oleg", "Bystrik", "Maria,Marlena", "Ctibor", "Ludomil", "Jolana", "Ludmila", "Olympia", "Eugenia", "Konstantin", "Luboslav,Luboslava", "Matus", "Moric", "Zdenka", "Lubos,Lubor", "Vladislav,Vladislava", "Edita", "Cyprian", "Vaclav", "Michal,Michaela", "Jarolim"},
    {"", "Arnold", "Levoslav", "Stela", "Frantisek", "Viera", "Natalia", "Eliska", "Brigita", "Dionyz1", "Slavomira", "Valentina", "Maximilian", "Koloman", "Boris", "Terezia", "Vladimira", "Hedviga", "Lukas", "Kristian", "Vendelin", "Ursula", "Sergej", "Alojzia", "Kvetoslava", "Aurel", "Demeter", "Sabina", "Dobromila", "Klara", "Simon,Simona", "Aurelia"},
    {"", "Denis,Denisa", "Hubert", "Karol", "Imrich", "Renata", "Rene", "Bohumir", "Teodor1", "Tibor", "Martin,Maros1", "Svatopluk", "Stanislav", "Irma", "Leopold", "Agnesa", "Klaudia", "Eugen", "Alzbeta", "Felix", "Elvira", "Cecilia", "Klement", "Emilia", "Katarina", "Kornel", "Milan", "Henrieta", "Vratko", "Ondrej,Andrej"},
    {"", "Edmund", "Bibiana", "Oldrich", "Barbora,Barbara", "Oto", "Mikulas", "Ambroz", "Marina", "Izabela1", "Raduz", "Hilda", "Otilia", "Lucia", "Branislava,Bronislava", "Ivica", "Albina", "Kornelia", "Slava", "Judita", "Dagmara", "Bohdan", "Adela", "Nadezda", "Adam,Eva", "Stefan", "Filomena", "Ivana,Ivona", "Milada", "David", "Silvester"}
};

static char* Days[] = {"", "Pondelok", "Utorok", "Streda", "Stvrtok", "Piatok", "Sobota", "Nedela"};
static unsigned int today = 1;

static char* Apartments[] = {"", "33", "34", "35", "36"};
static unsigned int apartmentIndex = 1;

int string_length(char s[]) {
   int c = 0;
   while (s[c] != '\0')
      c++;

   return c;
}

void setClock(UBYTE year, UBYTE month, UBYTE day, UBYTE hour, UBYTE minute, UBYTE second){
    year = year<<2;
    month = month<<4;
    day = day<<3;
    hour = hour<<3;
    minute = minute<<2;
    while(RTC_STATUS != 0){}
    RTC_CLOCK = 0;
    while(RTC_STATUS != 0){}
    UDOUBLE tmp = year<<24|month<<18|day<<14|hour<<9|minute<<4|second;
    while(RTC_STATUS != 0){}
    RTC_CLOCK = tmp;
    while(RTC_STATUS != 0){}
}

void increaseMinute(){
    while(RTC_STATUS != 0){}
    unsigned int datetime = RTC_CLOCK;
    while(RTC_STATUS != 0){}
    
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
    
    while(RTC_STATUS != 0){}
    UDOUBLE datetime = RTC_CLOCK;
    while(RTC_STATUS != 0){}
    
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

void waitForI2CSent(){
    while(!I2C_INTFLAG&0x1){
        //wait
    }
    I2C_INTFLAG = I2C_INTFLAG|0x1;
}
void waitForI2CRead(){
    while(!I2C_INTFLAG&0x2){
        //wait
    }
    I2C_INTFLAG = I2C_INTFLAG|0x2;
}

void waitForI2CIdle(){
    while(!I2C_STATUS&0x3 == 0x10){
        
    }
}

void writeI2C(char deviceAddr, char registerAddr, UBYTE *data, char length){
    char tmpDeviceAddr = deviceAddr<<1;
    int tmpAddr = 0x00000000;
    tmpAddr = tmpAddr|(length+1);
    tmpAddr = tmpAddr<<16;
    tmpAddr = tmpAddr|0x2000;
    tmpAddr = tmpAddr|tmpDeviceAddr;
    I2C_ADDR = tmpAddr; //Datasheet page 522, send 2 bytes to 0xF6 (address shifted left by one, last bit is read/write)
    waitForI2CSent();
    I2C_DATA = registerAddr; //Datasheet page 524, where to write to
    
    for(int i = 0; i < length; i++){
        waitForI2CSent();
        I2C_DATA = data[i];//What data to write
    }
    waitForI2CIdle();
}

void readI2C(char deviceAddr, char registerAddr, UBYTE *data, char length){
    char tmpDeviceAddr = deviceAddr<<1;
    int tmpAddr = 0x00000000;
    tmpAddr = tmpAddr|0x1;
    tmpAddr = tmpAddr<<16;
    tmpAddr = tmpAddr|0x2000;
    tmpAddr = tmpAddr|tmpDeviceAddr;
    I2C_ADDR = tmpAddr; //Datasheet page 522, send 2 bytes to 0xF6 (address shifted left by one, last bit is read/write)
    waitForI2CSent();
    I2C_DATA = registerAddr; //Datasheet page 524, where to write to
    waitForI2CIdle();
    tmpAddr = 0x00000000;
    tmpAddr = tmpAddr|(length);
    tmpAddr = tmpAddr<<16;
    tmpAddr = tmpAddr|0x2000;
    tmpAddr = tmpAddr|tmpDeviceAddr;
    tmpAddr = tmpAddr|0x1;
    I2C_ADDR = tmpAddr;
    
    for(int i = 0; i < length; i++){
        waitForI2CRead();
        data[i] = I2C_DATA;
        I2C_CTRLB = I2C_CTRLB|0x00020000; //Datasheet page 513, reset flags
    }
    
    //I2C_CTRLB = I2C_CTRLB|0x00070000; //Datasheet page 513, reset flags
}

int getMonth(){
    while(RTC_STATUS != 0){}
    UDOUBLE datetime = RTC_CLOCK;
    while(RTC_STATUS != 0){}

    unsigned int month = (datetime >> 22) & 0x0000000F;
    
    return month;
}

int getDay(){
    while(RTC_STATUS != 0){}
    UDOUBLE datetime = RTC_CLOCK;
    while(RTC_STATUS != 0){}

    unsigned int day = (datetime >> 17) & 0x0000001F;
    
    return day;
}

int getMinute(){
    while(RTC_STATUS != 0){}
    UDOUBLE datetime = RTC_CLOCK;
    while(RTC_STATUS != 0){}

    unsigned int minute = (datetime >> 6) & 0x0000003F;
    
    return minute;
}

void main(){
    //ADD DCF77
    
    GROUP1DIR = GROUP1DIR|LEDPIN; //SET LED PIN AS OUTPUT
    //GROUP1OUT = GROUP1OUT|LEDPIN; //SET LED HIGH
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
    GENDIV = 0x00002004;//divide 32.768khz by 32 = 1024
    GENCTRL = 0x00290504; //datasheet page 31 & 126 Connect GENCLK04 to XOSC32K, Send it to GCLK_IO[4] and enable it
    
    
    //-----------------------------------------------------------------------------------------------------------------------------------------------
    //FREQCORR = 0x1C;
    
    //Configure RTC
    CLKCTRL = 0x4404; //Datasheet page 123, Connect GENCLK4 to RTC
    DBGCTRL = DBGCTRL|DBGRUN; //Keep running even when debug is stopped
    RTC_CTRL = 0x0A0A; // Datasheet page 242, divide clock by 1024 to get 1Hz, set the MODE 2 (calendar) and enable RTC
    //read CLOCK register to get date & time // Datasheet page 262
    
    UBYTE TimeAndDate[15];
    readClock(TimeAndDate);
    setClock(21,2,2,19,58,0);
    readClock(TimeAndDate);
    
    //Configure SPI SERCOM1
    GROUP0PMUX8 = GROUP0PMUX8|FUNCTION_C_LOW; //datasheet page 385, Set alternate function of PA16 as PAD[0]
    GROUP0PINCFG16 = GROUP0PINCFG16|PMUXEN; //datasheet page 387, Enable alternate function
    
    GROUP0PMUX8 = GROUP0PMUX8|FUNCTION_C_HIGH; //datasheet page 385, Set alternate function of PA17 as PAD[1]
    GROUP0PINCFG17 = GROUP0PINCFG17|PMUXEN; //datasheet page 387, Enable alternate function
    
    //DFLLCTRL = 0x02; //Enable 48MHz Clock
    GROUP0PMUX5 = GROUP0PMUX5|FUNCTION_H_HIGH; //datasheet page 385, Set alternate function of PA11 as PAD[3]
    GROUP0PINCFG11 = GROUP0PINCFG11|PMUXEN; //datasheet page 387, Enable alternate function   
    GENCTRL = 0x00090605; //datasheet page 31 & 126 Connect GENCLK05 to DFLL48M, Send it to GCLK_IO[5] and enable it
    CLKCTRL = 0x4515; //Datasheet page 123, Connect GENCLK5 to SERCOM1
    
    APBCMASK = APBCMASK|0x00000008; //Enables APBC clock for SERCOM1
    SPI_CTRLB = 0x0; //8 bit transfer page 465
    SPI_CTRLA = 0x0000000E; //Enable SPI master
    
        
    //Configure I2C
    APBCMASK = APBCMASK|0x00000004; //Enables APBC clock for SERCOM0
    
    GROUP0PMUX4 = GROUP0PMUX4|FUNCTION_C_LOW; //datasheet page 476, Set alternate function of PA8 as PAD[0] - SDA
    GROUP0PINCFG8 = GROUP0PINCFG8|PMUXEN;
    
    GROUP0PMUX4 = GROUP0PMUX4|FUNCTION_C_HIGH; //datasheet page 476, Set alternate function of PA9 as PAD[1] - SCL
    GROUP0PINCFG9 = GROUP0PINCFG9|PMUXEN;
    
    CLKCTRL = 0x4514; //Datasheet page 123, Connect GENCLK5 to SERCOM0
    CLKCTRL = 0x4513; //Datasheet page 123, Connect GENCLK5 to SERCOM_SLOW (should be connected to 32kHz, currently is not... Maybe isn't even necessary)
    
    I2C_CTRLA = 0x30000014; //Datasheet page 510, INACTOUT switches I2C to idle automatically, MODE 5 means master 
    I2C_BAUD = 0xFFFF; //Datasheet page 515, just sets it to something for now
    I2C_CTRLA = I2C_CTRLA|0x00000002; //Datasheet page 510, enables I2C
    //I2C_CTRLB = I2C_CTRLB|0x100;
    //Write I2C
    //I2C_ADDR = 0x000220DE; //Datasheet page 522, send 2 bytes to 0xF6 (address shifted left by one, last bit is read/write)
    //I2C_DATA = 0x0022; //Datasheet page 524, where to write to
    //I2C_DATA = 0x00AA;//What data to write
    
    UBYTE data[] = {0x00aa, 0x00bb, 0x00cc, 0x00dd};
    writeI2C(0x6F, 0x20, data, 4);
    
    UBYTE dataRead[4];
    readI2C(0x6F, 0x20, dataRead, 4);
    
    //Read I2C
    //I2C_ADDR = 0x000120DE; //Datasheet page 522, send 1 byte to 0xF6 (address shifted left by one, last bit is read/write)
    //I2C_DATA = 0x0021; //Sets where to read from
    //I2C_ADDR = 0x000120DF;//Datasheet page 522, read 1 byte from 0xF6 (address shifted left by one, last bit is read/write)
    
    //short tmpdata = I2C_DATA;
    
    //I2C_CTRLB = I2C_CTRLB|0x00070000; //Datasheet page 513, reset flags
    //I2C_DATA = 0x0020;
    
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
    char tmp[] = "Init...";
    
    Paint_DrawString_EN(10, 20, tmp, &Font24, WHITE, BLACK);
    EPD_2IN7_Display(BlackImage);
    //EPD_2IN7_Sleep();
    
    //Set RTC interrupt 
    RTC_MASK = 0x01; //Compare only seconds
    RTC_ALARM = 0x0; //When seconds are 0 (at start of every minute)
    RTC_INTENSET = 0x01; //Enables interrupt coming from RTC peripheral

    NVIC_ISER = 0x8; //Enable RTC interrupt in NVIC page 49 table 11-3, numbers are bit in register (RTC NVIC line 3 = 4th bit)
    
    SCR = SCR|SLEEPDEEP; //Not sure, but probably sets sleep mode to standby (deep sleep); https://developer.arm.com/documentation/dui0497/a/cortex-m0-peripherals/system-control-block/system-control-register
    
    __WFI(); //Go into deep sleep, wait for interrupt
    
    //delay(10);
    //clock();
    
    unsigned int i;
    while(1){
        //clock();
        EPD_2IN7_Wake();
        Paint_Clear(WHITE);
        readClock(TimeAndDate);
        //if(getMinute() == 14){
            if(today < 7){
                today++;
            }else{
                today = 1;
            }
        //}
        
        if(apartmentIndex < 4){
            apartmentIndex++;
        }else{
            apartmentIndex = 1;
        }
        
        unsigned int xPos = 0;
        xPos = 132-(string_length(Apartments[apartmentIndex])*0.5)*72;
        Paint_DrawString_EN(xPos, 0, Apartments[apartmentIndex], &FontTmp, WHITE, BLACK);
                
        char dayAndDate[80] = {};
        strcpy(dayAndDate, Days[today]);
        strcat(dayAndDate, " ");
        strcat(dayAndDate, TimeAndDate);
        
        xPos = 132-(string_length(dayAndDate)*0.5)*11;
        Paint_DrawString_EN(xPos, 146, dayAndDate, &Font16, WHITE, BLACK);
        
        unsigned int monthc = getMonth();
        unsigned int dayc = getDay();
        xPos = 132-(string_length(Meniny[monthc][dayc])*0.5)*11;
        Paint_DrawString_EN(xPos, 160, Meniny[monthc][dayc], &Font16, WHITE, BLACK);
        EPD_2IN7_Display(BlackImage);
        EPD_2IN7_Sleep();
       __WFI();
        
        UBYTE button1pressed;
        /*for(i = 0; i < 50; i++){
            delay(500);
            DEV_Digital_Write(EPD_LED_PIN, 1);
            delay(500);
         */
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
           
        /*  DEV_Digital_Write(EPD_LED_PIN, 0);  
           
            if(RTC_INTFLAG&0x01){
                delay(10);
                RTC_INTFLAG = RTC_INTFLAG|0x01;
            }
        }*/
    
    }
    DEV_Module_Exit();
}

void RTC_Handler(void){
    delay(10);
    RTC_INTFLAG = RTC_INTFLAG|0x01;
    NVIC_ICPR = 0x08;
}

/* *****************************************************************************
 End of File
 */
