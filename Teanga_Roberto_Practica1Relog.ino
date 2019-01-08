/*
 * Relog 
 * Nombre:Roberto Teanga 
 * Matteraia: Microprosesados 
 * Fecha: 08 de enero del 2019
 * 
 */
#include <MsTimer2.h>

#include <TimerOne.h>

#include <LiquidCrystal.h>


LiquidCrystal lcd(13, 12, 11, 10,9, 8); //Configuramos los pines 12=RS 11=E 5,4,3,2=pines de control
int pulsador1=6;          //Cargamos un 6 ena la variable "pulsador1"
int pulsador2=7;          //Cargamos un 7 en la variable "pulsador2"
int u_hora=0;             //Cargamos un 0 en la variable "u_hora"
int u_minuto=0;           //Cargamos un 0 en la variable "u_minuto"
int u_segundo=0;          //Cargamos un 0 en la variable "u_segundo"
int d_hora=0;             //Cargamos un 0 en la variable "d_hora"
int d_minuto=0;           //Cargamos un 0 en la variable "d_minuto"
int d_segundo=0;          //Cargamos un 0 en la variable "d_segundo"
int Au_hora=0;             //Cargamos un 0 en la variable "u_hora"
int Au_minuto=0;           //Cargamos un 0 en la variable "u_minuto"
int Au_segundo=0;          //Cargamos un 0 en la variable "u_segundo"
int Ad_hora=0;             //Cargamos un 0 en la variable "d_hora"
int Ad_minuto=0;           //Cargamos un 0 en la variable "d_minuto"
int Ad_segundo=0; 
unsigned long Atimer1=0;  
unsigned long Atimer2=0;
unsigned long timer1=0;  
unsigned long timer2=0;    //cargamos el tiempo alrama 
int pulsador3=8;           //Cargamos alarama 
void setup (){
  pinMode(pulsador1,INPUT);  //El pulsador 1 en el pin 6 es un pin de entrada
  pinMode(pulsador2,INPUT);  //El pulsador 2 en el pin 7 es un pin de entrada
  lcd.begin(16, 2);          //Configuramos los números de filas y de columnas del LCD
  lcd.clear();
  pinMode(speakerPin, OUTPUT);
  delay(250); 
  pinMode(pulsador3,INPUT); 
}


void loop()
{ 
  // programa principal 
  un_seg ();    //Va a la rutina un_seg
   
  contador();   //Va a la rutina contador
   
  escribe_hora();  //Va a la rutina escribe_hora
   
  set_hora();   //Va a la rutina set_hora

  
  // programa principal 
  Aun_seg ();    //Va a la rutina un_seg
   
  escribe_hora();  //Va a la rutina escribe_hora
   
  Aset_hora(); 
}

   
void un_seg(){    //Rutina para cada segundo
   
timer2=(millis()/1000);    
if ( timer1 != timer2 ) {
 timer1=timer2;
 u_segundo++;    // unidades de segundo se incrementa cada segundo       
 }     
}


 
   
void Aun_seg(){    //Rutina para cada segundo
   
Atimer2=(millis()/1000);    
if ( Atimer1 != Atimer2 ) {
 Atimer1=Atimer2;
 Au_segundo++;    // unidades de segundo se incrementa cada segundo       
 }     
}




void contador(){ // Rutina para el reloj
 
if ( u_segundo == 10 ) {
u_segundo =0;
d_segundo++;} 
 
if ( ( d_segundo == 6 ) && ( u_segundo == 0 ) ) {
d_segundo =0;
u_minuto++;} 
 
 
// Rutina de minutos
 
if ( u_minuto == 10 ) {
u_minuto =0;
d_minuto++; } 
 
if ( ( d_minuto == 6 ) && ( u_minuto == 0 ) ) {
d_minuto =0;     
u_hora++;} 
// Rutina de horas
 
if ( u_hora == 10 ) {
u_hora =0;
d_hora++; } 
 
if ( (d_hora == 2) &&  (u_hora == 4) ) {
u_hora =0; 
d_hora =0; } 
 
 
}





void contador2(){ // Rutina para el reloj alarma 
 
if ( Au_segundo == 10 ) {
Au_segundo =0;
Ad_segundo++;} 
 
if ( ( Ad_segundo == 6 ) && ( Au_segundo == 0 ) ) {
Ad_segundo =0;
Au_minuto++;} 
 
 
// Rutina de minutos
 
if ( Au_minuto == 10 ) {
Au_minuto =0;
Ad_minuto++; } 
 
if ( ( Ad_minuto == 6 ) && ( Au_minuto == 0 ) ) {
Ad_minuto =0;     
Au_hora++;} 


// Rutina de horas 
if ( Au_hora == 10 )
{
Au_hora =0;
Ad_hora++;
} 
 
if ( (Ad_hora == 2) &&  (Au_hora == 4) ) 
{
Au_hora =0; 
Ad_hora =0; 
} 
 
 
}





 void set_hora()
  
  {   
 //Rutina para poner el reloj en hora
    if(digitalRead(pulsador1)==LOW)    //Si el presionas el pulsador2
    {    
    u_minuto++;                        //Incrementa la variable "u_minuto" 1 unidad
    delay (250);                        //Pausa antirebote
    }
    if(digitalRead(pulsador2)==LOW)
    {    //Si el presionas el pulsador1
    u_hora++;                          //Incrementa la variable "u_hora" 1 unidad
    delay(250);                         //Pausa antirebote
    }

  }


void Aset_hora()
  
  {    //Rutina para poner el reloj en hora
  if(digitalRead(pulsador3)==LOW)
  {
  if(digitalRead(pulsador1)==LOW){    //Si el presionas el pulsador2
   Au_minuto++;                        //Incrementa la variable "u_minuto" 1 unidad
   delay (250);                        //Pausa antirebote
  }
  if(digitalRead(pulsador2)==LOW)
  {    //Si el presionas el pulsador1
   Au_hora++;                          //Incrementa la variable "u_hora" 1 unidad
   delay(250);                         //Pausa antirebote
  }
   }
    
   
}
   
   
  void escribe_hora()
  
  { //Rutina para escribir la hora en el LCD
     
  lcd.setCursor(0,0);  //Situa el cursor en la segunda posición de la primera línea
  lcd.print("Reloj"); //Escribe el texto entre comillas
  lcd.setCursor(7, 0);  //Situa el cursor en la cuarta posición de la segunda línea
  lcd.print(d_hora);    //Escribe la cantidad almacenada en la variable d_hora
  lcd.print(u_hora);    //Escribe la cantidad almacenada en la variable u_hora
  lcd.print(":");        //Escribe el texto entre comillas
  lcd.print(d_minuto);  //Escribe la cantidad almacenada en la variable d_minuto
  lcd.print(u_minuto);  //Escribe la cantidad almacenada en la variable u_minuto
  lcd.print(":");        //Escribe el texto entre comillas
  lcd.print(d_segundo);  //Escribe la cantidad almacenada en la variable d_segundo
  lcd.print(u_segundo);  //Escribe la cantidad almacenada en la variable u_segundo
  lcd.setCursor(0,1);
  lcd.print("Alarma"); 
   lcd.setCursor(7, 1);  //Situa el cursor en la cuarta posición de la segunda línea
  lcd.print(Ad_hora);    //Escribe la cantidad almacenada en la variable d_hora
  lcd.print(Au_hora);    //Escribe la cantidad almacenada en la variable u_hora
  lcd.print(":");        //Escribe el texto entre comillas
  lcd.print(Ad_minuto);  //Escribe la cantidad almacenada en la variable d_minuto
  lcd.print(Au_minuto);  //Escribe la cantidad almacenada en la variable u_minuto
  lcd.setCursor(0,1);
  
  
  }
   
