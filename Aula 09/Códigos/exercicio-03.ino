#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Endereço padrão do módulo I2C do LCD (pode variar: 0x27 ou 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();      // Inicializa LCD
  lcd.backlight(); // Liga a luz de fundo

  lcd.setCursor(0, 0); // Coluna 0, linha 0
  lcd.print("Hello, World!");

  lcd.setCursor(0, 1); // Coluna 0, linha 1
  lcd.print("Arduino + LCD");
}

void loop()
{
  // Nada aqui, o texto permanece no LCD
}
