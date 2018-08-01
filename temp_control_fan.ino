#include "DHT.h"
#include "LiquidCrystal.h"

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define DHTPIN 8

#define DHTTYPE DHT22
DHT sensor(DHTPIN, DHTTYPE);

void setup() 
{
  lcd.begin(16,2);
  sensor.begin();
  pinMode(relay_pin, OUTPUT);
  digitalWrite(relay_pin, HIGH);
}

void loop() 
{
  lcd.clear();
  float t = sensor.readTemperature(); //reading the temperature from the sensor
  // Checking if the sensor is sending values or not
  if (isnan(t)) 
  {
    lcd.print("Failed");
    delay(1000);
    return;
  }
  
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");
  if (t > 35)
  {
    digitalWrite(relay_pin, LOW);
    lcd.setCursor(0,1);
    lcd.print("Fan is ON ");
    delay(10);
  }
}
