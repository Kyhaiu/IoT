// =============================
// Portão automático com sensor de distância
// =============================

#include <Servo.h>

#define TRIG_PIN 2
#define ECHO_PIN 3
#define RELAY_PIN 7 // Lâmpada de entrada
#define SERVO_PIN 9

Servo portao;

void setup()
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
  portao.attach(SERVO_PIN);
  portao.write(0); // Portão fechado

  Serial.begin(9600);
}

long medirDistancia()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2; // cm
  return distance;
}

void loop()
{
  long dist = medirDistancia();
  Serial.print("Distancia: ");
  Serial.print(dist);
  Serial.println(" cm");

  if (dist > 0 && dist < 15)
  {                                // Alguém se aproximou
    portao.write(90);              // Abre portão
    digitalWrite(RELAY_PIN, HIGH); // Liga lâmpada
  }
  else
  {
    portao.write(0);              // Fecha portão
    digitalWrite(RELAY_PIN, LOW); // Desliga lâmpada
  }

  delay(500);
}
