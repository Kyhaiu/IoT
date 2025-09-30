#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pinos do LED RGB (PWM)
int pinR = 9;
int pinG = 10; // não usado aqui
int pinB = 11;

// Pinos do sensor HC-SR04
int trigPin = 6;
int echoPin = 7;

long duration;
int distance;

void setup()
{
  lcd.init();
  lcd.backlight();

  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Sistema Alerta");
  delay(2000);
  lcd.clear();
}

void loop()
{
  // Gera pulso no trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Mede o tempo do eco
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // cm

  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" cm   "); // espaços extras para apagar restos

  if (distance < 20)
  {
    lcd.setCursor(0, 1);
    lcd.print("Muito perto!   ");
    setColor(255, 0, 0); // Vermelho
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print("Muito longe    ");
    setColor(0, 0, 255); // Azul
  }

  delay(300);
}

void setColor(int red, int green, int blue)
{
  analogWrite(pinR, red);
  analogWrite(pinG, green);
  analogWrite(pinB, blue);
}
