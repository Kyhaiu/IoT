# Aula 10 - Relé

## Descrição

Nesta aula, o foco é compreender **como funciona um relé** e como podemos utiliza-lo em circuitos de automação residencial/industrial.  
O relé será responsável por simular o controle de uma carga elétrica (como uma lâmpada), enquanto o LED representará o comportamento visual da intensidade.

---

## Exercícios

1. **Controle de uma Lâmpada via Botão (introdução ao relé)**  
   O aluno deverá montar um circuito simples de acionamento do relé utilizando um botão, ao pressionar o botão, o circuito deve acender acionar o relé.

2. **Acionamento automático do relé**  
   Quando o valor lido no potenciômetro ultrapassar **metade do valor máximo (512)**, o **relé deverá ser acionado automaticamente**, desligando a luz.  
   Caso o valor seja inferior, o relé deve permanecer ligado.

3. **Sistema de aquecimento automática (DHT11 + relé)**  
   O circuito deve ter um sensor de temperatura e umidade (DHT11), que indicará através de um **LED RGB**, qual é o estado (_vermelho_ = quente, _verde_ = normal, _azul_ = fria), e com base no valor de temperatura determinar quando ligar a lampada de aquecimento.

4. **Portão automático**
   O circuito deve detectar a distância utilizando o sensor **SR04**, e quando estiver proximo ele deve acionar o mecanismo que abre o portão utilizando o **servo motor** e acender uma lampada para iluminar a entrada.

---

## Materiais necessários

- Arduino Uno (ou compatível)
- Protoboard
- Potenciômetro de 10kΩ
- LED comum
- Resistor de 220Ω ou 330Ω para o LED
- Módulo relé (5V)
- Jumpers (macho-macho)
- Cabo USB para conexão ao computador

---

## Padrão de cores (Color Coding) dos jumpers

- **Preto** → GND (terra)
- **Vermelho** → VCC (5V)
- **Azul** → Saída
- **Verde** → Entrada
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
