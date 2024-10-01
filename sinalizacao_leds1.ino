// Definindo os pinos dos LEDs
const int ledVerde1 = 2;
const int ledVerde2 = 3;
const int ledVermelho1 = 4;
const int ledVermelho2 = 5;
const int ledAzul1 = 6;
const int ledAzul2 = 7;

void setup() {
  // Configurando os pinos como saída
  pinMode(ledVerde1, OUTPUT);
  pinMode(ledVerde2, OUTPUT);
  pinMode(ledVermelho1, OUTPUT);
  pinMode(ledVermelho2, OUTPUT);
  pinMode(ledAzul1, OUTPUT);
  pinMode(ledAzul2, OUTPUT);
}

void loop() {
  // Primeiro momento: 1 Verde, 1 Vermelho, 1 Azul
  digitalWrite(ledVerde1, HIGH);
  digitalWrite(ledVermelho1, HIGH);
  digitalWrite(ledAzul1, HIGH);
  delay(2000); // Mantém aceso por 2 segundos
  digitalWrite(ledVerde1, LOW);
  digitalWrite(ledVermelho1, LOW);
  digitalWrite(ledAzul1, LOW);
  delay(500); // Pausa

  // Segundo momento: 2 Verdes e 2 Azuis
  digitalWrite(ledVerde1, HIGH);
  digitalWrite(ledVerde2, HIGH);
  digitalWrite(ledAzul1, HIGH);
  digitalWrite(ledAzul2, HIGH);
  delay(2000); // Mantém aceso por 2 segundos
  digitalWrite(ledVerde1, LOW);
  digitalWrite(ledVerde2, LOW);
  digitalWrite(ledAzul1, LOW);
  digitalWrite(ledAzul2, LOW);
  delay(500); // Pausa

  // Terceiro momento: 1 Verde, 2 Vermelhos e 1 Azul
  digitalWrite(ledVerde1, HIGH);
  digitalWrite(ledVermelho1, HIGH);
  digitalWrite(ledVermelho2, HIGH);
  digitalWrite(ledAzul1, HIGH);
  delay(2000); // Mantém aceso por 2 segundos
  digitalWrite(ledVerde1, LOW);
  digitalWrite(ledVermelho1, LOW);
  digitalWrite(ledVermelho2, LOW);
  digitalWrite(ledAzul1, LOW);
  delay(500); // Pausa
}
