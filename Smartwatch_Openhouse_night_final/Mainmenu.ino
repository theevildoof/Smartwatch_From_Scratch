void main_menu1() {
    if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
    }

  while(1){
    leftState = digitalRead(left);
    rightState = digitalRead(right);
    selectState = digitalRead(select);
    backState = digitalRead(back);

    if (leftState == HIGH){
    delay(500);
    Serial.print("LEFT");
    green_led();
    notifs_menu();
    
    }
    else if(rightState == HIGH) {
    delay(500);
    Serial.print("right");
    green_led();
    bmp_menu();
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
    red_led();
     buzzer_red();
    }  
    ArduinoOTA.handle();
  DateTime now = rtc.now();
  tft.setCursor(0, 0);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(10);
  tft.println(now.hour(), DEC);
  tft.setTextColor(ST77XX_YELLOW);
  tft.setTextSize(10);
  tft.println(now.minute(), DEC);
  ArduinoOTA.handle();
  delay(100);
  ArduinoOTA.handle();
    
  }
  
}
