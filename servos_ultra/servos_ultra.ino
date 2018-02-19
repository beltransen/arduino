/**
 * Movimiento hacia delante cuando hay un obstaculo
 **/

#include <Servo.h>
#include <Ultrasonic.h>

Ultrasonic l_ultra(7,6, 6000); // (Trig PIN,Echo PIN)
Ultrasonic r_ultra(5,4, 6000); // (Trig PIN,Echo PIN)

// Pines de los motores
int leftpin = 9;
int rightpin = 10;

Servo leftservo, rightservo;  // create servo object to control a servo

void setup(){
  // Asociamos los objetos servos a los pines correspondientes
  leftservo.attach(leftpin);  // attaches the servo on pin 9 to the servo object
  rightservo.attach(rightpin);  // attaches the servo on pin 10 to the servo object
  Serial.begin(19200); // Iniciamos conexion con puerto de serie 
}

void loop(){
  // Leer distancia de los ultrasonidos
  long l_distancia = l_ultra.Ranging(CM);
  long r_distancia = r_ultra.Ranging(CM);
  
  if(l_distancia<15 || r_distancia<15){ // Avanzar
    leftservo.write(180);    
    rightservo.write(0);
  }
  else{ // Detenerse
    leftservo.write(90);    
    rightservo.write(85);
  }
}



