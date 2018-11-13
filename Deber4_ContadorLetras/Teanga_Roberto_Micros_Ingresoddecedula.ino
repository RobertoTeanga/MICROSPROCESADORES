int numero1;
int numero2;
int numero3;
int numero4; 
int numero5; 
int numero6; 
int numero7;
int numero8;
int numero9;
int numero10;
int i=0;  
 
void setup() {
        Serial.begin(9600);
        Serial.println("intruzca los numeros");
}
 
void loop() {
   
 // if(i>10)
  
  //{
   // i=0; 
        numero1 = Serial.parseInt(); //12,34,56
        numero2 = Serial.parseInt();
        numero3 = Serial.parseInt();
        numero4 = Serial.parseInt();
        numero5 = Serial.parseInt();
        numero6 = Serial.parseInt();
        numero7 = Serial.parseInt();
        numero8 = Serial.parseInt();
        numero9 = Serial.parseInt();
        numero10 = Serial.parseInt();
 
        Serial.println(numero1+i);
        Serial.println(numero2+i);
        Serial.println(numero3+i);
        Serial.println(numero4+i);
        Serial.println(numero5+i);
        Serial.println(numero6+i);
        Serial.println(numero7+i);
        Serial.println(numero8+i);
        Serial.println(numero9+i);
        Serial.println(numero10+i);
        
//}
}





 
