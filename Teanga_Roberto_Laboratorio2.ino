#include <TimerOne.h>
#include <MsTimer2.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
 
int Sec = 0;
int d=0;
int Min = 0;
int Hor = 0;
int hor2=0;
int min2=0;
int sec2=0;

int j=0;
int k=0;
int l=0;
int p=0;
char valor;
String estado;




#include<Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 8, 7, 6, 5);
int A=15; // pin de salida para display
int B=16; // pin de salida para display
int C=17; // pin de salida para display
int D=18; // pin de salida para display
const byte ROWS=4; //NUMERO DE FILAS
const byte COLS=4; //numero de columnas
int cont=0;
int cont2=0;
int cont3=0;
int i=0;
int id;
int salida1=0;
int mast=0;
//contaseñas
char uno[5]={'1','2','3','4','5'};
char dos[5]={'A','B','C','D','1'};
char tres[5]={'9','8','7','6','5'};
char cuatro[5]={'A','1','A','1','A'};
char admin[5]={'A','D','1','2','3'};
char ing[5]={};
char nueva[6]={};
int num2=0;
int vector2;
//teclado
char keys [ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS]={3,2,1,0};//ASIGNACION DE PINES PARA LAS FILAS
byte colPins[COLS]={13,10,9,4};
Keypad keypad =Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);  //ASIGNACION DE NOMBRE


//const int pinBuzzer = 4;
 
//const int tonos[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
//const int countTonos = 10;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
Serial.begin(9600);
Timer1.initialize(1000000);
Timer1.attachInterrupt(contador2);
MsTimer2::set(1000,contado); // el sistema va a trabajar con un segundo
MsTimer2::start();
//attachInterrupt(0,alarma,FALLING);

pinMode(A,OUTPUT); // configuracion de pin
 pinMode(B,OUTPUT); // configuracion de pin
 pinMode(C,OUTPUT); // configuracion de pin
 pinMode(D,OUTPUT); // configuracion de pin

Hor=EEPROM.read(1);
Min=EEPROM.read(2);


 pinMode(14,INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("ENCENDIDO");
}

void loop() {

////////////////////////////////////////////////////////////////////////////////////////////
if(cont==1&&mast==0){
 
        if(ing[0]==admin[0]&&ing[1]==admin[1]&&ing[2]==admin[2]&&ing[3]==admin[3]&&ing[4]==admin[4]){
        mast=1;
        salida1=3;
        lcd.setCursor(0,1);
        lcd.print("     ADMIN      ");  
        delay(600)    ;
          lcd.setCursor(0,0);
          lcd.print(" ID USUARIO:  ");
         lcd.setCursor(0,1);
        lcd.print("                ");   
          lcd.setCursor(0,0);
        lcd.print("   BIENBENIDO   ");     
      }
      if(salida1==2){
          lcd.setCursor(0,0);
          lcd.print("  HASTA LUEGO ");
          salida1=0;
      }
      if(salida1==0){
        delay(600);
          lcd.setCursor(0,0);
          lcd.print("  BIENBENIDO ");
         lcd.setCursor(0,1);
        lcd.print("               ");         
        }
        cont=0;
     }
char key= keypad.getKey();

//ingeso x medio del teclado pa los empleados
  if(key&&mast==0){
    lcd.setCursor(cont,1);
    lcd.print(key);
    delay(100);
    lcd.setCursor(cont,1);
    lcd.print('*');
    ing[cont]=key;
    cont++;   
    }

    //ingeso x medio del teclado pa el admin
    if(key&&mast==1){   
      if(i==0){
          switch (key)     {
            case '1':
            id=1;
            i=1;
            break;
            case '2':
            id=2;
            i=1;
            break;
            case '3':
            id=3;
            i=1;
            break;
            case '4':
            id=4;
            i=1;
            break;     
            }
      }
    }
    if(key&&mast==1&&i==1){
          lcd.setCursor(0,0);
          lcd.print("NUEVA CONTRASENA");
          lcd.setCursor(cont2,1);
          lcd.print(key);
            nueva[cont2]=key;
            cont2++;
        if(cont2==6&&mast==1){
          if(id==1){
            uno[0]=nueva[1];
            uno[1]=nueva[2];
            uno[2]=nueva[3];
            uno[3]=nueva[4];
            uno[4]=nueva[5];
            }
            if(id==2){
            dos[0]=nueva[1];
            dos[1]=nueva[2];
            dos[2]=nueva[3];
            dos[3]=nueva[4];
            dos[4]=nueva[5];
            }
            if(id==3){
            tres[0]=nueva[1];
            tres[1]=nueva[2];
            tres[2]=nueva[3];
            tres[3]=nueva[4];
            tres[4]=nueva[5];
            }
            if(id==4){
            cuatro[0]=nueva[1];
            cuatro[1]=nueva[2];
            cuatro[2]=nueva[3];
            cuatro[3]=nueva[4];
            cuatro[4]=nueva[5];
            }
        salida1=0;
        mast=0;
        cont2=0;
        cont=0;
        i=0;
          lcd.setCursor(0,0);
          lcd.print("   BIENBENIDO   ");
          lcd.setCursor(0,1);
          lcd.print("                ");
      }
      }
if(digitalRead(14)==HIGH){
  delay(1000)    ;
  contador(cont3);
  cont3++;
  if(cont>=9){
    cont3=0;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



 
     while (Serial.available())
  {
    char c = Serial.read();  //Lee el dato entrante y lo almacena en una variable tipo char
    estado += c;  
    }
  /*if(digitalRead(7)== LOW){
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
*/

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void contado()
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

 /* void alarma ()
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
*/
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

void contador (int j){



/////////////////////////////////////////////
switch(j){
  //0
  case 0:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//1
 case 1:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//2
case 2:
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//3
case 3:
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//4
case 4:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//5
case 5:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//6
case 6:
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//7
case 7:
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//8
case 8:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
//9
case 9:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
}
}
