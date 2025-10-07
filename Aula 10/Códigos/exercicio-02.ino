// =============================
// Acionamento automático do relé via potenciômetro
// =============================

#define POT_PIN A0  // Pino do potenciômetro
#define RELAY_PIN 7 // Relé
#define LED_PIN 9   // LED indicador opcional

void setup()
{
  pinMode(POT_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH); // Relé inicia ligado (lâmpada acesa)
  digitalWrite(LED_PIN, HIGH);   // LED indicador
  Serial.begin(9600);
}

void loop()
{
  int potValue = analogRead(POT_PIN);

  // Condição para ligar/desligar o relé
  if (potValue > 512)
  {
    digitalWrite(RELAY_PIN, LOW); // Desliga lâmpada
    digitalWrite(LED_PIN, LOW);
  }
  else
  {
    digitalWrite(RELAY_PIN, HIGH); // Liga lâmpada
    digitalWrite(LED_PIN, HIGH);
  }

  Serial.print("Potenciometro: ");
  Serial.print(potValue);
  Serial.print(" | Rele: ");
  Serial.println((potValue > 512) ? "DESLIGADO" : "LIGADO");

  delay(100);
}
