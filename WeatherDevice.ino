#include <LiquidCrystal.h>
#include <TemperatureLed.h>
#include <DHT.h>

#define LCD_CONTRAST_PIN 6
#define LCD_BACKLIGHT_PIN 10

#define DHT_TYPE DHT11
#define DHT_PIN 8

#define RED_PIN 18
#define GREEN_PIN 19
#define BLUE_PIN 20

LiquidCrystal lcd(13, 12, 5, 4, 3, 2);  
TemperatureLed led(RED_PIN, GREEN_PIN, BLUE_PIN);
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {  

  Serial.begin(9600);

  dht.begin();

  pinMode(9, OUTPUT);

  analogWrite(9, 100);

  analogWrite(LCD_BACKLIGHT_PIN, 255);

  analogWrite(LCD_CONTRAST_PIN, 150);

  lcd.begin(16, 2);

  led.begin();
}  

void loop() {  

  float humidity = dht.readHumidity();

  float fahrenheit = dht.readTemperature(true);

  if(fahrenheit <= 68.5) {

    led.changeLedColor(led.blueColor);

  } else if((fahrenheit >= 68.6) && (fahrenheit <= 72.5)) {
    
    led.setCustomLedColor(0, 255, 255);

  } else if((fahrenheit >= 72.6) && (fahrenheit <= 76.5)) {
    
    led.changeLedColor(led.greenColor);

  } else if((fahrenheit >= 76.6) && (fahrenheit <= 80.5)) {
    
    led.setCustomLedColor(255, 255, 0);

  } else if(fahrenheit >= 80.6) {
    
    led.changeLedColor(led.redColor);
  }

  lcd.setCursor(0, 0);

  lcd.print("Temp: ");
  lcd.print(fahrenheit, 0);
  lcd.print((char)223);
  lcd.print("F");


  lcd.setCursor(0, 1);

  lcd.print("Humidity: ");
  lcd.print(humidity, 0);
  lcd.print("%");

  delay(10000);
}
