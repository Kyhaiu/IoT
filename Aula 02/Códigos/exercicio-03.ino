/************************************************************
 * Exercício: Knight Rider Effect
 *
 * Descrição:
 * Este programa demonstra o efeito visual conhecido como
 * "Knight Rider", acendendo quatro LEDs em sequência
 * da esquerda para a direita e de volta. Ensina controle
 * de múltiplos LEDs e lógica sequencial.
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

const int leds[] = {8, 9, 10, 11}; // LEDs conectados aos pinos 8 a 11
const int numLEDs = 4;
const int tempo = 200; // Tempo em ms entre LEDs

void setup()
{
  for (int i = 0; i < numLEDs; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{
  // Sequência da esquerda para a direita
  for (int i = 0; i < numLEDs; i++)
  {
    digitalWrite(leds[i], HIGH);
    delay(tempo);
    digitalWrite(leds[i], LOW);
  }

  // Sequência da direita para a esquerda
  for (int i = numLEDs - 2; i > 0; i--)
  {
    digitalWrite(leds[i], HIGH);
    delay(tempo);
    digitalWrite(leds[i], LOW);
  }
}
