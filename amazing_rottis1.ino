#include <Servo.h>

Servo microServo; // Cria um objeto servo

int led = 0; // Pino do LED vermelho
int servo = 2; // Pino do servo
int posicao = 0;

long distancia(int trigger, int echo) {
  // Trigger como pino de saída
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, LOW);
  delay(5); // Espera 5 milissegundos
  digitalWrite(trigger, HIGH);
  delay(10); // Envia o pulso
  digitalWrite(trigger, LOW);

  // Echo como pino de entrada
  pinMode(echo, INPUT);
  
  return pulseIn(echo, HIGH); // Corrigido: pulseln -> pulseIn
}

void setup() {
  // Inicializando o servo na porta digital
  microServo.attach(servo);
  
  pinMode(led, OUTPUT); // Corrigido: fechando o parêntese
  microServo.write(posicao);
}

void loop() {
  int cm = 0.1723 * distancia(1, 1); // Ajuste para os pinos corretos
  
  if (cm < 30) {
    // Mandar o motor para a nova posição
    posicao = posicao + 5;
    microServo.write(posicao);
    digitalWrite(led, HIGH);
    delay(100);
  } else {
    digitalWrite(led, LOW);
  }
}
