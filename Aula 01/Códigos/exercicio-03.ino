/************************************************************
 * Exercício: Exercício 02 - Semáforo
 *
 * Descrição:
 * Este programa simula o funcionamento de um semáforo simples
 * utilizando três LEDs (vermelho, amarelo e verde).
 * O ciclo de funcionamento é:
 *   - Verde aceso por 5 segundos
 *   - Amarelo aceso por 2 segundos
 *   - Vermelho aceso por 5 segundos
 * O processo se repete indefinidamente.
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

// Definição dos pinos dos LEDs
const int ledVerde = 8;
const int ledAmarelo = 9;
const int ledVermelho = 10;

void setup()
{
  // A função setup() é executada apenas uma vez,
  // logo após o Arduino ser ligado ou reiniciado.
  // Aqui configuramos os pinos dos LEDs como saídas digitais.

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop()
{
  // A função loop() é executada repetidamente, em um ciclo infinito.
  // Aqui definimos o comportamento do semáforo, controlando
  // a sequência e o tempo em que cada LED ficará aceso.

  // LED Verde aceso por 5 segundos
  digitalWrite(ledVerde, HIGH);
  delay(5000);
  digitalWrite(ledVerde, LOW);

  // LED Amarelo aceso por 2 segundos
  digitalWrite(ledAmarelo, HIGH);
  delay(2000);
  digitalWrite(ledAmarelo, LOW);

  // LED Vermelho aceso por 5 segundos
  digitalWrite(ledVermelho, HIGH);
  delay(5000);
  digitalWrite(ledVermelho, LOW);
}
