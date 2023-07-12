#include "DHT.h"
#include <LiquidCrystal.h>

#define DHTPIN 7
#define DHTTYPE DHT11

#define green 7
#define red 8

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT dht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  lcd.begin(16,2);

  pinMode(green,OUTPUT);

}

void faile(){
  lcd.setCursor(0, 0);
  lcd.print("faild to read");
  lcd.setCursor(0,1);
  lcd.print("from the senson");
}

void loop() {
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(t) || isnan(h)){
    faile();
    lcd.clear();
  }else{
   if( (h>=30 && h<=50) && (t>=20 && t<=35)){
      lcd.setCursor(0,0);
      lcd.print("Temp: ");
      lcd.print(t);
      lcd.setCursor(0, 1);
      lcd.print("Hum: ");
      lcd.print(h);

    }else if((h < 30)&&(t<20)){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("warning");
    }
  }

  

  
}






