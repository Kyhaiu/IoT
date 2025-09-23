#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX do HC-05
int led = 13;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("Escravo aguardando...");
}

void loop()
{
  if (BT.available())
  {
    String comando = BT.readStringUntil('\n');
    comando.trim();

    if (comando == "LIGA")
    {
      digitalWrite(led, HIGH);
      Serial.println("LED ligado");
    }
    else if (comando == "DESLIGA")
    {
      digitalWrite(led, LOW);
      Serial.println("LED desligado");
    }
  }
}
