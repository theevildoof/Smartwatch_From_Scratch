void rtc_menu(){
  tft.fillScreen(0xF800);
  tft.setTextSize(2);
  tft.setCursor(0, 10);
  // Display static text
  tft.println("RTC");

  while(1){
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  
  if (buttonState1 == HIGH){
     delay(1000);
    ble_menu();
  }
  else if (buttonState3 == HIGH) {
   
  rtc_loop();
  }
  else if (buttonState4 == HIGH) {
    delay(1000);
  main_menu();
  }

  }
}

void rtc_loop(){

  #ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
    }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(2022,1,28,7,43,0));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  tft.fillScreen(0xF800);
  while(1){
    buttonState4 = digitalRead(buttonPin4);
    if (buttonState4 == HIGH){
      delay(1000);
      rtc_menu();
      }
    DateTime now = rtc.now();

    tft.fillScreen(0xF800);
    tft.setTextSize(2);
    tft.setCursor(0, 10);
    tft.print(now.year(), DEC);
    tft.print('/');
    tft.print(now.month(), DEC);
    tft.print('/');
    tft.println(now.day(), DEC);
    tft.print("(");
    tft.print(daysOfTheWeek[now.dayOfTheWeek()]);
    tft.print(")");
    tft.print(now.hour(), DEC);
    tft.print(':');
    tft.print(now.minute(), DEC);
    tft.print(':');
    tft.print(now.second(), DEC);
    tft.println();
  }
  
}
