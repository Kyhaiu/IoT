#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Botão
int buttonPin = 2;
int lastButtonState = HIGH;
int menuState = 0;

// LED RGB
int pinR = 9, pinG = 10, pinB = 11;

// Sensor HC-SR04
int trigPin = 6, echoPin = 7;
long duration;
int distance;

void setup()
{
  lcd.init();
  lcd.backlight();

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Menu LCD");
  delay(2000);
  lcd.clear();
}

void loop()
{
  // Detecta botão pressionado
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH)
  {
    menuState = (menuState + 1) % 2; // alterna entre 0 e 1
    lcd.clear();
    delay(200); // debounce
  }
  lastButtonState = buttonState;

  if (menuState == 0)
  {
    mostrarDistancia();
  }
  else
  {
    mostrarRGB();
  }
}

void mostrarDistancia()
{
  // Mede distância
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  lcd.setCursor(0, 0);
  lcd.print("Distancia:");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm    ");
}

void mostrarRGB()
{
  static int r = 255, g = 0, b = 0;

  lcd.setCursor(0, 0);
  lcd.print("RGB:");
  lcd.setCursor(0, 1);
  lcd.print("R:");
  lcd.print(r);
  lcd.print(" G:");
  lcd.print(g);
  lcd.print(" B:");
  lcd.print(b);

  setColor(r, g, b);

  // Troca simples de cor
  delay(500);
  r = random(0, 256);
  g = random(0, 256);
  b = random(0, 256);
}

void setColor(int red, int green, int blue)
{
  analogWrite(pinR, red);
  analogWrite(pinG, green);
  analogWrite(pinB, blue);
}
