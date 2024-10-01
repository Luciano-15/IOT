# Projeto de Semáforo com Sensor de Distância

# Introdução

Este projeto foi desenvolvido no Tinkercad, como parte da disciplina de Internet
das Coisas (IoT), com o objetivo de criar um protótipo que simula um sistema de 
semáforo inteligente. O sistema é projetado para controlar os sinais de trânsito
destinados a veículos e pedestres, utilizando um sensor de distância para detectar
a presença de pedestres.

Foram implementados dois semáforos para veículos, equipados com LEDs nas cores
verde, amarelo e vermelho, considerando que cada pista possui um sentido de tráfego
distinto. Além disso, foram criados dois semáforos para pedestres, utilizando LEDs 
nas cores vermelha e verde, um para cada faixa.

No funcionamento do sistema, os semáforos dos veículos permanecem na cor verde até que
um pedestre se aproxime da faixa de travessia. Quando um pedestre se aproxima a uma 
distância de 50 cm, o sensor de distância é ativado, resultando na mudança imediata 
dos sinais dos veículos para vermelho. Durante um período de 15 segundos, os semáforos
para pedestres exibem a luz verde, permitindo a travessia segura.

Após o término desse intervalo, quando o sensor não detecta mais a presença de pedestres,
os sinais para pedestres se tornam vermelhos, e os semáforos dos veículos são novamente 
liberados para o tráfego.

# Componentes Usados


1 Arduino Uno
1 Placa de Ensaio
6 LEDs (Vermelho, Amarelo e Verde para dois semáforos de veículos)
4 LEDs (Vermelho e Verde para dois semáforos de pedestres)
1 Sensor de Distância (Ultrassônico)
14 Jumpers Macho-Macho
3 Jumpers Macho-Fêmea


# Montagem do Circuito

![Imagem do Circuito](semafaro1.png)

# Explicação do Código


 Definindo os pinos para os LEDs dos semáforos de carros
const int carRed1 = 4;     LED vermelho para o carro 1
const int carYellow1 = 3;  LED amarelo para o carro 1
const int carGreen1 = 2;   LED verde para o carro 1
const int carRed2 = 7;     LED vermelho para o carro 2
const int carYellow2 = 6;  LED amarelo para o carro 2
const int carGreen2 = 5;   LED verde para o carro 2

 Definindo os pinos para os LEDs dos semáforos de pedestres
const int pedestrianRed1 = 9;      LED vermelho para pedestre 1
const int pedestrianGreen1 = 8;    LED verde para pedestre 1
const int pedestrianRed2 = 11;     LED vermelho para pedestre 2
const int pedestrianGreen2 = 10;    LED verde para pedestre 2

 Definindo os pinos para o sensor de distância
const int trigPin = 12;  Pino de disparo do sensor
const int echoPin = 13;  Pino de eco do sensor

void setup() {
    Configurando os pinos dos LEDs dos carros como saída
  pinMode(carRed1, OUTPUT);
  pinMode(carYellow1, OUTPUT);
  pinMode(carGreen1, OUTPUT);
  pinMode(carRed2, OUTPUT);
  pinMode(carYellow2, OUTPUT);
  pinMode(carGreen2, OUTPUT);

 Configurando os pinos dos LEDs dos pedestres como saída
  pinMode(pedestrianRed1, OUTPUT);
  pinMode(pedestrianGreen1, OUTPUT);
  pinMode(pedestrianRed2, OUTPUT);
  pinMode(pedestrianGreen2, OUTPUT);

   Configurando os pinos do sensor de distância
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
 Inicia os semáforos de carros
  startCarSignals();
}

void loop() {
  long duration, distance;
  
   Ativando o sensor de distância
  digitalWrite(trigPin, LOW);  Baixa o pino do trigger
  delayMicroseconds(2);         Espera 2 microssegundos
  digitalWrite(trigPin, HIGH);  Ativa o pino do trigger
  delayMicroseconds(10);        Espera 10 microssegundos
  digitalWrite(trigPin, LOW);   Desativa o trigger
  
   Lê o tempo que o sinal leva para retornar
  duration = pulseIn(echoPin, HIGH);
  
   Calcula a distância em centímetros
  distance = (duration * 0.034) / 2;  (duração em microssegundos * 0.034 cm/µs) / 2

   Verifica se um pedestre está próximo
  if (distance < 50) {  Se a distância for menor que 50 cm
     Pedestre detectado
    stopCarSignals();          Para os sinais dos carros
    startPedestrianSignals();  Ativa os sinais dos pedestres
    delay(15000);              Espera 15 segundos
    stopPedestrianSignals();   Para os sinais dos pedestres
    startCarSignals();         Retorna os sinais dos carros
  }
}

 Função para iniciar os sinais dos carros
void startCarSignals() {
  digitalWrite(carRed1, LOW);    Verde para carro 1
  digitalWrite(carYellow1, LOW);  Amarelo para carro 1 desligado
  digitalWrite(carGreen1, HIGH);  Verde para carro 1 ligado
  digitalWrite(carRed2, LOW);     Verde para carro 2
  digitalWrite(carYellow2, LOW);  Amarelo para carro 2 desligado
  digitalWrite(carGreen2, HIGH);  Verde para carro 2 ligado
}

 Função para parar os sinais dos carros
void stopCarSignals() {
  digitalWrite(carRed1, HIGH);    Vermelho para carro 1
  digitalWrite(carYellow1, LOW);   Amarelo para carro 1 desligado
  digitalWrite(carGreen1, LOW);    Verde para carro 1 desligado
  digitalWrite(carRed2, HIGH);     Vermelho para carro 2
  digitalWrite(carYellow2, LOW);    Amarelo para carro 2 desligado
  digitalWrite(carGreen2, LOW);     Verde para carro 2 desligado
}

 Função para iniciar os sinais dos pedestres
void startPedestrianSignals() {
  digitalWrite(pedestrianRed1, LOW);   Verde para pedestre 1
  digitalWrite(pedestrianGreen1, HIGH);  Verde para pedestre 1 ligado
  digitalWrite(pedestrianRed2, LOW);     Verde para pedestre 2
  digitalWrite(pedestrianGreen2, HIGH);  Verde para pedestre 2 ligado
}

 Função para parar os sinais dos pedestres
void stopPedestrianSignals() {
  digitalWrite(pedestrianRed1, HIGH);   Vermelho para pedestre 1
  digitalWrite(pedestrianGreen1, LOW);  Verde para pedestre 1 desligado
  digitalWrite(pedestrianRed2, HIGH);    Vermelho para pedestre 2
  digitalWrite(pedestrianGreen2, LOW);   Verde para pedestre 2 desligado
}
