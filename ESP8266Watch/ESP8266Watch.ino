/*
   ESP8266Watch
   - Connection -
   DS1302:
   CLK => GPIO 14 (D5)
   DAT => GPIO 12 (D6)
   RST => GPIO 13 (D7)

   SSD1306 0.96'' OLED:
   SDA => GPIO 4 (D2)
   SCL => GPIO 5 (D1)

   Potentiometer:
   Connect the two ends to VCC and GND, and the pin in the middle to ADC0 (A0).

   Touch button:
   SIG => GPIO 15 (D8)
*/

// Include necessary libraries.
#include <DS1302.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <OneButton.h>

// You can change the pins here.
// The porentiometer pin:
#define POTPIN A0
// The button pin:
#define BTNPIN 15
// DS1302 CLK, DAT and RST pins:
#define CLK 14
#define DAT 12
#define RST 13

#define countof(a) (sizeof(a) / sizeof(a[0]))

// Initialize variables.
bool buttonClicked = false;
bool buttonDoubleClicked = false;
bool buttonLongPressed = false;

// Create device objects.
DS1302 rtc(RST, DAT, CLK);
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
OneButton btn(BTNPIN, false);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Boot complete. Configuring RTC module...");
  Serial.println();
  rtc.writeProtect(false);
  rtc.halt(false);
  // Uncomment the two lines below to set the clock.
  //  Time t(2021, 7, 23, 22, 25, 50, Time::kFriday);
  //  rtc.time(t);

  Serial.println("RTC configuration completed. Configuring screen...");
  u8g2.begin();
  //  u8g2.enableUTF8Print();
  
  Serial.println("Screen configuration completed. Configuring button...");
  btn.attachClick(clicked);
  btn.attachDoubleClick(doubleClicked);
  btn.attachLongPressStop(longPressed);
  Serial.println("Button configuration completed. Moving to the loop...");
}

void loop() {
  // put your main code here, to run repeatedly:
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(0, 28, "RTC Test");
    String menuTxt[3] = {"Something"};
    int menuResult = showMenu("Test", menuTxt);
    Serial.println(menuTxt[menuResult]);
  } while (u8g2.nextPage());
}
