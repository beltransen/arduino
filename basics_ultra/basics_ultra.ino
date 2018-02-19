/**
 * Tiempo de vuelo y distancias con ultrasonidos
 **/
#include <Ultrasonic.h>

Ultrasonic ultra(7,6, 6000); // (Trig PIN,Echo PIN)

void setup(){
  Serial.begin(19200);
}

void loop(){
  // Mostrar tiempo de vuelo de la onda
  long tiempo = ultra.Timing();
  Serial.print("Tiempo de vuelo: ");
  Serial.println(tiempo);
  
  // Calcular distancia a partir del tiempo de vuelo 
  Serial.print("Distancia 1: ");
  Serial.println(tiempo/2/29.41176); 
  
  // Obtener distancia mediante funcion de la libreria
  Serial.print("Distancia 2: ");
  Serial.println(ultra.Ranging(CM));
  
  delay(500);
}


