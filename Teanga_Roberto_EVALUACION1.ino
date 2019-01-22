/*
 * EVALUACION DE MICROS
 * NOMBRE:ROBERTO TEANGA
 * FECHA: 22 DE ENERO DEL 2019
 */



#include <EEPROM.h>
int pulsador1=10;//A
int pulsador3 = 12;//C
int pulsador4 = 13;//D
int ledcorrect = 7;
int ledincorrect = 6;
int contrasea[5] = {10,12,13,10,10};//{A,C,D,A,A}
int contrasea1[5] = {};
int posicion = 0;
int p1  =10;
int p3  =12;
int p4  =13;
int i=0;

 int       salida1=0;
 int       mast=0;
 int       cont2=0;
 int       cont=0;
 int       id;
 char      nueva[5]={};

 long randomNumber;
       

void setup() {
Serial.begin(9600);
pinMode(pulsador1, INPUT);
pinMode(pulsador3, INPUT);
pinMode(pulsador4, INPUT);
pinMode (ledcorrect, OUTPUT);
pinMode (ledincorrect, OUTPUT);
randomSeed(analogRead(pulsador1));
randomSeed(analogRead(pulsador3));
randomSeed(analogRead(pulsador4));
attachInterrupt(1,on,FALLING);//on off sistema
Serial.println("Ingrese su contrasena");
p1=EEPROM.read(1);
p3=EEPROM.read(2);
p4=EEPROM.read(2);
}
void loop()
{
 conta(); 
 validacion();
 EEPROM.write(contrasea1[0],5);
 EEPROM.write(contrasea1[1],6);
 EEPROM.write(contrasea1[2],7);
 EEPROM.write(contrasea1[3],8);
 EEPROM.write(contrasea1[4],9);
 

}
void conta()
{
  
if (digitalRead(pulsador1) == HIGH) {
contrasea1[posicion] = p1;
posicion++;
delay(500);
}

if (digitalRead(pulsador3) == HIGH) {
contrasea1[posicion] = p3;
posicion++;
delay(500);
}
if (digitalRead(pulsador4) == HIGH) {
contrasea1[posicion] = p4;
posicion++;
delay(500);
}
  EEPROM.write(1,p1);
  EEPROM.write(2,p3);
  EEPROM.write(3,p4); 
  
}

void on(){
   i=1-i;
   if(i==1){
   Serial.println("SITEMA ON"); 
   delay(250);}
   else{
   Serial.println("SISTEMA OFF");
    delay(250);
   }
   
}
void validacion()
{
  if (posicion == 5) {
if ((contrasea[0] == contrasea1[0]) && (contrasea[1] == contrasea1[1]) && (contrasea[2] == contrasea1[2] && (contrasea[3] == contrasea1[3])&& (contrasea[4] == contrasea1[4])))

{
digitalWrite(ledcorrect, HIGH);
delay(1500);
Serial.println("contrasena correcta");
delay(1500);

}
else 
{
 digitalWrite(ledincorrect,HIGH); 
 Serial.println("Contrasena erronea");
 delay(1500);

    }

}

char key=0;
   
    if(key&&mast==1){   
      if(i==0){
          switch (key)     {
            case '1':
            id=1;
            i=1;
            break;
                
            }
      }
    }
    if(key&&mast==1&&i==1){


    randomNumber = random(0,2);
         
          Serial.println("NUEVA CONTRASENA");
          
          Serial.print(key);
            nueva[cont2]=key;
            cont2++;
        if(cont2==6&&mast==1){
          if(id==1){
            contrasea1[0]=nueva[randomNumber];
            contrasea1[1]=nueva[randomNumber];
            contrasea1[2]=nueva[randomNumber];
            contrasea1[3]=nueva[randomNumber];
            contrasea1[4]=nueva[randomNumber];
            }
            
        salida1=0;
        mast=0;
        cont2=0;
        cont=0;
        i=0;
    
  }
 }
}

