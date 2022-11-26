#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;
int const buzzPin = 1;
const int ledPin = 12;
long duration;
int distanceCm, distanceInch;
void setup() { 
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzPin, OUTPUT);
pinMode(ledPin, OUTPUT); 
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
if (distanceCm <= 4) {
// Buzz
digitalWrite(buzzPin, HIGH);
digitalWrite(ledPin, HIGH); 
} else {
// Don't buzz
digitalWrite(buzzPin, LOW);
digitalWrite(ledPin, LOW); 
}
delay(20);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Distance = "); // Prints string "Distance" on the LCD
lcd.print(distanceCm); // Prints the distance value from the sensor
lcd.print(" cm ");
delay(250);
lcd.setCursor(0,1);
lcd.print("Distance = ");
lcd.print(distanceInch);
lcd.print(" inch");
delay(250);
}
