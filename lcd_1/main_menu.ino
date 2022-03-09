void main_menu(){
  tft.fillScreen(0xF800);
  tft.setTextSize(2);
  tft.setCursor(0, 10);
  // Display static text
  tft.println("Main Menu");

  while(1){
  buttonState3 = digitalRead(buttonPin3);
    if (buttonState3 == HIGH) {
    delay(1000);
    bmp_menu();
    }
  }
  
}
