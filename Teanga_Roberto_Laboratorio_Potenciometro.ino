
float Potenciometro=A0; 
String lectura; 
//float mv; 
float leer;
int mvs;
int A=6; // pin de salida para display
int B=5; // pin de salida para display
int C=4; // pin de salida para display
int D=3; // pin de salida para display

int b1=2; // pin de entrada para pulsador

int i=0;  // variable de conteo
int dec=8; // pin de acitivacion de display decenas
int uni=9;  // pin de activacion unidades
int cen=10; 
int decenas; // variable de almacenamiento de decenas
int unidades; // variable de almacenamiento de unidades
//int centenas;
String dato; 
int datos; 
float mv;
int estado=LOW; 

//int estado=LOW;
 
void setup()
{
  Serial.begin(9600); 
   pinMode(Potenciometro,INPUT); 
 
 pinMode(A,OUTPUT); // configuracion de pin
 pinMode(B,OUTPUT); // configuracion de pin
 pinMode(C,OUTPUT); // configuracion de pin
 pinMode(D,OUTPUT); // configuracion de pin
 pinMode(b1,INPUT);  // configuracion de pin
pinMode(dec,OUTPUT); // configuracion de pin
pinMode(uni,OUTPUT); // configuracion de pin
pinMode(cen,OUTPUT); 

attachInterrupt(0, estado, FALLING);
}

void loop()
{

if(digitalRead(b1)==HIGH){  // condicion de activacion de boton
     delay(100);
  estado=digitalRead(b1); 
  digitalWrite(b1,estado);
  
    
    Serial.println("SISTEMA ON:");   
    Serial.println("SU VOLTAGE"); 
  
  
  if (Serial.available()>0)
{
  dato=Serial.readString(); 
  datos=dato.toInt(); 
}
    lectura=analogRead(Potenciometro);
    leer=lectura.toInt(); 
    mv=(leer*5)/1023;
    mvs=mv*10;
    Serial.print(leer); 
    Serial.print("     mv:    "); 
    Serial.print(Potenciometro); 
    Serial.println();   

     //if(mv<datos)
         // limite de conteo
      //{        // aumento de variable
        decenas=mvs/10;  // valor de decenas
        unidades= mvs-(decenas*10); // valor unidades 
      //}    
      
     if(datos>=mv)
      {
      digitalWrite(uni,HIGH); // activacion de pin de unidades
      digitalWrite(dec,LOW);  // desactivacion de pin de decenas
      digitalWrite(cen,LOW); 
      contador(unidades);    // llamo metodo de visualizacion
      delay(200);  //           espero
      digitalWrite(uni,LOW);   // desactivacion de pin de unidades
      digitalWrite(dec,HIGH);// activacion de pin de decenas
      digitalWrite(cen,LOW); 
      contador(decenas);  // llamo metodo de visualizacion
      delay(150); // espero

  }

}
if(digitalRead(b1)==LOW){  // condicion de activacion de boton
  
    
    Serial.println("SISTEma OFF");   
     
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
