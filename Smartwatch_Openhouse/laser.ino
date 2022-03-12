
void laser_setup(){
  pinMode(14, INPUT);
  pinMode(12, OUTPUT);
  Serial.println("LASER SETUP COMPLETE");
}

void laser_loop(){
   //okay
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
    laser_menu();
    
    }  
  tft.fillScreen(0x0000);
  tft.setTextSize(3);
  tft.setCursor(20 , tft.height()/2 - 10);
  // Display static text
  tft.println("LASER");
  delay(40);
  if(digitalRead(14) == HIGH){
    digitalWrite(12,HIGH);
  }
  else{
    digitalWrite(12,LOW);
  }
   }
}

void laser_menu(){
  while(1){
    leftState = digitalRead(left);
    rightState = digitalRead(right);
    selectState = digitalRead(select);
    backState = digitalRead(back);

    if (leftState == HIGH){
    delay(500);
    Serial.print("LEFT");
    green_led();
    steps_menu();
    
    }
    else if(rightState == HIGH) {
    delay(500);
    Serial.print("right");
    green_led();
    ping_pong_menu();
    }
    else if (selectState == HIGH) {
    delay(500);
    Serial.print("select");
    green_led();
    laser_loop();
    
    }
    else if (backState == HIGH) {
    delay(500);
    Serial.print("back");
    green_led();
    main_menu1();
    
    }  
  tft.fillScreen(0x0000);
  tft.setTextSize(4);
  tft.setCursor(5 , tft.height()/2 - 20);
  // Display static text
  tft.println("LASER");
  delay(40);
  }
}
