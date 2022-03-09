void ble_menu(){
  tft.fillScreen(0xF800);
  tft.setTextSize(2);
  tft.setTextColor(0xFFE0);
  tft.setCursor(0, 10);
  // Display static text
  tft.println("BLE");

  while(1){
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  
  if (buttonState1 == HIGH){
    delay(1000);
    wifi_menu();
  }
  else if(buttonState2 == HIGH) {
    delay(1000);
  rtc_menu();
  }
  else if (buttonState3 == HIGH) {
   
  ble_loop();
  }
  else if (buttonState4 == HIGH) {
    delay(1000);
  main_menu();
  }
  }
}

void ble_loop(){

  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  tft.fillScreen(0xF800);
  tft.setTextColor(0xFFE0);
  tft.setTextSize(1);
  tft.setCursor(0, 10);
  tft.println("BLE is on");
  //display.println();
  delay(2000);
  tft.fillScreen(0xF800);
  tft.setCursor(0, 10);
  
  while(1){
    buttonState4 = digitalRead(buttonPin4);
    if (buttonState4 == HIGH){
      delay(1000);
      ble_menu();
      }
  if (SerialBT.available()) {
  
  tft.print(char(SerialBT.read()));
  //display.println();
  }
  delay(20);
  }
  
}
