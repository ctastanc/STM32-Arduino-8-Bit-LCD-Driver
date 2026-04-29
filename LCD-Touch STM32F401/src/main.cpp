/***********************************************************************************
*This program is a demo of how to use the touch function in a phone GUI
*This demo was made for LCD modules with 8bit data port.
* STM32 - LCD 8-bit parallel LCD + TouchScreen
* Hardware Environment: STM32 Arduino STM32F401
* Build Environment   : STM32Arduino
*
*=========================== pin usage as follow: ================================
*                  LCD_CS  LCD_RS  LCD_WR  LCD_RD  LCD_RST  SD_SS  SD_DI  SD_DO  SD_SCK
*     STM32          B1      B0      PA8    PB14     PB15
*     Touch          YP      XM
*
*                  LCD_D0  LCD_D1  LCD_D2  LCD_D3  LCD_D4  LCD_D5  LCD_D6  LCD_D7
*     STM32          PA0     PA1     PA2     PA3     PA4     PA5     PA6     PA7
*     Touch           XP     YM
*=================================================================================
*
*----------------- Pins and ports are defined in mcu_regs.h ----------------
*
* NOTE: PB3 and PB4 are JTAG pins. They can be used freely in SWD mode (default).
**********************************************************************************/

#include <LCD_KBV.h> 
#include <sin_cos.h>
#include <phonecall.h>
#include <touchdemo.h>
#include <bench2.h>
#include <read_pixel.h>
#include <switch_test.h>
#include <colligate_test.h>
#include <Meter_Linear.h>
#include <meters.h>
#include <cube_demo.h>
#include <clock_analog.h>
#include <disp_scroll.h>

void full_screen_test() {
    uint32_t start = micros(); 
    lcd.Fill_Screen(BLUE); 
    uint32_t elapsed_us = micros() - start;
    Serial.println(String(elapsed_us)+ " us"); 
    digitalWrite(PC13, HIGH);
    lcd.Print((String)("MCU "+String(SystemCoreClock/1000000) + " MHz"),CENTER,55,3,YELLOW,BLUE,0);
    lcd.Print((String)(String(elapsed_us)+" us"),CENTER,130,4,YELLOW,BLUE,0);
    lcd.Print((String)("APB1 "+String(HAL_RCC_GetPCLK1Freq()/1000000) +" Mhz"),CENTER,205,3,YELLOW,BLACK,0);
    delay(1000);
    lcd.Fill_Screen(RED); 
    digitalWrite(PC13, LOW);
    lcd.Print((String)("MCU "+String(SystemCoreClock/1000000) + " MHz"),CENTER,55,3,YELLOW,BLUE,0);
    lcd.Print((String)(String(elapsed_us)+" us"),CENTER,130,4,YELLOW,BLUE,0);
    lcd.Print((String)("APB1 "+String(HAL_RCC_GetPCLK1Freq()/1000000) +" Mhz"),CENTER,205,3,YELLOW,BLACK,0);
    delay(1000);
}

void rotate_rect(void) { 
    lcd.Set_Rotation(LANDSCAPE);
    lcd.Fill_Screen(BLACK);
    for(int x=1;x<360;x++){
        lcd.Fill_Rotated_Rectangle(160,120,50,50,x,RED);
        delay(10);
        lcd.Rotated_Rectangle(160,120,50,50,x,BLACK);
        lcd.Rotated_Rectangle(160,120,51,51,x,BLACK);
        lcd.Rotated_Rectangle(160,120,52,52,x,BLACK);
        lcd.Rotated_Rectangle(160,120,53,53,x,BLACK);
        lcd.Rotated_Rectangle(160,120,54,54,x,BLACK);
    }
    for(int x=360;x>0;x--){
        lcd.Fill_Rotated_Rectangle(160,120,50,50,x,GREEN);
        delay(10);
        lcd.Rotated_Rectangle(160,120,50,50,x,BLACK);
        lcd.Rotated_Rectangle(160,120,51,51,x,BLACK);
        lcd.Rotated_Rectangle(160,120,52,52,x,BLACK);
        lcd.Rotated_Rectangle(160,120,53,53,x,BLACK);
        lcd.Rotated_Rectangle(160,120,54,54,x,BLACK);
    }
}

void setup(void) {
    //SystemClock_Config96();
    Serial.begin(115200);
    delay(150); 
    Serial.println("system running...");
    analogReadResolution(10); // STM32 ADC default 12-bit; touch 10-bit
    pinMode(PC13,OUTPUT);
    lcd.Init_LCD();
    lcd.Fill_Screen(BLACK);
}

void loop(void) { 
    rotate_rect();
    full_screen_test();
    fast_sin_cos();
    //touch_demo();
    //phonecall();
    //b2.bench2();
    //ml.Meter_Linear();
    //cl.clock_analog();
    //mt.meters();
    //ds.disp_scroll();
    //cb.cube_demo();
    //rp.read_pixel();
    //sw.switch_test();
    //colligate_test(); 
}