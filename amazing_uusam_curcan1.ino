// Definição dos pinos
const int ledCarroVerde1 = 2;
const int ledCarroAmarelo1 = 3;
const int ledCarroVermelho1 = 4;
const int ledCarroVerde2 = 5;
const int ledCarroAmarelo2 = 6;
const int ledCarroVermelho2 = 7;
const int ledPedestreVerde1 = 8;
const int ledPedestreVermelho1 = 9;
const int ledPedestreVerde2 = 10;
const int ledPedestreVermelho2 = 11;
const int trigPin = 12;
const int echoPin = 13;

void setup() {
    // Configuração dos pinos como saída
    pinMode(ledCarroVerde1, OUTPUT);
    pinMode(ledCarroAmarelo1, OUTPUT);
    pinMode(ledCarroVermelho1, OUTPUT);
    pinMode(ledCarroVerde2, OUTPUT);
    pinMode(ledCarroAmarelo2, OUTPUT);
    pinMode(ledCarroVermelho2, OUTPUT);
    pinMode(ledPedestreVerde1, OUTPUT);
    pinMode(ledPedestreVermelho1, OUTPUT);
    pinMode(ledPedestreVerde2, OUTPUT);
    pinMode(ledPedestreVermelho2, OUTPUT);
    
    // Configuração dos pinos do sensor de distância
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    
    // Inicializa os semáforos
    iniciarSemaforos();
}

void loop() {
    long duration, distance;
    
    // Aciona o sensor de distância
    digitalWrite(trigPin, LOW);
    delay(2);
    digitalWrite(trigPin, HIGH);
    delay(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);
    distance = (duration * 0.034) / 2; // em cm

    if (distance <= 50) { // Se um pedestre está a 50 cm da faixa
        // Troca para sinal vermelho para carros
        semaforosCarroVermelho();
        // Sinais de pedestres ficam verdes
        semaforosPedestreVerde();
        delay(15000); // Aguarda 15 segundos
        
        // Verifica se o pedestre saiu da faixa
        if (verificaPedestreSaindo()) {
            semaforosPedestreVermelho();
            iniciarSemaforos();
        }
    }
}

void iniciarSemaforos() {
    digitalWrite(ledCarroVerde1, HIGH);
    digitalWrite(ledCarroAmarelo1, LOW);
    digitalWrite(ledCarroVermelho1, LOW);
    digitalWrite(ledCarroVerde2, HIGH);
    digitalWrite(ledCarroAmarelo2, LOW);
    digitalWrite(ledCarroVermelho2, LOW);
    
    digitalWrite(ledPedestreVerde1, LOW);
    digitalWrite(ledPedestreVermelho1, HIGH);
    digitalWrite(ledPedestreVerde2, LOW);
    digitalWrite(ledPedestreVermelho2, HIGH);
}

void semaforosCarroVermelho() {
    digitalWrite(ledCarroVerde1, LOW);
    digitalWrite(ledCarroAmarelo1, LOW);
    digitalWrite(ledCarroVermelho1, HIGH);
    digitalWrite(ledCarroVerde2, LOW);
    digitalWrite(ledCarroAmarelo2, LOW);
    digitalWrite(ledCarroVermelho2, HIGH);
}

void semaforosPedestreVerde() {
    digitalWrite(ledPedestreVerde1, HIGH);
    digitalWrite(ledPedestreVermelho1, LOW);
    digitalWrite(ledPedestreVerde2, HIGH);
    digitalWrite(ledPedestreVermelho2, LOW);
}

void semaforosPedestreVermelho() {
    digitalWrite(ledPedestreVerde1, LOW);
    digitalWrite(ledPedestreVermelho1, HIGH);
    digitalWrite(ledPedestreVerde2, LOW);
    digitalWrite(ledPedestreVermelho2, HIGH);
}

bool verificaPedestreSaindo() {
    long duration, distance;
    
    // Aguardar um tempo para verificar se não há pedestre
    for (int i = 0; i < 5; i++) {
        digitalWrite(trigPin, LOW);
        delay(2);
        digitalWrite(trigPin, HIGH);
        delay(10);
        digitalWrite(trigPin, LOW);
        
        duration = pulseIn(echoPin, HIGH);
        distance = (duration * 0.034) / 2;
        
        if (distance <= 50) {
            return false; // Se o pedestre ainda está presente
        }
        delay(2000); // Aguarda 2 segundos antes da próxima verificação
    }
    return true; // Se não detectar pedestre
}
