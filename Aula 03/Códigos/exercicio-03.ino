/************************************************************
 * Exercício: Botão liga LED + controle de velocidade com potenciômetro
 *
 * Descrição:
 * Este programa utiliza um botão para ligar/desligar um LED.
 * Quando o LED está ligado, o potenciômetro controla a
 * velocidade de piscada.
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
const int botao = 2;
const int led = 13;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
}

void loop()
{
  int estadoBotao = digitalRead(botao);
  int valor = analogRead(pot);

  if (estadoBotao == LOW)
  {
    digitalWrite(led, HIGH);
    delay(valor);

    digitalWrite(led, LOW);
    delay(valor);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}
