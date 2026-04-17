/************************************************************
 * Exercício: Acender LEDs de acordo com a temperatura (DHT11)
 *
 * Descrição:
 * Este programa utiliza o sensor DHT11 para medir a temperatura
 * ambiente e acender diferentes LEDs de acordo com a faixa
 * de temperatura (frio, médio ou quente).
 *
 * Autor: Marcos Augusto Campagnaro Mucelini
 * Instituição: FAG - Engenharia de Software
 *
 * Licença:
 * Este programa é software livre: você pode redistribuí-lo e/ou
 * modificá-lo sob os termos da Licença Pública Geral GNU, conforme
 * publicada pela Free Software Foundation, na versão 3 da Licença
 * ou (a seu critério) qualquer versão posterior.
 *
 * Este programa é distribuído na esperança de que seja útil,
 * mas SEM NENHUMA GARANTIA; sem mesmo a garantia implícita de
 * COMERCIALIZAÇÃO ou ADEQUAÇÃO A UM DETERMINADO PROPÓSITO.
 * Consulte a Licença Pública Geral GNU para mais detalhes.
 *
 * Você deve ter recebido uma cópia da Licença Pública Geral GNU
 * junto com este programa. Caso contrário, veja <https://www.gnu.org/licenses/>.
 ************************************************************/

#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int ledFrio = 3;
const int ledMedio = 4;
const int ledQuente = 5;

void setup()
{
  dht.begin();

  pinMode(ledFrio, OUTPUT);
  pinMode(ledMedio, OUTPUT);
  pinMode(ledQuente, OUTPUT);
}

void loop()
{
  float temperatura = dht.readTemperature();

  if (temperatura < 20)
  {
    digitalWrite(ledFrio, HIGH);
    digitalWrite(ledMedio, LOW);
    digitalWrite(ledQuente, LOW);
  }
  else if (temperatura >= 20 && temperatura < 28)
  {
    digitalWrite(ledFrio, LOW);
    digitalWrite(ledMedio, HIGH);
    digitalWrite(ledQuente, LOW);
  }
  else
  {
    digitalWrite(ledFrio, LOW);
    digitalWrite(ledMedio, LOW);
    digitalWrite(ledQuente, HIGH);
  }

  delay(2000);
}
