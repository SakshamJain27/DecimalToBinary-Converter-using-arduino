#include <LiquidCrystal.h>

#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 
int sum;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

String decimal = "";

const int rs = 18, en = 19, d4 = 14, d5 = 15, d6 = 16, d7 = 17;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.write("Enter A Decimal Number");
}

void loop() {
  char customKey = customKeypad.getKey(); 
  if(customKey){
    Serial.println();
    if(customKey=='D'){
      decimal = "";
      lcd.clear();

    }else if(customKey=='B'){
      Serial.println("It is");
      int no = decimal.toInt();
      lcd.clear();
      lcd.print(no, BIN);
    }else{
     decimal=decimal+customKey;
     lcd.clear();
     lcd.print(decimal);
    }
  }
}
