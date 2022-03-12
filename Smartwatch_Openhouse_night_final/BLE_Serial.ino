#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void ble_menu(){
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
    wifi_menu();
    
    }
    else if(rightState == HIGH) {
    delay(500);
    Serial.print("right");
    green_led();
    ota_menu();
    }
    else if (selectState == HIGH) {
    delay(500);
    Serial.print("select");
    green_led();
    ble_loop();
    
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
  tft.println("BLE");
  delay(40);
  }
}

void ble_loop(){
  //okay
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  tft.fillScreen(0xF000);
  tft.setTextColor(0xFFE0);
  tft.setTextSize(1);
  tft.setCursor(0, 10);
  tft.println("BLE is on");
  //display.println();
  delay(2000);
  tft.fillScreen(0xF0000);
  tft.setCursor(0, 10);
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
    ble_menu();
    
    }  
    if (SerialBT.available()) {
    tft.print(char(SerialBT.read()));
    }
}
  
}
