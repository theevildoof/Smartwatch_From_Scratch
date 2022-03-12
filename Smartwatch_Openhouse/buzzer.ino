
  int freq = 2000;
  int channel = 0;
  int resolution = 8;
 // need to solve this
  
void buzzer_setup(){
  pinMode(17, OUTPUT);
  ledcSetup(3, 8000, 12);
  ledcAttachPin(17, 3);
  Serial.println("BUZZER SETUP COMPLETE");
}

void buzzer_green(){
   ledcWriteTone(3, 500);
   Serial.println("BUZZER GREEN");
   delay(1000);
}

void buzzer_red(){
  ledcWriteTone(3, 500);
}

  
