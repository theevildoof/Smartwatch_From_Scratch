void max_menu(){
   while(1){
    leftState = digitalRead(left);
    rightState = digitalRead(right);
    selectState = digitalRead(select);
    backState = digitalRead(back);

    if (leftState == HIGH){
    delay(500);
    Serial.print("LEFT");
    green_led();
    rtc_menu();
    
    }
    else if(rightState == HIGH) {
    delay(500);
    Serial.print("right");
    green_led();
    mpu_menu();
    }
    else if (selectState == HIGH) {
    delay(500);
    Serial.print("select");
    green_led();
    max_loop();
    
    }
    else if (backState == HIGH) {
    delay(500);
    Serial.print("back");
    green_led();
    main_menu1();
    
    }  
  //okay
  tft.fillScreen(0x0000);
  tft.setTextSize(6);
  tft.setCursor(15 , tft.height()/2 - 20);
  // Display static text
  tft.println("MAX");
  delay(40);
   }
}

void max_setup(){
  //okay
  if (particleSensor.begin(Wire1) == false)
  {
    Serial.println("MAX30105 was not found. Please check wiring/power. ");
    while (1);
  }

  particleSensor.setup(); //Configure sensor. Use 6.4mA for LED drive
}

void max_loop(){
  //okay
  float red, ir, green;
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
    max_menu();
    
    }  
   red = particleSensor.getRed();
   ir = particleSensor.getIR();
   green = particleSensor.getGreen();
   tft.fillScreen(0x0000);
  tft.setTextSize(1);
  tft.setCursor(30, tft.height()/2 - 10);
  tft.print("Red:");
  tft.println(red);
  tft.setCursor(30, tft.height()/2 );
  tft.print("IR:");
  tft.println(ir);
  tft.setCursor(30, tft.height()/2 + 10);
  tft.print("Green:");
  tft.println(green);
  delay(100);
  }
}
