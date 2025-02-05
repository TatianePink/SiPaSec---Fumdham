# SiPaSec - Sistema de Sensoriamento com Arduino e ESP32

## Descrição do Projeto

O sistema de sensoriamento desenvolvido como parte do projeto de iniciação tecnológica na **FAETERJ Petrópolis**, sob a orientação do **Doutor Alberto Torres Angonese**. O projeto utiliza um **Arduino Uno** com o sensor **DHT22** para coletar dados de temperatura e umidade, e um **ESP32** para realizar a comunicação Wi-Fi e hospedar os dados na plataforma **Tago.io**.

O objetivo principal do projeto é monitorar e visualizar em tempo real as condições ambientais, como temperatura e umidade, através de uma interface web hospedada no Tago.io.

## Componentes Utilizados

- **Arduino Uno**: Microcontrolador principal para leitura dos dados do sensor.
- **Sensor DHT22**: Sensor de temperatura e umidade.
- **ESP32**: Módulo Wi-Fi para comunicação com a internet e envio dos dados para o Tago.io.
- **Tago.io**: Plataforma IoT para armazenamento e visualização dos dados.

## Funcionalidades

- Leitura de temperatura e umidade ambiente.
- Transmissão dos dados via Wi-Fi utilizando o ESP32.
- Hospedagem e visualização dos dados em tempo real no Tago.io.

## Diagrama de Blocos

```plaintext
+-------------------+       +-------------------+       +-------------------+
|                   |       |                   |       |                   |
|  Arduino Uno      |<----->|  ESP32            |<----->|  Tago.io          |
|  (DHT22 Sensor)   |       |  (Wi-Fi Module)   |       |  (Cloud Platform) |
|                   |       |                   |       |                   |
+-------------------+       +-------------------+       +-------------------+

