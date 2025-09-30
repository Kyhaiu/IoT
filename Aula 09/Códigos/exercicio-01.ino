// Definição dos pinos PWM para o LED RGB
int pinR = 9;  // Vermelho
int pinG = 10; // Verde
int pinB = 11; // Azul

void setup()
{
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop()
{
  // Vermelho
  setColor(255, 0, 0);
  delay(1000);

  // Verde
  setColor(0, 255, 0);
  delay(1000);

  // Azul
  setColor(0, 0, 255);
  delay(1000);

  // Amarelo (R + G)
  setColor(255, 255, 0);
  delay(1000);

  // Ciano (G + B)
  setColor(0, 255, 255);
  delay(1000);

  // Magenta (R + B)
  setColor(255, 0, 255);
  delay(1000);

  // Branco (R + G + B)
  setColor(255, 255, 255);
  delay(1000);

  // Apagado
  setColor(0, 0, 0);
  delay(1000);
}

// Função para definir a cor do LED RGB
void setColor(int red, int green, int blue)
{
  analogWrite(pinR, red); // Valor de 0 a 255
  analogWrite(pinG, green);
  analogWrite(pinB, blue);
}
