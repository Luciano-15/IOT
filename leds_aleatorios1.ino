int R = 6; // porta vermelha
int G = 3; // porta verde
int B = 5; // porta azul

void setup()
{
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // geração de números aleatórios entre 0 e 255
  int v1 = random(0, 256);
  int v2 = random(0, 256);
  int v3 = random(0, 256);
  
  // controle das portas com PWM para variar a intensidade
  analogWrite(R, v1);  // valor aleatório de 0 a 255
  analogWrite(G, v2);  // valor aleatório de 0 a 255
  analogWrite(B, v3);  // valor aleatório de 0 a 255
  delay(50);           // espera 50 milissegundos
}

