void disp(int size, int x, int y, String text) {
  display.clearDisplay();
  display.setTextSize(size); 
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(x, y);
  display.println(text);
  display.display(); 
}

void disp(int size, int x, int y, int num) {
  display.clearDisplay();
  display.setTextSize(2); 
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(x, y);
  display.println(num);
  display.display(); 
}

void displ(int size, int x, int y, String text) {
  display.setTextSize(size); 
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(x, y);
  display.println(text);
  display.display(); 
}
void displ(int size, int x, int y, int num) {
  display.setTextSize(size); 
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(x, y);
  display.println(num);
  display.display(); 
}
