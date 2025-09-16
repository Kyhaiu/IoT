/************************************************************
 * Exercício: Exercício 01 - Blink
 *
 * Descrição:
 * Este programa tem como objetivo demonstrar o funcionamento
 * básico do Arduino, fazendo com que o LED conectado ao pino 13
 * pisque em intervalos de 1 segundo. Este é o exemplo clássico
 * conhecido como "Blink".
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

void setup()
{
  // A função setup() é executada apenas uma vez,
  // logo após o Arduino ser ligado ou reiniciado.
  // Nela configuramos os parâmetros iniciais do programa,
  // como a definição dos pinos de entrada e saída.

  pinMode(13, OUTPUT); // Define que vamos utilizar o pino 13 no modo de saída
}

void loop()
{
  // A função loop() é executada repetidamente, em um ciclo infinito,
  // enquanto o Arduino estiver ligado. Aqui colocamos o comportamento
  // principal do programa, que ficará se repetindo continuamente.

  digitalWrite(13, LOW);  // Manda um pulso baixo (desligado) no pino 13
  delay(1000);            // Aguarda 1 segundo
  digitalWrite(13, HIGH); // Manda um pulso alto (ligado) no pino 13
  delay(1000);            // Aguarda 1 segundo
}
