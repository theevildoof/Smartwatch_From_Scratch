 #include <Wire.h>
//oled
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
//RTC
//#include<DS3231.h>
//BMP280
#include <Adafruit_BMP280.h>
//MPU6050
#include <Adafruit_MPU6050.h>
//#include <Adafruit_Sensor.h>
//max
#include "MAX30105.h"
//wifi
#include <WiFi.h>
//ble
#include "BluetoothSerial.h"
//rtc
#include "RTClib.h"


RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

// Replace with your network credentials
const char* ssid = "Hello";
const char* password = "123456789";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output26State = "off";

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

//MAX variables
MAX30105 particleSensor;
//MPU variables
Adafruit_MPU6050 mpu;
//bmp
Adafruit_BMP280 bmp(&Wire1);
//tft
#define TFT_CS        5
#define TFT_RST        4 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         2
  
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);


const int buttonPin1 = 32;
const int buttonPin2 = 33;
const int buttonPin3 = 34;
const int buttonPin4 = 35;

int buttonState1 = 0; 
int buttonState2 = 0; 
int buttonState3 = 0; 
int buttonState4 = 0; 



void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);

  Wire1.begin(27,26, 100000);
  
  Serial.begin(115200);
  tft_setup();
  Serial.print("Oled setup done");
  bmp_setup();
  Serial.print("Oled setup done");
  mpu_setup();
  Serial.print("Oled setup done");
  max_setup();

  
  main_menu();

}

void loop() {
}
