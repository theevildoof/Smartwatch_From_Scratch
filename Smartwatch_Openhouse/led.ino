void led_setup(){
  pinMode(15, OUTPUT);
  pinMode(19, OUTPUT);
}

void green_led(){
  digitalWrite(19, HIGH);
  delay(100);
  digitalWrite(19,LOW);
  delay(100);
}
void red_led(){
  digitalWrite(15, HIGH);
  delay(100);
  digitalWrite(15,LOW);
  delay(50);
}
