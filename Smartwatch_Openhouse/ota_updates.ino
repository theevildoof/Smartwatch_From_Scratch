void ota_menu(){

    while(1){
    leftState = digitalRead(left);
    rightState = digitalRead(right);
    selectState = digitalRead(select);
    backState = digitalRead(back);

    if (leftState == HIGH){
    delay(500);
    Serial.print("LEFT");
    green_led();
    ble_menu();
    
    }
    else if(rightState == HIGH) {
    delay(500);
    Serial.print("right");
    green_led();
    notifs_menu();
    }
    else if (selectState == HIGH) {
    delay(500);
    Serial.print("select");
    green_led();
    ota_loop();
    
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
  tft.println("OTA");
  delay(40);
    
  }
  
}

void ota_setup(){
  
}

void ota_loop(){
  while(1){
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
    ota_menu();
    
    }  
  tft.fillScreen(0x0000);
  tft.setTextSize(3);
  tft.setCursor(20 , tft.height()/2 - 20);
  tft.println("No data");
  }
}
