#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); // RX | TX

char flag = 0;
int led = 13;

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(led, OUTPUT);
}
void loop()
{
  if (bluetooth.available())
    flag = bluetooth.read();

  if (flag == 'w')
  {
    digitalWrite(led, HIGH);
    Serial.println("LED On");
  }
  else if (flag == 's')
  {
    digitalWrite(led, LOW);
    Serial.println("LED Off");
  }
  else if (flag == '0')
  {
    digitalWrite(led, LOW);
    Serial.println("LED Off");
  }
}            
