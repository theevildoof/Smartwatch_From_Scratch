void tft_setup(){
   // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
     tft.initR(INITR_BLACKTAB); 

    tft.setFont();
    tft.setTextColor(0xFFE0);
    tft.setTextSize(1);
}
