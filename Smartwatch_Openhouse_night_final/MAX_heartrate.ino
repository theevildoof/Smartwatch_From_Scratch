void max_heartrate_menu(){

  while(1){
    leftState = digitalRead(left);
    rightState = digitalRead(right);
    selectState = digitalRead(select);
    backState = digitalRead(back);

    if (leftState == HIGH){
    delay(500);
    Serial.print("LEFT");
    green_led();
    max_spo2_menu();
    
    }
    else if(rightState == HIGH) {
    delay(500);
    Serial.print("right");
    green_led();
    steps_menu();
    }
    else if (selectState == HIGH) {
    delay(500);
    Serial.print("select");
    green_led();
    max_heartrate_loop();
    
    }
    else if (backState == HIGH) {
    delay(500);
    Serial.print("back");
    green_led();
    main_menu1();
    
    }  
  //okay
  tft.fillScreen(0x0000);
  tft.setTextSize(3);
  tft.setCursor(20 , tft.height()/2 - 20);
  tft.println("Heart");
  tft.setCursor(30 , tft.height()/2+ 5);
  tft.println("Rate");
  delay(40);
  }
}

void max_heartrate_loop(){
  uint32_t irBuffer[100]; //infrared LED sensor data
  uint32_t redBuffer[100];

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
    max_heartrate_menu();
    
    }

  const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred

float beatsPerMinute;
int beatAvg;

long irValue = particleSensor.getIR();

  if (checkForBeat(irValue) == true)
  {
    //We sensed a beat!
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute >100  && beatsPerMinute < 55)
    {
      rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE; //Wrap variable

      //Take average of readings
      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
  }

  tft.fillScreen(0x0000);
  tft.setTextSize(3);
  tft.setCursor(0 , tft.height()/2 - 20);
  
  if (irValue < 50000)
  {
    tft.setTextSize(2);
    tft.println("No finger?");
  }
  else
    tft.println(int(beatsPerMinute*50));
  
  
 
  }
}
