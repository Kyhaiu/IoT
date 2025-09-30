# Aula Arduino – LCD, LED RGB e Sensor Ultrassônico

Este repositório contém os exemplos práticos utilizados em aula para trabalhar com **LCD 16x2 (I2C)**, **LED RGB**, **botões** e **sensor ultrassônico HC-SR04**.

---

## Exercícios

## Exercícios - LED RGB

1. **LED RGB – cores básicas**  
   Acender as luzes RGB e fazer com que elas **troquem de cor automaticamente**, explorando combinações de cores e pinos PWM.

2. **Controle do LED RGB com potenciômetros**  
   Cada potenciômetro controla uma cor (vermelho, verde ou azul), permitindo **misturar cores manualmente** no LED RGB.

## Exercícios - LCD 1602

3. **Escrever mensagens no LCD 16x2**  
   Vamos mostrar a mensagem **"Hello, World!"** no LCD e aprender a posicionar o texto em diferentes linhas, explorando comandos da biblioteca I2C.

4. **Sistema de alerta**  
   O sensor **HC-SR04** irá medir a distância de um objeto.

   - O **LCD** exibirá: “Muito perto!” ou “Muito longe”.
   - O **LED RGB** mudará de cor: **vermelho** quando o objeto estiver perto e **azul** quando estiver longe.

5. **Menu LCD com botão**  
   Vamos criar um **menu interativo** no LCD, alternando informações ao pressionar um botão:
   - Distância medida pelo sensor.
   - Valores RGB exibidos no LCD e refletidos no LED RGB.

---

## 📚 Bibliotecas utilizadas

- [`LiquidCrystal_I2C`](https://github.com/markub3327/LiquidCrystal_I2C) – controle simplificado do LCD via I2C.

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
