#include <avr/wdt.h> // Incluir la librería que contiene el watchdog (wdt.h)
 
#define TIEMPO_DE_ESPERA 2500 // 2500 milisegundos (cualquier valor mayor que 2 segundos)
 
unsigned long cronometro;
unsigned long tiempo_transcurrido;
 
void setup()
{
  wdt_disable();
  wdt_enable(WDTO_2S); // Configurar a dos segundos
  Serial.begin(9600);
}
 
void loop()
{
  wdt_reset(); // Actualizar el watchdog para que no produzca un reinicio
  Serial.println("Esto se ve en la consola");
  cronometro=millis(); // Iniciar el cronómetro
  do
  {
    tiempo_transcurrido=millis()-cronometro; // Calcular el tiempo que ha pasado desde que se inició el cronómetro
  }
  while(tiempo_transcurrido<TIEMPO_DE_ESPERA); // Repetir mientras que no haya pasado el tiempo previsto
  Serial.println("Esto NO lo muestra en la consola porque se resetea antes");
}
void cont1()
{
  
  wdt_reset(); // Actualizar el watchdog para que no produzca un reinicio
  Serial.println("Esto se ve en la consola");
  cronometro=millis(); // Iniciar el cronómetro
  do
  {
    tiempo_transcurrido=millis()-cronometro; // Calcular el tiempo que ha pasado desde que se inició el cronómetro
  }
  while(tiempo_transcurrido<TIEMPO_DE_ESPERA); // Repetir mientras que no haya pasado el tiempo previsto
  Serial.println("Esto NO lo muestra en la consola porque se resetea antes");
}
void con2()
{
  
  wdt_reset(); // Actualizar el watchdog para que no produzca un reinicio
  Serial.println("Esto se ve en la consola");
  cronometro=millis(); // Iniciar el cronómetro
  do
  {
    tiempo_transcurrido=millis()-cronometro; // Calcular el tiempo que ha pasado desde que se inició el cronómetro
  }
  while(tiempo_transcurrido<TIEMPO_DE_ESPERA); // Repetir mientras que no haya pasado el tiempo previsto
  Serial.println("Esto NO lo muestra en la consola porque se resetea antes");
}
void cont3()
{
  
  wdt_reset(); // Actualizar el watchdog para que no produzca un reinicio
  Serial.println("Esto se ve en la consola");
  cronometro=millis(); // Iniciar el cronómetro
  do
  {
    tiempo_transcurrido=millis()-cronometro; // Calcular el tiempo que ha pasado desde que se inició el cronómetro
  }
  while(tiempo_transcurrido<TIEMPO_DE_ESPERA); // Repetir mientras que no haya pasado el tiempo previsto
  Serial.println("Esto NO lo muestra en la consola porque se resetea antes");
}

