
void button_setup(){
   pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(select, INPUT);
  pinMode(back, INPUT);
  Serial.println("BUTTON SETUP COMPLETE");
}

void button_test(){
   while(1){
    leftState = digitalRead(left);
    rightState = digitalRead(right);
    selectState = digitalRead(select);
    backState = digitalRead(back);

    if (leftState == HIGH){
    Serial.print("LEFT");
    red_led();
    }
    else if(rightState == HIGH) {
    Serial.print("right");
    red_led();
    }
    else if (selectState == HIGH) {
    Serial.print("select");
    }
    else if (backState == HIGH){
      Serial.print("back");
    }
    else{
      
    }
    
   }
}
