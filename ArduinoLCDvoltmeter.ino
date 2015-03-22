#include <LiquidCrystal.h>

// LCD pin setup
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//define 10 samples 
#define number_of_samples 10
// sum of samples read from sensor pin
int sum = 0;
// samples count
unsigned char sample_count = 0;
// calculated voltage
float napiecie = 0.0;            


void setup() {
  Serial.begin(9600); //initialize serial port monitor
  // setup for number of lines and rows of LCD 
  lcd.begin(16, 2);
  //print on LCD
  lcd.print("My Voltmeter");
  
}

void loop() {
  while (sample_count < number_of_samples) {
        sum += analogRead(A2);
        sample_count++;
        delay(10);
    }
  napiecie = ((float)sum / (float)number_of_samples * 4.90) / 1024.0;
  //4.90 is a value on 5V pin of Arduino wich is used as reference to calculate voltage on sensor pin, 
  //you have to "calibrate" voltmeter putting here measured value on +5V
  Serial.print(napiecie);
  Serial.println (" V");
  sample_count = 0;
  sum = 0;
  // set LCD cursor on column 0 and row 1 (we count LCD rows and columns from 0!)
  lcd.setCursor(0, 1);
  // prints voltage
  lcd.print(napiecie);
  // set LCD cursor on column 4 and row 1 (we count LCD rows and columns from 0!)
  lcd.setCursor(4, 1);
  // Volts "V"
  lcd.print(" V");
  }

