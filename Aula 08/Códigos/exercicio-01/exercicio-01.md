# Configuração AT dos módulos HC-05

## Passo 1 – Colocar o HC-05 em modo AT

1. Desligue o HC-05.
2. Pressione e segure o botão do módulo (se houver) e ligue a alimentação (3.3 ou 5V) no pino KEY/EN.
3. O LED piscará lentamente indicando modo AT.

## Passo 2 – Conectar ao Arduino

- TX do HC-05 → TX do Arduino
- RX do HC-05 → RX do Arduino (usar divisor de tensão)
- VCC → 5V
- GND → GND
- KEY/EN → 5V
- Abrir Monitor Serial a 38400 baud.

## Configuração do Escravo

```
Enviar os comandos AT:
AT           # Verifica comunicação, retorna OK
AT+ROLE?     # Verifica em qual modo está operando
AT+ROLE=0    # Define como mestre e escravo (funcionamento dual)
AT+ADDR?     # Mostra o endereço Bluetooth (ex: 1234,56,ABCDEF)
```

## Configuração do Mestre

```
Enviar os comandos AT:
AT                      # Verifica comunicação, retorna OK
AT+ROLE?                # Verifica em qual modo está operando
AT+ROLE=1               # Define como mestre e escravo (funcionamento dual)
AT+CMODE=0              # Conecta apenas a 1 dispositivo específico (força ele a assumir o papel de mestre)
AT+BIND=1234,56,ABCDEF  # Endereço do escravo obtido acima
```
