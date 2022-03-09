void bmp_loop(){
  float t,p,a;
  while(1){
    buttonState4 = digitalRead(buttonPin4);
    if (buttonState4 == HIGH){
      delay(1000);
      bmp_menu();
      }
   t = bmp.readTemperature();
   p = bmp.readPressure();
   a = bmp.readAltitude(1013.25);
   
  tft.fillScreen(0xF800);
  tft.setTextSize(1);
  tft.setCursor(0, 10);
  tft.print("Temp:");
  tft.println(t);
  tft.print("Pressure:");
  tft.println(p);
  tft.print("Altitude:");
  tft.println(a);
  }
}

void bmp_setup(){
  unsigned status;
  status = bmp.begin(0x76);
  if (!status) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    Serial.print("SensorID was: 0x"); Serial.println(bmp.sensorID(),16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    while (1) delay(10);
  }

    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500);
   Serial.println("BMP setup done");
}

void bmp_menu(){
  tft.fillScreen(0xF800);
  tft.setTextSize(2);
  tft.setCursor(0, 10);
  // Display static text
  tft.println("BMP");

  while(1){
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  
  if (buttonState2 == HIGH) {
  delay(1000);
  mpu_menu();
  }
  else if (buttonState3 == HIGH) {
   delay(1000);
  bmp_loop();

  }
  else if (buttonState4 == HIGH) {
    delay(1000);
  main_menu();
  }
  
  }
}
