/**
 * Parpadear LED a cierta distancia del ultrasonido
 **/
#include <Ultrasonic.h>

Ultrasonic ultra(7,6, 6000); // (Trig PIN,Echo PIN)

float LED_DISTANCE = 10.0;

void setup(){
  Serial.begin(19200);
  pinMode(13, OUTPUT);
}

void loop(){
  long distance = ultra.Ranging(CM); // Medir distancia
  if(distance<LED_DISTANCE){
    digitalWrite(13, HIGH);
    Serial.println(1000.0/distance);
    delay(500.0/distance);
    digitalWrite(13, LOW);
    delay(500.0/distance);
  }
}


