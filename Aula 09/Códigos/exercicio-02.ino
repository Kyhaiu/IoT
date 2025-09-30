// Pinos dos LEDs RGB
int pinR = 9;
int pinG = 10;
int pinB = 11;

// Pinos dos potenciômetros
int potR = A0;
int potG = A1;
int potB = A2;

void setup()
{
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop()
{
  // Leitura dos potenciômetros (0–1023)
  int valR = analogRead(potR);
  int valG = analogRead(potG);
  int valB = analogRead(potB);

  // Mapeamento para PWM (0–255)
  valR = map(valR, 0, 1023, 0, 255);
  valG = map(valG, 0, 1023, 0, 255);
  valB = map(valB, 0, 1023, 0, 255);

  // Ajuste das cores
  analogWrite(pinR, valR);
  analogWrite(pinG, valG);
  analogWrite(pinB, valB);
}
