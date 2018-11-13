/* 
 *  COMUNICACION SERTIAL ENVIO Y RECICION DE DATOS 
 *  Configuaracion------->Serial.begin(Velocidad)
 *  
 *  Enviar dato------->Seria.print(dato)  // sin avance de linea 
 *                     Serial.println(dato)   // con avance de linea 
 *  
 *  Recibir dato------> Serial.aviable()   /// confirmar si hay dato de entrada 
 *                      Seria.read()       //leemos el dato de entrada 
 *                      Serial,readString()//leer caddena de texto 
 */

 #include<stdlib.h>    //------->
 int j=0; 
int i=0; 
char dato; 
int leds[6]={13,12,11,10,9,8};
String str; 
int tam; 
int numero; 
void setup()

{
  Serial.begin(9600); 
  for(;i<6;i++)
  {
    pinMode(leds[i],OUTPUT); 

   
  }
i=0; 
}


void loop() 
{
     if(Serial.available()>0)
    {
      str=Serial.readString(); //recive en caracteres 

       tam=str.length(); 
       //Serial.println(tam); 
       char vector[tam]; 
       str.toCharArray(vector,tam+1); 
       dato=vector[1]; 
       numero=atoi(&dato); 
       numero=numero*2; 
       Serial.println(numero); 

       
    }
    
i=0; 


  //ENVIO DE DATOS 
  //Enviar lo que se recibe 

  if(Serial.available()>0)
  {
    dato=Serial.read(); 
    delay(50); 
    Serial.println(dato); //Serial.println(dato,tipo)----->Hexa
                                                          //decimal 
                                                          //octal
  }

 
  for(;i<20;i++) 
  {
    Serial.print("CONTADOR:"); 
    Serial.println(i); 
    delay(300); 
  }
    i=0;
 



 
}
