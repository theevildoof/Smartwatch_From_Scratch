#define BUZZER_PIN 16 // ESP32 GIOP21 pin connected to Buzzer's pin

void buzzer_setup() {
  ledcAttachPin(BUZZER_PIN, 1);
  ledcSetup(1, 200, 8);
}
  

void buzzer_red(){
  ledcWrite(1, 50);
  delay(500);
  ledcWrite(1, 0);
  delay(100);
  ledcWrite(1, 50);
  delay(500);
  ledcWrite(1, 0);
  delay(100);
}

  
