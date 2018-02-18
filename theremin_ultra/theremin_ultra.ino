/**
 * Theremin con Ultrasonidos y Piezo
**/
#include <Ultrasonic.h>

Ultrasonic ultra(4,2, 6000); // (Trig PIN,Echo PIN)
int notas[] = {
  261, 293, 329, 349, 392, 440, 493};

float MAX_DISTANCE = 30.0;
float MIN_DISTANCE = 5.0;
int NUM_NOTAS = 6.0;
float slot = (MAX_DISTANCE-MIN_DISTANCE)/NUM_NOTAS;

void setup(){
  Serial.begin(19200);
  Serial.println(slot);
}

void loop(){
  long distance = ultra.Ranging(CM); // Medir distancia
  if(distance>MAX_DISTANCE || distance < MIN_DISTANCE){
    noTone(8); // Si no esta en rango, no emitir sonido
  }
  else{ 
    // Emitir nota correspondiente dependiendo de la distancia:
    // Indice calculado en bins de 1/NUM_NOTAS del rango considerado;
    int index = floor((distance-MIN_DISTANCE)/slot);
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" Pitch: ");
    Serial.println(index);
    tone(8, notas[index], 20);
  }
  delay(20);
}

