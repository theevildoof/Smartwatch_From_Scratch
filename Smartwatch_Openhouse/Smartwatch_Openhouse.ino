#include <Wire.h>
//oled
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
//RTC
//#include<DS3231.h>
//BMP280
#include <Adafruit_BMP280.h>
//MPU6050
#include <Adafruit_MPU6050.h>
//max
#include "MAX30105.h"
//wifi
#include <WiFi.h>
//ble
#include "BluetoothSerial.h"
//rtc
#include "RTClib.h"
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//bmp
Adafruit_BMP280 bmp(&Wire1);
//MPU variables
Adafruit_MPU6050 mpu;
RTC_DS3231 rtc;
//MAX variables
MAX30105 particleSensor;

//tft
#define TFT_CS        5
#define TFT_RST        4 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         2
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);


//oled
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define left 32
#define right 33
#define select 34
#define back 35

int leftState = 0; 
int rightState = 0; 
int selectState = 0; 
int backState = 0; 

void setup() {
  Serial.begin(115200);
  Wire1.begin(27,26, 100000);
  ota_setup();
   LCD_setup();
  button_setup();
  bmp_setup();
  max_setup();
  mpu_setup();
  laser_setup();
  buzzer_setup();
  led_setup();

}

void loop() {
  main_menu1();
}
