/************************************************************
 * Exercício: Acender LED com botão
 *
 * Descrição:
 * Este programa demonstra como acender um LED enquanto um
 * botão estiver pressionado. O objetivo é ensinar leitura
 * de entradas digitais e acionamento de saídas.
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

const int led = 13;  // LED conectado ao pino 13
const int botao = 2; // Botão conectado ao pino 2

void setup()
{
  pinMode(led, OUTPUT);  // Modo de operação: Saída (Envia pulso)
  pinMode(botao, INPUT); // Modo de operação: Entrada (Recebe pulso)
}

void loop()
{
  int buttonState = digitalRead(botao);
  if (buttonState == LOW)
  { // Botão pressionado
    digitalWrite(led, HIGH);
  }
  else
  { // Botão não pressionado
    digitalWrite(led, LOW);
  }
}
