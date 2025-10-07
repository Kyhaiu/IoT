// =============================
// Sistema de aquecimento automático
// =============================

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define RELAY_PIN 7 // Lâmpada de aquecimento
#define LED_R 9
#define LED_G 10
#define LED_B 11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
  dht.begin();
  Serial.begin(9600);
}

void loop()
{
  float temp = dht.readTemperature(); // Leitura em °C
  float hum = dht.readHumidity();     // Leitura de umidade

  if (isnan(temp) || isnan(hum))
  {
    Serial.println("Falha na leitura do DHT11!");
    return;
  }

  // Estado da lâmpada de aquecimento: liga se temperatura < 25°C
  if (temp < 25)
  {
    digitalWrite(RELAY_PIN, HIGH); // Liga aquecimento
  }
  else
  {
    digitalWrite(RELAY_PIN, LOW); // Desliga aquecimento
  }

  // Controle do LED RGB
  if (temp < 20)
  { // Frio
    analogWrite(LED_R, 0);
    analogWrite(LED_G, 0);
    analogWrite(LED_B, 255);
  }
  else if (temp >= 20 && temp <= 25)
  { // Normal
    analogWrite(LED_R, 0);
    analogWrite(LED_G, 255);
    analogWrite(LED_B, 0);
  }
  else
  { // Quente
    analogWrite(LED_R, 255);
    analogWrite(LED_G, 0);
    analogWrite(LED_B, 0);
  }

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C | Umid: ");
  Serial.print(hum);
  Serial.print(" % | Rele: ");
  Serial.println((temp < 25) ? "LIGADO" : "DESLIGADO");

  delay(2000);
}
