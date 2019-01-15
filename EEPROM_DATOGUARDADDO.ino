/*
 * Universidad tecnica del norte 
 * Nombre: Roberto Teanga 
 * Materia: Sistema Microprosesados 
 * Fecha: 15 de enero del 2019
 * Tema: Guardar dato si es mayor no si es menor 
 */
#include <EEPROM.h>
 int cont; 
 float dato; 


void setup()
{
 Serial.begin(9600); 
 cont=EEPROM.read(0); 


}
void loop() 
{
  if(cont<dato)
  { 
  cont++; 
  EEPROM.update(0,cont);
  Serial.print("Dato guardado")  
  Serial.println(cont); 
  delay(400); 
  }
  else 
  cont=0; 
}
