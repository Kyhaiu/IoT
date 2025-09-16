/************************************************************
 * Exercício: Exercício 02 - LEDs em série
 *
 * Descrição:
 * Este programa tem como objetivo demonstrar o que acontece
 * quando três LEDs são conectados em série e ligados ao
 * pino digital 13 do Arduino. O código apenas liga e desliga
 * o pino, enquanto o aluno observa no circuito físico se os
 * LEDs acendem corretamente ou não.
 *
 * Observação: Dependendo da tensão disponível no Arduino,
 * os três LEDs em série podem não acender ou acender de forma
 * muito fraca, pois a soma da queda de tensão de cada LED pode
 * ultrapassar a tensão fornecida pelo pino, além disso a cor do LED
 * pode influenciar no resultado, devido a tensão necessária para
 * ligar cada LED.
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
  // Aqui definimos o pino 13 como saída digital.

  pinMode(13, OUTPUT); // Pino conectado ao conjunto de LEDs em série
}

void loop()
{
  // A função loop() é executada repetidamente em um ciclo infinito.
  // O LED (ou conjunto de LEDs) será ligado e desligado em intervalos
  // de 1 segundo, permitindo observar o comportamento do circuito.

  digitalWrite(13, HIGH); // Liga os LEDs (se a tensão for suficiente)
  delay(1000);            // Aguarda 1 segundo
  digitalWrite(13, LOW);  // Desliga os LEDs
  delay(1000);            // Aguarda 1 segundo
}
