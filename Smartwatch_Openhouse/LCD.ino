

void LCD_setup(){
    //okay
    tft.initR(INITR_BLACKTAB); 
    tft.setFont();
    tft.fillScreen(0x0000);
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    Serial.println("LCD SETUP COMPLETE");
}
