/*
 * PROGRAMA DE JUEGO DE LUCES 
 * NOMBRE: ROBERTO TEANGA 
 * MATERIA: MICROS 
 * FECHA: 24 DE OCTUBRE DEL 2018 
 * 
 */
int leds[6]={8,9,10,11,12,13}; // defino vector para configurar leds
int i=0; // variable de recorrido del vector
long randNumber;
void setup() 
{
  // configuracion de pines de forma grupal
  for(;i<6;i++){
     pinMode(leds[i],OUTPUT);
    }
    
      i=0;  // reseteo la variable de conteo
Serial.begin(9600);
randomSeed(analogRead(0));
  

}

void loop() 

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
         i=0;
        for(;i<randNumber;i++)
        { 
         i = random(300);
         Serial.println(i);
         i = random(10, 20);
         Serial.println(i);
         delay(50);
        }
       
         
   i=0;

}



