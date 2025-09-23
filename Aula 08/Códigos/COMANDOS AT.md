# Comandos AT do HC-05

O HC-05 é um módulo Bluetooth clássico que pode ser configurado via **modo AT**.  
Para entrar em **modo AT**, normalmente você deve **pressionar o botão do módulo enquanto liga**.  
A comunicação com o módulo pode ser feita pelo Serial Monitor do Arduino (geralmente a 38400 bps em modo AT).

---

## 1. Comandos Básicos

| Comando                          | Descrição                                                         |
| -------------------------------- | ----------------------------------------------------------------- |
| `AT`                             | Testa comunicação. Retorna `OK`.                                  |
| `AT+VERSION?`                    | Retorna a versão do firmware.                                     |
| `AT+NAME?`                       | Retorna o nome atual do módulo.                                   |
| `AT+NAME=<nome>`                 | Define um novo nome para o módulo.                                |
| `AT+ROLE?`                       | Retorna o modo (0 = escravo, 1 = mestre, 2 = mestre + escravo).   |
| `AT+ROLE=<role>`                 | Define o papel do módulo.                                         |
| `AT+UART?`                       | Retorna configuração da porta serial (baud, stop bits, paridade). |
| `AT+UART=<baud>,<stop>,<parity>` | Configura a porta serial. Ex.: `AT+UART=9600,0,0`                 |
| `AT+RESET`                       | Reinicia o módulo.                                                |

---

## 2. Comandos de Pareamento e Conexão

| Comando                  | Descrição                                                                           |
| ------------------------ | ----------------------------------------------------------------------------------- |
| `AT+CMODE?`              | Verifica modo de conexão (0 = um dispositivo específico, 1 = qualquer dispositivo). |
| `AT+CMODE=<mode>`        | Configura modo de conexão.                                                          |
| `AT+BIND?`               | Mostra o endereço do módulo ao qual se conecta automaticamente.                     |
| `AT+BIND=<addr>`         | Define o endereço de outro HC-05 para conexão automática (apenas em modo mestre).   |
| `AT+PAIR=<addr>,<tempo>` | Faz pareamento com um endereço específico por `<tempo>` segundos.                   |
| `AT+LINK=<addr>`         | Conecta manualmente a um endereço Bluetooth específico.                             |

---

## 3. Comandos de Visibilidade e Senha

| Comando         | Descrição                                                   |
| --------------- | ----------------------------------------------------------- |
| `AT+PSWD?`      | Consulta a senha (PIN) do módulo.                           |
| `AT+PSWD=<pin>` | Define uma nova senha. Ex.: `AT+PSWD=1234`                  |
| `AT+INQM`       | Configura pesquisa de dispositivos (classe, máximo, tempo). |

---

## 4. Consultas de Endereço e Estado

| Comando     | Descrição                                                   |
| ----------- | ----------------------------------------------------------- |
| `AT+ADDR?`  | Retorna o endereço Bluetooth do módulo.                     |
| `AT+STATE?` | Retorna o estado atual do módulo (pareado, conectado, etc). |

---

## 5. Outros Comandos Úteis

| Comando     | Descrição                                                 |
| ----------- | --------------------------------------------------------- |
| `AT+POLAR?` | Verifica polaridade de LEDs (opcional em alguns módulos). |
| `AT+ROLE=2` | Configura modo **mestre + escravo** (dual).               |
| `AT+RESET`  | Reinicia o módulo após alterações.                        |

---

💡 **Dicas:**

- Sempre use `\r\n` ao enviar comandos via Serial.
- O módulo deve responder `OK` se o comando for aceito.
- Para mudanças de nome, PIN ou função, use **RESET** depois para aplicar.
- Módulos diferentes podem ter pequenas variações nos comandos, então consulte a documentação específica do seu HC-05 se algum comando não funcionar.
