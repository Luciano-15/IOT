// Biblioteca do LCD
#include <LiquidCrystal.h>

// Criar variável do LCD
LiquidCrystal lcd(2, 3, 4, 9, 10, 11);

// Pino do LED do LCD
int ledLcd = 13;

// Método para capturar a distância
long distancia(int trigger, int echo) {
  pinMode(trigger, OUTPUT); // definir porta de saída
  digitalWrite(trigger, LOW); // desligar porta
  delay(2); // espera 2 milissegundos
  digitalWrite(trigger, HIGH); // enviando sinal
  delay(10); // espera 10 milissegundos
  digitalWrite(trigger, LOW); // desligar porta
  pinMode(echo, INPUT); // definir porta de entrada
  return pulseIn(echo, HIGH); // retorna os dados que a porta recebe
}

void setup() {
  pinMode(ledLcd, OUTPUT); // Definir ledLcd como saída
  digitalWrite(ledLcd, HIGH); // Ligar os LEDs do LCD
  lcd.begin(16, 2); // Informar que o LCD tem 16 colunas e 2 linhas
  lcd.clear(); // Iniciar o LCD limpo
}

void loop() {
  long duration = distancia(8, 7); // Ajuste os pinos conforme necessário
  int cm = duration * 0.034 / 2; // Calcular a distância em cm
  
  lcd.clear(); // Limpa o LCD a cada loop
  if (cm < 100 && cm > 0) { // se menor que 1 metro e maior que 0 cm
    lcd.setCursor(0, 0); // Primeira linha
    lcd.print("MANTENHA");
    lcd.setCursor(0, 1); // Segunda linha
    lcd.print("DISTANCIA");
  }
  delay(100); // Aguarda 100 milissegundos antes da próxima leitura
}
