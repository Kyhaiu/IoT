/************************************************************
 * Exercício: Controlar a velocidade do LED com potenciômetro
 *
 * Descrição:
 * Este programa utiliza um potenciômetro para controlar a
 * velocidade com que um LED pisca. Quanto maior o valor lido,
 * maior será o tempo de delay.
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

const int pot = A0;
const int led = 13;

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  int valor = analogRead(pot);

  digitalWrite(led, HIGH);
  delay(valor);

  digitalWrite(led, LOW);
  delay(valor);
}
