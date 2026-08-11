
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

// Pin mapping
#define DHTPIN 2
#define DHTTYPE DHT22
#define LDRPIN A0
#define TRIGPIN 3
#define ECHOPIN 4
#define BUZZER 8
#define LED_RED 5
#define LED_YELLOW 6
#define LED_GREEN 7

// Objects
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust address if needed

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  pinMode(LDRPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("System Ready");
}

void loop() {
  // DHT22 readings
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // LDR reading
  int ldrValue = analogRead(LDRPIN);

  // HC-SR04 distance
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  long duration = pulseIn(ECHOPIN, HIGH);
  int distance = duration * 0.034 / 2;

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print("C H:");
  lcd.print(hum);
  lcd.setCursor(0,1);
  lcd.print("L:");
  lcd.print(ldrValue);
  lcd.print(" D:");
  lcd.print(distance);

  // LED logic (example thresholds)
  if (temp > 30) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(BUZZER, HIGH);
  } else if (temp > 20) {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(BUZZER, LOW);
  } else {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(BUZZER, LOW);
  }

  delay(1000);
}
