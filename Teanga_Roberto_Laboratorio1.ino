#include <TimerOne.h>
#include <MsTimer2.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
LiquidCrystal lcd(8,9,10,11,12,13); 
int Sec = 0;
int d=0;
int Min = 0;
int Hor = 0;
int hor2=0;
int min2=0;
int sec2=0;
int i =0;
int j=0;
int k=0;
int l=0;
int p=0;
char valor;
String estado;
//const int pinBuzzer = 4;
 
//const int tonos[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
//const int countTonos = 10;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
Timer1.initialize(1000000);
Timer1.attachInterrupt(contador2);
MsTimer2::set(1000,contador); // el sistema va a trabajar con un segundo
MsTimer2::start();
attachInterrupt(0,alarma,FALLING);
pinMode(7,INPUT);
pinMode(6,INPUT);
pinMode(5,OUTPUT);
pinMode(4,OUTPUT);

Hor=EEPROM.read(1);
Min=EEPROM.read(2);
}

void loop() {
 
  /*if(d==1){
  
  
  for (int iTono = 0; iTono < countTonos; iTono++)
  {
   tone(pinBuzzer, tonos[iTono]);
   delay(1000);
  }
  noTone(pinBuzzer);
}
 */
     while (Serial.available())
  {
    char c = Serial.read();  //Lee el dato entrante y lo almacena en una variable tipo char
    estado += c;  
    }
  if(digitalRead(7)== LOW){
  lcd.setCursor(0,1);
    lcd.print("Ingrese Hora ");
   Hor++;
   lcd.setCursor(14,1);
    lcd.print(Hor);
   delay(150);
  }
  
  if(digitalRead(6)== LOW){
  lcd.setCursor(0,1);
    lcd.print("Ingrese Min ");
   Min++; 
   lcd.setCursor(14,1);
    lcd.print(Min);
   delay(150);

  }


}

void contador()
{
    lcd.clear();
  if(Hor<10){

    lcd.setCursor(0, 0);
    lcd.print(0);
    lcd.setCursor(1,0);
    lcd.print(Hor);
   
  } 
  else{
    lcd.setCursor(0,0);
    lcd.print(Hor);
  }

  lcd.setCursor(2, 0);
  lcd.print(":");

  if(Min< 10){
    lcd.setCursor(3,0);
    lcd.print(0);
    lcd.setCursor(4,0);
    lcd.print(Min);
  }
  else{
    lcd.setCursor(3, 0);
    lcd.print(Min);
  }

  lcd.setCursor(5, 0);
  lcd.print(":");

  if(Sec< 10){
    lcd.setCursor(6,0);
    lcd.print(0);
    lcd.setCursor(7,0);
    lcd.print(Sec);
  }
  else{
    lcd.setCursor(6,0);
    lcd.print(Sec);
  }
 
  Sec++;
  EEPROM.write(1,Hor);
  EEPROM.write(2,Min);

    if(Sec == 60){
      Min++;
      Sec = 0;
       
  
    }
    if (Min == 60){
      Hor++;
      Min = 0;

    }
    if(Hor==24)
    {
      Hor=0;
      Min=0;
      Sec=0;   
      }

        
      if(EEPROM.read(4)<10)
      {

      lcd.setCursor(6,1);
    lcd.print(EEPROM.read(3));
      lcd.setCursor(8,1);
    lcd.print(":0");
     lcd.setCursor(10,1);
    lcd.print(EEPROM.read(4));
      }
      else
      {
      lcd.setCursor(6,1);
    lcd.print(EEPROM.read(3));
      lcd.setCursor(8,1);
    lcd.print(":");
     lcd.setCursor(9,1);
    lcd.print(EEPROM.read(4));
        }  
        
          
  }

  void alarma ()
  {
    i=1+i;
    delay(250);
    if(i==1)
    {
   Serial.println("Ingrese hora de la alarma");
    estado="";
    
    }
    if(i==2)
    {
      hor2=estado.toInt();
      Serial.println("");
      Serial.println("Ingrese minutos de la alarma");
       
    estado="";
    }
    if(i==3)
    {
      min2=estado.toInt();
      Serial.println("");
      Serial.println("la hora de la alarma es :");
      if(min2<10)
      {
      Serial.print(hor2);
      Serial.print(":");
      Serial.print("0");
      Serial.print(min2);
      }
      else
      {
        Serial.print(hor2);
      Serial.print(":");
      Serial.print(min2);
        }
      EEPROM.write(3,hor2);
    EEPROM.write(4,min2);
    }
    if(i==4)
    {
      Serial.println("");
      Serial.println("Alarma encendida");
   j=1;
   delay(1000);
   Serial.println("Presione una ves mas para apagar la alarma");
   }
   if(i==5)
   {
     Serial.println("Alarma apagada");
    j=0;
    i=0;
    p=0;
    k=0;
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    d=0;
     
    }
  }

  void contador2()
  {
    if(j==1)
    {
   if(EEPROM.read(1) == EEPROM.read(3))
   {
    if(EEPROM.read(2) == EEPROM.read(4))
   {
  p=1;
   }
  }
    }
    if(p==1){
   if(k<21 )
    {
  k++;
       digitalWrite(5,HIGH);
       digitalWrite(4,HIGH);
       p=1;
      }
      else
      {
       digitalWrite(5,LOW);
       digitalWrite(4,LOW);
       
      }
    if(l==60)
    {
        k=0;
        p=1;
     }
    if(l==60)
    {
       l=0;
    }
     l++;
    }    
  
 }

