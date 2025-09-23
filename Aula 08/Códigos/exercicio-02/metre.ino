#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX

void setup()
{
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("Mestre pronto. Enviando comandos...");
}

void loop()
{
  BT.println("LIGA"); // envia comando
  delay(2000);
  BT.println("DESLIGA");
  delay(2000);
}
