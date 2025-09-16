/************************************************************
 * Exercício: Alternar LED com botão
 *
 * Descrição:
 * Este programa demonstra como alternar o estado de um LED
 * (ligado/desligado) a cada pressão de um botão. O objetivo
 * é ensinar controle de estado e leitura de entradas digitais.
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

const int led1 = 13;
const int led2 = 12;
const int botao = 2;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(botao, INPUT);
}

void loop()
{
  bool estadoBotao = digitalRead(botao);

  // Detecta mudança de estado do botão
  if (ultimoEstadoBotao == HIGH)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    delay(200); // Debounce simples
  }
  else
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    delay(200); // Debounce simples
  }
}
