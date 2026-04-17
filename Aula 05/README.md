# Aula 05 - Sensores: HC-SR04 e DHT11

## Descrição

Nesta aula, o foco é a utilização de sensores com o Arduino.  
O aluno irá aprender como coletar dados do ambiente utilizando sensores e utilizá-los para controlar LEDs com base nessas informações.

Serão utilizados:

- **HC-SR04** → sensor de distância (ultrassônico)
- **DHT11** → sensor de temperatura e umidade

---

## Exercícios

1. **SR04 simples acender LED**  
   O LED acende quando um objeto é detectado a uma distância definida.

2. **SR04 controlar a distância do sensor e acender o LED**  
   O comportamento do LED varia de acordo com a distância medida.

3. **Acender 3 LEDs de acordo com a temperatura (DHT11)**  
   LEDs diferentes indicam faixas de temperatura (frio, médio, quente).

---

## Materiais necessários

- Arduino Uno (ou compatível)
- Protoboard
- LEDs (mínimo 3)
- Resistores (220Ω ou 330Ω)
- Sensor HC-SR04
- Sensor DHT11
- Jumpers (macho-macho)
- Cabo USB para conexão ao computador

---

## Sensor HC-SR04 (Ultrassônico)

### Funcionamento

O HC-SR04 mede distância utilizando ondas ultrassônicas:

1. Envia um pulso sonoro
2. O som reflete em um objeto
3. O sinal retorna ao sensor
4. O tempo de retorno é convertido em distância

### Pinos

- **VCC** → 5V
- **GND** → Terra
- **TRIG** → Envio do pulso
- **ECHO** → Recebimento do pulso

---

## Sensor DHT11 (Temperatura e Umidade)

### Funcionamento

O DHT11 é um sensor digital que mede:

- Temperatura (°C)
- Umidade relativa do ar (%)

Ele envia os dados diretamente para o Arduino através de um único pino de comunicação.

### Pinos

- **VCC** → 5V
- **GND** → Terra
- **DATA** → Comunicação

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
