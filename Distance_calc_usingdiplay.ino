#include <LiquidCrystal.h>

// Define the pins for the LCD
const int rs = 12;  // Register Select
const int en = 11;  // Enable
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

// Define the pins for the ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

long duration;
int distance;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Distance:");

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Generate a 10us pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the pulse on the echoPin
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters using the speed of sound
  distance = duration * 0.034 / 2;

  // Display the distance on the LCD
  lcd.setCursor(0, 1);
  lcd.print("                "); // Clear the previous distance
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  delay(1000); // Wait for 1 second before the next measurement
}
