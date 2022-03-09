void mpu_menu(){
  tft.fillScreen(0xF800);
  tft.setTextSize(2);
  tft.setCursor(0, 10);
  // Display static text
  tft.println("MPU");

  while(1){
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  
  if (buttonState1 == HIGH){
    delay(1000);
    bmp_menu();
  }
  else if(buttonState2 == HIGH) {
  delay(1000);
  max_menu();
  }
  else if (buttonState3 == HIGH) {
   
  mpu_loop();
  }
  else if (buttonState4 == HIGH) {
    delay(1000);
  main_menu();
  }
  }
  
}

void mpu_setup(){
  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin(0x68, &Wire1)) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }

  Serial.println("");
  delay(100);
  
}

void mpu_loop(){
  

  float ax, ay, az;
  float gx, gy, gz;
  float temp1;

  while(1){
    buttonState4 = digitalRead(buttonPin4);
    if (buttonState4 == HIGH){
      delay(1000);
      mpu_menu();
      }
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
    ax = a.acceleration.x;
    ay = a.acceleration.y;
    az = a.acceleration.z;

    gx = g.gyro.x;
    gy = g.gyro.y;
    gz = g.gyro.z;
  
    temp1 = temp.temperature;

    tft.fillScreen(0xF800);
    tft.setTextSize(1);
    tft.setCursor(0, 0);

    tft.print("ax:");
    tft.println(ax);
    tft.print("ay:");
    tft.println(ay);
    tft.print("az:");
    tft.println(az);

    tft.print("gx:");
    tft.println(gx);
    tft.print("gy:");
    tft.println(gy);
    tft.print("gz:");
    tft.println(gz);

    tft.print("temp:");
    tft.println(temp1);
   
    
  }
}
