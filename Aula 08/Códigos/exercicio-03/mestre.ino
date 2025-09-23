#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX do HC-05
int botao = 2;             // Pino do botão
int estadoAnterior = LOW;

void setup()
{
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(botao, INPUT_PULLUP); // Botão com pull-up interno
  Serial.println("Mestre pronto. Aguarde botão...");
}

void loop()
{
  int estadoAtual = digitalRead(botao);

  // Detecta mudança de estado do botão
  if (estadoAtual == LOW && estadoAnterior == HIGH)
  { // botão pressionado
    BT.println("LIGA");
    Serial.println("Comando LIGA enviado");
  }
  else if (estadoAtual == HIGH && estadoAnterior == LOW)
  { // botão solto
    BT.println("DESLIGA");
    Serial.println("Comando DESLIGA enviado");
  }

  estadoAnterior = estadoAtual;
  delay(50); // debounce simples
}
