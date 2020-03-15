
#include "ESC.h"
#define LED_PIN (13)              // Pin for the LED 

ESC ThrustFan(9, SPEED_MIN, SPEED_MAX_1, 500); // ESC_Name (ESC PIN, Minimum Value, Maximum Value, Default Speed, Arm Value)
ESC LiftFan(10, SPEED_MIN, SPEED_MAX_2, 500);  // ESC_Name (ESC PIN, Minimum Value, Maximum Value, Default Speed, Arm Value)

void setup() {
  pinMode(LED_PIN, OUTPUT);       // LED Visual Output (can be removed)
  digitalWrite(LED_PIN, HIGH);    // LED High while signal is High (can be removed)
  ThrustFan.calib();                  // Calibration of the Max and Min value the ESC is expecting
  ThrustFan.stop();                   // Stop the ESC to avoid damage or injuries
 
  LiftFan.calib();                  // Calibration of the Max and Min value the ESC is expecting
  LiftFan.stop();                   // Stop the ESC to avoid damage or injuries
  digitalWrite(LED_PIN, LOW);     // LED Low when the calibration is done (can be removed)
}

void loop() {

}