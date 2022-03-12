void max_spo2_menu(){

  while(1){
    leftState = digitalRead(left);
    rightState = digitalRead(right);
    selectState = digitalRead(select);
    backState = digitalRead(back);

    if (leftState == HIGH){
    delay(500);
    Serial.print("LEFT");
    green_led();
    bmp_menu();
    
    }
    else if(rightState == HIGH) {
    delay(500);
    Serial.print("right");
    green_led();
    max_heartrate_menu();
    }
    else if (selectState == HIGH) {
    delay(500);
    Serial.print("select");
    green_led();
    max_spo2_loop();
    
    }
    else if (backState == HIGH) {
    delay(500);
    Serial.print("back");
    green_led();
    main_menu1();
    
    }  
  //okay
  tft.fillScreen(0x0000);
  tft.setTextSize(4);
  tft.setCursor(15 , tft.height()/2 - 20 );
  tft.println("SPO2");
  delay(40);
  }
  
}

void max_spo2_loop(){
  
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
    max_spo2_menu();
    
    }  
  tft.fillScreen(0x0000);
  tft.setTextSize(3);
  tft.setCursor(0 , tft.height()/2 - 20);
  tft.println("No data");
  }
  
}
