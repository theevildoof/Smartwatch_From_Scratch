void rtc_menu(){
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
    ping_pong_menu();
    
    }
    else if(rightState == HIGH) {
    delay(500);
    Serial.print("right");
    green_led();
    max_menu();
    }
    else if (selectState == HIGH) {
    delay(500);
    Serial.print("select");
    green_led();
    rtc_loop();
    
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
  tft.println("RTC");
  delay(40);
   }
}

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


void rtc_loop(){
  //okay
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
  while(1){
    leftState = digitalRead(left);
    rightState = digitalRead(right);
    selectState = digitalRead(select);
    backState = digitalRead(back);

    if (leftState == HIGH){
    delay(500);
    Serial.print("LEFT");
    red_led();
    buzzer_red();
    }
    else if(rightState == HIGH) {
    delay(500);
    Serial.print("right");
    red_led();
    buzzer_red();
    }
    else if (selectState == HIGH) {
    delay(500);
    Serial.print("select");
    red_led();
    buzzer_red();
    
    }
    else if (backState == HIGH) {
    delay(500);
    Serial.print("back");
    green_led();
    rtc_menu();
    
    }  
    DateTime now = rtc.now();

    tft.fillScreen(0x0000);
    tft.setTextSize(2);
    tft.setCursor(15, tft.height()/2-20);
    tft.print(now.year(), DEC);
    tft.print('/');
    tft.print(now.month(), DEC);
    tft.print('/');
    tft.println(now.day(), DEC);
    tft.setCursor(25, tft.height()/2 );
    tft.println(daysOfTheWeek[now.dayOfTheWeek()]);
    tft.setCursor(15, tft.height()/2 + 20);
    tft.print(now.hour(), DEC);
    tft.print(':');
    tft.print(now.minute(), DEC);
    tft.print(':');
    tft.print(now.second(), DEC);
    tft.println();
    delay(100);  
  }
}
