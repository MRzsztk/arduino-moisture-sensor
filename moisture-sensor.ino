#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorPin = A0; 
int moisture;
int prevMoisture = -1;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.print("Initializing");
  lcd.setCursor(0, 1);
  lcd.print("measurement");
  Serial.println("Initializing measurement...");
  delay(2000);
}

void loop() {
  moisture = analogRead(sensorPin);
//  Serial.print(moisture);
//  delay(1000);
  moisture = map(moisture,1023,0,0,100);
  if (moisture != prevMoisture) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Moisture (%):");
    lcd.setCursor(0, 1);
    lcd.print(moisture, DEC);
    Serial.print("Moisture: ");
    Serial.print(moisture);
    Serial.println("%");
    delay(5000);
  }
  prevMoisture = moisture;
}
