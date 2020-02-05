
#include "ESC.h"

#define LED_PIN (13)       // Pin for the LED
#define SPEED_MIN (1000)   // Set the Minimum Speed in microseconds
#define SPEED_MAX_1 (2200) // Set the Minimum Speed in microseconds
#define SPEED_MAX_2 (3000)

ESC ThrustFan(9, SPEED_MIN, SPEED_MAX_1, 500); // ESC_Name (ESC PIN, Minimum Value, Maximum Value, Default Speed, Arm Value)
ESC LiftFan(10, SPEED_MIN, SPEED_MAX_2, 500);  // ESC_Name (ESC PIN, Minimum Value, Maximum Value, Default Speed, Arm Value)
int oESC;                                      // Variable for the speed sent to the ESC

int sensorPin = A0;  // select the input pin for the potentiometer
int sensorValue = 0; // variable to store the value coming from the sensor

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT); // LED Visual Output
  ThrustFan.arm();
  LiftFan.arm();               // Send the Arm value so the ESC will be ready to take commands
  digitalWrite(LED_PIN, HIGH); // LED High Once Armed
  delay(1000);                 // Wait for a while
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  Serial.print(sensorValue);
  Serial.print("     ");
  sensorValue = map(sensorValue, 0, 1023, SPEED_MIN, SPEED_MAX_2);
  Serial.println(sensorValue);
//  ThrustFan.speed(SPEED_MAX_1);
//  LiftFan.speed(sensorValue);
  delay(10);
}
