/*
 * Puertos como salida
 * Nombre:Roberto Teanga 
 * Deber:juego luces 

 */
int leds[6]={8,9,10,11,12,13}; // defino vector para configurar leds
int i=0; // variable de recorrido del vector
int j=5; // variable de recorrido del vector 
int numero=0; //el contador inicia en 0
int a=0; 
int b=0; 
int c=0; 
int d=0; 
int e=0;
int f=0;  

void setup() {

  pinMode(7,INPUT); 
  pinMode(6,INPUT); 
  pinMode(5,INPUT); 
  pinMode(4,INPUT); 
  pinMode(3,INPUT); 
  pinMode(2,INPUT); 
  pinMode(1,INPUT); 
  
  
  // configuracion de pines de forma grupal
  for(;i<6;i++){
     pinMode(leds[i],OUTPUT);
    }
    i=0;  // reseteo la variable de conteo


    pinMode(A0, OUTPUT);    //inicializa variable de entrada
    for(int i=8;i<=13;i++)  // inicializa variables de salida
    { 
    pinMode(i, OUTPUT);
    }
  /*
   * configuracion de pines individualmente
  pinMode(10,OUTPUT);  // pin 10 definido como salida
  pinMode(11,OUTPUT);  // pin 11 definido como salida
  */
  
}

void loop() {
  

//    JUEGO 1

//    Encendido de leds en forma individual

a = digitalRead(7);
if (a==HIGH)
{
  digitalWrite(10,HIGH); // pin 10 en alto (5 voltios)
 digitalWrite(11,HIGH); // pin 11 en alto (5 voltios)
 delay(400);   // espera 200 ms

}
else 
{
  digitalWrite(10,LOW); // pin 10 en bajo (0 voltios)
  digitalWrite(11,LOW); // pin 11 en bajo (0 voltios)
  delay(400);   // espera 200 ms

}
 
 
  

//JUEGO 2


// encendido de leds de forma grupal


  b = digitalRead(6);
if (b==HIGH)
{
  for(;i<6;i++){
    digitalWrite(leds[i],HIGH);  // encendiendo posicion i del vector
    delay(250);                  //espero
    digitalWrite(leds[i],LOW);   // apago posicion i del vector
    delay(250);                   //espero
    }
    i=0;    // reset de variable de conteo
           // enciendad sin apagarse
    for(;i<6;i++){
      digitalWrite(leds[i],HIGH);  // encendiendo posicion i del vector
      delay(250);  
      }
     for(;i>=0;i--){
      digitalWrite(leds[i],LOW);  // encendiendo posicion i del vector
       delay(250); 
      }
}
else 
{
   digitalWrite(leds[i],LOW);  
}

   
 i=0;  // j=5



// JUEGO 3

//SUMATORIA 

 
c = digitalRead(5);
if (c==HIGH)
{

      for(;i<3;i++){
        digitalWrite(leds[i],HIGH);
        digitalWrite(leds[5-i],HIGH);
        delay(400);
        }
        i=2;
        for(;i>=0;i--){
          digitalWrite(leds[i],LOW);
           digitalWrite(leds[5-i],LOW);
          delay(200);
          }
}
else 
{
   digitalWrite(leds[i],LOW);  
}


     i=0;


// JUEGO 4

     
// ENCENDIDO PARES 

 d = digitalRead(4);
 if (d==HIGH)
 {
   i=0; 
      for(;i<6;i++)
        {
        digitalWrite(leds[i],HIGH);
        digitalWrite(leds[i++],HIGH); //SUMATORIA DE LOS IMPARES 
        delay(200);
        }
        
        i=0; 
        for(;i<6;i++)
        {
        digitalWrite(leds[i],LOW);
        digitalWrite(leds[i++],LOW); //SUMATORIA DE LOS IMPARES 
        delay(200);
        }
 }
 else 
{
   digitalWrite(leds[i],LOW);  
}
 
 i=0; 
        
 
 //JUEGO5

 
 //ENCENDIDO IMPARES 

  e = digitalRead(3);
 if (e==HIGH)
 {
        i=1;
        for(;i<6;i++)
        {
          digitalWrite(leds[i],HIGH);
           digitalWrite(leds[i++],HIGH);
          delay(200);
         }
        i=1;
         for(;i<6;i++)
        {
          digitalWrite(leds[i],LOW);
           digitalWrite(leds[i++],LOW);
          delay(200);
         }
 }
 
 else 
{
   digitalWrite(leds[i],LOW);  
}
         i=0;

 


//JUEGO 6


// SUMADOR BINARIOS 

 f = digitalRead(2);
 if (e==HIGH){

    int k; // Declaro variable k
    if (digitalRead(A0)==HIGH)  // Si presiono el pulsador
    { 
    numero++; // Aumento el contador
    if (numero>255)// El contador llega a 255, 8bits 8 leds
    { 
    numero=0; // vuelve a 0
    }
    while (digitalRead(A0)==HIGH){} // Al presionar no hace nada mas
    }

    k=numero; // El numero va a variable k
    for(int i=8; i<=13; i++){ //Ciclo para ver que leds prendo
    digitalWrite(i, k%2); // modulo de la division por 2 para ver si led prendido o apagado
    k=k/2; // Se divide el cociente entre 2 por cada ciclo
    }
 }

 else 
{
   digitalWrite(leds[i],LOW);  
}  
 i=0; 
}





