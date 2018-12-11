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
char uno[5]={'1','2','3','4','5'};//miguel
char dos[5]={'6','7','8','9','9'};
char tres[5]={'A','B','C','D','1'};//paul
char cuatro[5]={'A','A','A','A','A'};
char admin[5]={'5','4','3','2','1'};//administrados
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

void setup() {
  // put your setup code here, to run once:
 pinMode(A,OUTPUT); // configuracion de pin
 pinMode(B,OUTPUT); // configuracion de pin
 pinMode(C,OUTPUT); // configuracion de pin
 pinMode(D,OUTPUT); // configuracion de pin
  pinMode(14,INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("SISTEMA ON ");
}


void loop() {
  // validacion de contaseñas cuanto el contado llega a cinco
if(cont==5&&mast==0){
        if(ing[0]==uno[0]&&ing[1]==uno[1]&&ing[2]==uno[2]&&ing[3]==uno[3]&&ing[4]==uno[4]){
        lcd.setCursor(0,1);
        lcd.print("     MIGUEL     ");    
        salida1++;  
      }
        if(ing[0]==dos[0]&&ing[1]==dos[1]&&ing[2]==dos[2]&&ing[3]==dos[3]&&ing[4]==dos[4]){
        lcd.setCursor(0,1);
        lcd.print("      PAUL      "); 
        salida1++;        
      }
        if(ing[0]==tres[0]&&ing[1]==tres[1]&&ing[2]==tres[2]&&ing[3]==tres[3]&&ing[4]==tres[4]){
        lcd.setCursor(0,1);
        lcd.print("      JUAN      ");
        salida1++;        
      }
        if(ing[0]==cuatro[0]&&ing[1]==cuatro[1]&&ing[2]==cuatro[2]&&ing[3]==cuatro[3]&&ing[4]==cuatro[4]){
        lcd.setCursor(0,1);
        lcd.print("    JONATHAN    ");  
        salida1++;       
      }
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
        lcd.print("SISTEMA ON");     
      }
      if(salida1==2){
          lcd.setCursor(0,0);
          lcd.print("SALIDA  ");
          salida1=0;
      }
      if(salida1==0){
        delay(600);
          lcd.setCursor(0,0);
          lcd.print("SISTEMA ON");
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
          lcd.print(" ENTRADA ");
          lcd.setCursor(0,1);
          lcd.print("                ");
      }
      }
if(digitalRead(14)==HIGH){
  delay(150)    ;
  contador(cont3);
  cont3++;
  if(cont>20)
  { 
    
    cont3=0;
    
    }
}

}


void contador (int j){
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
