

void bmp_setup(){
  //okay
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


void bmp_loop(){
  //okay
  float t,p,a;
  

    while(1){
       t = bmp.readTemperature();
       p = bmp.readPressure();
     a = bmp.readAltitude(1013.25);
    leftState = digitalRead(left);
    rightState = digitalRead(right);
    selectState = digitalRead(select);
    backState = digitalRead(back);

    if (leftState == HIGH){
    delay(500);
    Serial.print("LEFT");
    red_led();
    
    }
    else if(rightState == HIGH) {
    delay(500);
    Serial.print("right");
    red_led();
    }
    else if (selectState == HIGH) {
    delay(500);
    Serial.print("select");
    red_led();
    
    }
    else if (backState == HIGH) {
    delay(500);
    Serial.print("back");
    green_led();
    bmp_menu();
    
    }  
  //
  tft.fillScreen(0x0000);
  delay(10);
  tft.setTextSize(1);
  tft.setCursor(30, tft.height()/2 - 10);
  tft.print("Temp:");
  tft.println(t);
  tft.setCursor(10,tft.height()/2 );
  tft.print("Pressure:");
  tft.println(p);
  tft.setCursor(20,tft.height()/2 + 10 );
  tft.print("Altitude:");
  tft.println(a);
  delay(10);
    }
}


void bmp_menu(){
  //okay
  while(1){
    leftState = digitalRead(left);
    rightState = digitalRead(right);
    selectState = digitalRead(select);
    backState = digitalRead(back);

    if (leftState == HIGH){
    delay(500);
    Serial.print("LEFT");
    green_led();
    main_menu1();
    
    }
    else if(rightState == HIGH) {
    delay(500);
    green_led();
    Serial.print("right");
    max_spo2_menu();
    }
    else if (selectState == HIGH) {
    delay(500);
    Serial.print("select");
    green_led();
    bmp_loop();
    
    }
    else if (backState == HIGH) {
    delay(500);
    Serial.print("back");
    green_led();
    main_menu1();
    
    }  
  tft.fillScreen(0x0000);
  tft.setTextSize(6);
  tft.setCursor(15 , tft.height()/2 - 20);
  // Display static text
  tft.println("BMP");
  delay(40);
  }
}
