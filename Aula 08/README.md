# Aula 08 - Conexão e configuração Bluetooth (HC-05)

## Descrição

Nesta aula, o foco é aprofundarmos mais no dispositivo **HC-05**, onde iremos aprender a mexer nas configurações do dispositivo, mudando nome, modo de atuação (_mestre_ e _escravo_).

---

## Exercícios

1. **Configurar o HC-05**  
   Vamos aprender a como configurar o HC-05 mudando seu nome e definindo o modo de atuação

2. **Controlar outro Arduino via Bluetooth**
   Vamos configurar um Arduino como **_mestre_** e outro como **_escravo_**, vamos configurar o mestre para se conectar especificamente a um **_escravo_**. E vamos fazer o LED do escravo piscar, depois vamos inverter os papeis.

3. **Controlar outro Arduino via Bluetooth usando botão**
   Vamos adicionar um botão ao circuito do exercício anterior

---

## Materiais necessários

- Arduino Uno (ou compatível)
- Protoboard
- HC-05 (preferencialmente)
- LED
- Resistor de 220Ω ou 330Ω para o LED
- Resistor de 1KΩ e 2KΩ para devisor de tensão (Comunicação Arduino -> HC-05)
- Jumpers (macho-macho)
- Cabo USB para conexão ao computador

---

## Padrão de cores (Color Coding) dos jumpers

- **Preto** → GND (terra)
- **Vermelho** → VCC (5V ou 3.3V)
- **Azul** → Saída digital do Arduino
- **Verde** → Entrada digital / sinais de sensores
- **Amarelo/Laranja** → Comunicação ou conexões auxiliares

---

## Licença

Este repositório é distribuído sob a **GPL-3.0 License**.  
Você pode utilizar e modificar os arquivos livremente, desde que mantenha a mesma licença.

---

## Aviso sobre os slides em PDF

Os slides desta aula são **materiais de apoio para estudo**.  
Eles podem ser utilizados como referência ou inspiração, desde que seja feita a **devida citação de autoria**:  
**Marcos Augusto Campagnaro Mucelini**.

O uso sem atribuição ou apresentação como trabalho próprio caracteriza **plágio**.
