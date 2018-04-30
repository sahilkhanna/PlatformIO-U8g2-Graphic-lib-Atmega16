#include <Arduino.h>
#include <U8g2lib.h>

#include <SPI.h>
#include "../img/logo.h"
int led = 14;
U8G2_UC1701_EA_DOGS102_1_4W_HW_SPI u8g2(U8G2_R1, /* cs=*/ 2, /* dc=*/ 1, /* reset=*/ 4);
#define MAX_COUNT_VAL 100000

uint8_t current_selection = 1;
uint16_t count = 0;
static char count_s[10]={};
void setup(void) {
    pinMode(led,OUTPUT);
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(100);
    u8g2.begin(/*Select=*/ 7, /*Right/Next=*/ 17, /*Left/Prev=*/ 22, /*Up=*/ 23, /*Down=*/ 16, /*Home/Cancel=*/ 12); // 

    u8g2.setFont(u8g2_font_6x12_tr);
    u8g2.setPowerSave(0);
    u8g2.setDrawColor(1);
    u8g2.setBitmapMode(0);
    u8g2.clear();
    sprintf(count_s, "%d", count);
}


bool led_state = HIGH;
void loop(void) {
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawXBMP(-2,10,cbysm_se6xd_width, cbysm_se6xd_height, cbysm_se6xd_bits);
    u8g2.setFont(u8g2_font_7x14B_tf );
    u8g2.drawStr(12,75,"DIGITAL");
    u8g2.drawStr(15,86,"SLAVE");
    u8g2.drawStr(10,98,count_s);
  } while ( u8g2.nextPage() );
  //delay(1000);
  count++;
  count = count>100000 ? 0:count;
  sprintf(count_s, "%d", count);
  
  digitalWrite(led,led_state);
  led_state=!led_state;
}


