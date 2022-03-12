void steps_menu(){
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
    max_heartrate_menu();
    
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
    steps_loop();
    
    }
    else if (backState == HIGH) {
    delay(500);
    Serial.print("back");
    green_led();
    main_menu1();
    
    }  
  tft.fillScreen(0x0000);
  tft.setTextSize(3);
  tft.setCursor(20 , tft.height()/2 - 20);
  tft.println("Steps");
  tft.setCursor(2 , tft.height()/2+ 5);
  tft.println("Counter");
  delay(40);
    }
}

void steps_loop(){
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
    steps_menu();
    
    }  

  float accelX , accelY , accelZ ;
  float gx, gy, gz;
  bool bStepFlag;
  float temp1;
  int steps;
   sensors_event_t a, g, temp;

   mpu.getEvent(&a, &g, &temp);
    accelX = a.acceleration.x;
    accelY = a.acceleration.y;
    accelZ = a.acceleration.z;
  
 
    if( accelY < 1 )
        bStepFlag = true;
    else if( bStepFlag == true && accelY > 3 )
    {
        bStepFlag = false;
        steps++;
        Serial.print("Steps: ");
        Serial. print(steps);
        Serial.print("\n");
    }
    
  tft.fillScreen(0x0000);
  tft.setTextSize(3);
  tft.setCursor(0 , tft.height()/2 - 20);
  tft.println(steps);
  }
}
