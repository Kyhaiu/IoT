/************************************************************
 * Exercício: Controle de LED via HC-05 (Serial Padrão)
 *
 * Descrição:
 * Este programa demonstra como controlar um LED utilizando
 * o módulo Bluetooth HC-05. O Arduino recebe comandos do
 * celular (via aplicativo serial Bluetooth) e acende ou
 * apaga o LED de acordo com os caracteres recebidos.
 *
 * Conexões (usando Serial padrão):
 *  HC-05 TX -> Pino 0 (RX do Arduino)
 *  HC-05 RX -> Pino 1 (TX do Arduino)
 *  HC-05 VCC -> 5V
 *  HC-05 GND -> GND
 *
 * Comandos:
 *  '1' -> Acende o LED
 *  '0' -> Apaga o LED
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

const int led = 13; // LED conectado ao pino 13

void setup()
{
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  Serial.begin(9600); // Comunicação serial com HC-05
}

void loop()
{
  if (Serial.available())
  {
    char comando = Serial.read();

    if (comando == '1')
    {
      digitalWrite(led, HIGH);
    }
    else if (comando == '0')
    {
      digitalWrite(led, LOW);
    }
  }
}
