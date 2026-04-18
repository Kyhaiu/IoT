/************************************************************
 * Exercício: Ler o valor de um potenciômetro no Serial
 *
 * Descrição:
 * Este programa lê o valor analógico de um potenciômetro
 * conectado ao Arduino e exibe o valor no Serial Monitor.
 * O objetivo é ensinar leitura de entradas analógicas.
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

const int pot = A0; // Potenciômetro conectado na porta A0

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int valor = analogRead(pot);
  Serial.println(valor);

  delay(200);
}
