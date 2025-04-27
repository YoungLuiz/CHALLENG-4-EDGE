# Projeto TotemAI - Detecção de Gesto com Arduino Uno, TagoIO e Node-RED

## Objetivo

Este projeto tem como objetivo ilustrar uma aplicação de **Edge Computing** no contexto hospitalar.  
O **TotemAI** detecta gestos sem toque através de sensores para abrir menus de triagem, otimizando tempo de atendimento e reduzindo filas no Hospital Sabará.

---

## Funcionamento

- **IoT**: Um **Arduino Uno** lê os dados de um sensor ultrassônico (HC-SR04) para detectar a aproximação da mão do usuário.
- **Back-end**: Quando um gesto é detectado (mão a menos de 15 cm), o Arduino envia um sinal para a plataforma **TagoIO**.
- **Aplicação**: O **Node-RED** consome os dados do TagoIO, processa e exibe a informação para o sistema hospitalar, simulando a abertura de um menu de atendimento.

---

## Tecnologias Utilizadas

- **Arduino Uno**
- **Sensor Ultrassônico HC-SR04**
- **TagoIO** (Plataforma IoT para gerenciamento de dados)
- **Node-RED** (Orquestração de fluxos e visualização)
- **Wokwi** (Simulação online do Arduino Uno)

---

## 🔌 Esquema de Conexão

- HC-SR04 VCC → 5V Arduino
- HC-SR04 GND → GND Arduino
- HC-SR04 Trig → Pino 9 Arduino
- HC-SR04 Echo → Pino 10 Arduino

---
## Fluxo do Sistema
Sensor detecta gesto.

Arduino envia sinal para o TagoIO.

Node-RED lê o sinal e aciona a abertura de um menu ilustrativo.

---
## Demonstração

A simulação foi realizada no Wokwi e demonstra o sensor detectando o gesto.
O fluxo de dados é representado via TagoIO e Node-RED de maneira ilustrativa.
