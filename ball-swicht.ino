// Open Source

#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

int led_pin_Verm = 8; // Define the LED interface
int led_pin_Verd = 9; // Define the LED interface
int switch_pin = 13; // Definition of mercury tilt switch sensor interface
int val; // Defines a numeric variable

void setup()
{
  pinMode(led_pin_Verm, OUTPUT);
  pinMode(led_pin_Verd, OUTPUT);
  pinMode(switch_pin, INPUT);
  Serial.begin(9600);
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
}

void loop()
{
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("CHAVE D MERCURIO");
  Serial.println("Chave de Mercurio");
 
  val = digitalRead(switch_pin); // check mercury switch state
  if(val == HIGH)
  {
    digitalWrite(led_pin_Verm, HIGH);
    digitalWrite(led_pin_Verd, LOW);
    lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
    lcd.print("CHAVE ABERTA   ");
    Serial.println("Chave Aberta");
  }
  else
  {
    digitalWrite(led_pin_Verm, LOW);
    digitalWrite(led_pin_Verd, HIGH);
    lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
    lcd.print("CHAVE FECHADA  ");
    Serial.println("Chave Fechada");
  }
}
