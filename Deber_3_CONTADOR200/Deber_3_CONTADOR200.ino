/*
 * Multiplexacion de displays y contadores
 * Deber 3 contador 200
 * Nombre:Roberto Teanga 
 * Fecha 06/11/2018
 */

int A=5; // pin de salida para display
int B=4; // pin de salida para display
int C=3; // pin de salida para display
int D=2; // pin de salida para display
int b1=6; // pin de entrada para pulsador
int i=0;  // variable de conteo
int dec=9; // pin de acitivacion de display decenas
int uni=8;  // pin de activacion unidades
int cen=10; 
int decenas; // variable de almacenamiento de decenas
int unidades; // variable de almacenamiento de unidades
int centenas; 
void setup(){
 pinMode(A,OUTPUT); // configuracion de pin
 pinMode(B,OUTPUT); // configuracion de pin
 pinMode(C,OUTPUT); // configuracion de pin
 pinMode(D,OUTPUT); // configuracion de pin
 pinMode(b1,INPUT);  // configuracion de pin
pinMode(dec,OUTPUT); // configuracion de pin
pinMode(uni,OUTPUT); // configuracion de pin
pinMode(cen,OUTPUT); 
}

void loop(){

  
   if(i<200){     // limite de conteo
     i++;       // aumento de variable
     decenas=i/10;  // valor de decenas
     unidades= i-(decenas*10); // valor unidades
     centenas=decenas/10; 
     decenas=decenas-(centenas*10) ;    
    
    
    
    }
   else{
    i=0; // reset conteo
    unidades=0; // reset unidades
    decenas=0;  // reset decenas
    centenas=0; 
   }
  
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

 digitalWrite(uni,LOW);   // desactivacion de pin de unidades
 digitalWrite(dec,LOW);// activacion de pin de decenas
 digitalWrite(cen,HIGH); 
 contador(centenas);  // llamo metodo de visualizacion
 delay(150); // espero
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
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
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
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
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
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,HIGH);
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
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,HIGH);
break;
//8
case 8:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
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
