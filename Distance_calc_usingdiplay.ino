#include <LiquidCrystal.h>

// LCD pins (basic 16x2 LCD, no I2C stuff)
const int rs = 12;   // tells LCD "hey this is a command / data"
const int en = 11;   // enables the LCD to read data
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

// ultrasonic sensor pins
const int trigPin = 9;   // sends the sound wave
const int echoPin = 10;  // listens for the sound coming back

// creating the LCD object with the pins above
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

long duration;   // time taken for echo
int distance;    // final distance in cm

void setup() {
  // start the LCD (16 columns, 2 rows)
  lcd.begin(16, 2);

  // first line text
  lcd.print("Distance:");

  // ultrasonic pin modes
  pinMode(trigPin, OUTPUT);  // trigger sends signal
  pinMode(echoPin, INPUT);   // echo receives signal

  // serial just for debugging if needed
  Serial.begin(9600);
}

void loop() {
  // make sure trigger is LOW first
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // send a short pulse to ultrasonic sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // get how long the echo stayed HIGH
  duration = pulseIn(echoPin, HIGH);

  // convert time into distance (cm)
  distance = duration * 0.034 / 2;

  // go to second line of LCD
  lcd.setCursor(0, 1);

  // clear old values so screen doesn’t glitch
  lcd.print("                ");

  // print distance
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  // wait a bit before next reading
  delay(1000);
}
