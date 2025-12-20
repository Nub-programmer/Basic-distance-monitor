#include <LiquidCrystal.h>

// LCD pins (regular 16x2, nothing fancy)
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

// ultrasonic sensor pins
const int trigPin = 9;    // sends the ping
const int echoPin = 10;   // waits for the echo

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

long duration;
int distance;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Distance:");

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // just for debugging, not required for LCD
  Serial.begin(9600);
}

void loop() {
  // quick trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // time taken for sound to return
  duration = pulseIn(echoPin, HIGH);

  // simple distance math
  distance = duration * 0.034 / 2;

  lcd.setCursor(0, 1);
  lcd.print("                "); // clear old junk
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  delay(1000); // no need to spam the LCD
}
