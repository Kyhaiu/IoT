// =============================
// Controle de lâmpada via botão com relé
// =============================

#define BUTTON_PIN 2 // Botão
#define RELAY_PIN 7  // Relé
#define LED_PIN 9    // LED indicador opcional

void setup()
{
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Botão com pull-up interno
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW); // Relé inicia desligado
  digitalWrite(LED_PIN, LOW);   // LED desligado
}

void loop()
{
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW)
  {                                // Botão pressionado
    digitalWrite(RELAY_PIN, HIGH); // Liga relé (acende lâmpada)
    digitalWrite(LED_PIN, HIGH);   // LED indicador
  }
  else
  {
    digitalWrite(RELAY_PIN, LOW); // Desliga relé
    digitalWrite(LED_PIN, LOW);
  }
}
