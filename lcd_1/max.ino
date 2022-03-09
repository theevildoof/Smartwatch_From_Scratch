void max_menu(){
  tft.fillScreen(0xF800);
  tft.setTextSize(2);
  tft.setCursor(0, 10);
  // Display static text
  tft.println("MAX");

  while(1){
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  
  if (buttonState1 == HIGH){
    delay(1000);
    mpu_menu();
  }
  else if(buttonState2 == HIGH) {
  delay(1000);
  wifi_menu();
  }
  else if (buttonState3 == HIGH) {
   
  max_loop();
  }
  else if (buttonState4 == HIGH) {
    delay(1000);
  main_menu();
  }
  }
  
}

void max_setup(){
  if (particleSensor.begin(Wire1) == false)
  {
    Serial.println("MAX30105 was not found. Please check wiring/power. ");
    while (1);
  }

  particleSensor.setup(); //Configure sensor. Use 6.4mA for LED drive
}

void max_loop(){

  float red, ir, green;
  while(1){
    buttonState4 = digitalRead(buttonPin4);
    if (buttonState4 == HIGH){
      delay(1000);
      max_menu();
      }
   red = particleSensor.getRed();
   ir = particleSensor.getIR();
   green = particleSensor.getGreen();
 
  tft.fillScreen(0xF800);
  tft.setTextSize(1);
  tft.setCursor(0, 10);
  tft.print("Red:");
  tft.println(red);
  tft.print("IR:");
  tft.println(ir);
  tft.print("Green:");
  tft.println(green);
 
  }
}
