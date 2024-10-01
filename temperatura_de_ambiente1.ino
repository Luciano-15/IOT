// BILBIOTECA LCD COMMODULO I2C
#include <LiquidCrystal_I2C.h>

// INICIALIZANDO LCD
LiquidCrystal_I2C telalcd(0x20, 16, 2);

// VARIAVEL DO SENSOR DE TEMPERATURA
int sensorTMP = A0;
// capturar temperatura
int valorLido;

void setup()
{
  // definir o sensor como entrada
  pinMode(sensorTMP, INPUT);
  // ligar a tela lcd
  telalcd.init();
  // limpar os dados os que aparecem
  telalcd.clear();
  // aumentar a luminosidade do lcd
   telalcd.backlight();
  
}

void loop()
{
  // capturar o valor da temperatura
  valorLido = analogRead(sensorTMP);
  // converter valor de tensão
  float tensao = (valorLido * 5.0) / 1024.0;
  // calcular a temperatura
  float temperatura = (tensao - 0.5) * 100;
 
  // imprimir título "Temperatura" no LCD
  telalcd.setCursor(0, 0);
  telalcd.print("Temperatura"); // Adicionei o título

  // imprimir valor da temperatura no LCD
  telalcd.setCursor(0, 1);
   telalcd.print(temperatura);
  telalcd.print(" C");
}