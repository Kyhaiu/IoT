/************************************************************
 * Exercício: Controle de Servo via HC-05
 *
 * Descrição:
 * Este programa demonstra como controlar um motor servo
 * utilizando o módulo Bluetooth HC-05. O Arduino recebe
 * comandos do celular (via aplicativo serial Bluetooth)
 * e ajusta o ângulo do servo conforme os valores recebidos.
 *
 * Comando esperado:
 *  Enviar um número de 0 a 180 (em texto) pelo Bluetooth.
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

#include <Servo.h>

Servo meuServo;
const int pinoServo = 9; // Conecte o fio de sinal do servo no pino 9

String buffer = ""; // Armazena dados recebidos

void setup()
{
  meuServo.attach(pinoServo);
  meuServo.write(90); // Posição inicial (meio)

  Serial.begin(9600); // Comunicação com o HC-05
}

void loop()
{
  // Verifica se chegou algum dado via Bluetooth
  if (Serial.available())
  {
    char c = Serial.read();

    // O código acumula os caracteres recebidos até detectar \n ou \r (enter).
    if (c == '\n' || c == '\r')
    {
      if (buffer.length() > 0)
      {
        int angulo = buffer.toInt(); // Converte string para número
        if (angulo >= 0 && angulo <= 180)
        {
          meuServo.write(angulo);
        }
        buffer = ""; // Limpa buffer para próxima leitura
      }
    }
    else
    {
      buffer += c; // Continua montando a string recebida
    }
  }
}
