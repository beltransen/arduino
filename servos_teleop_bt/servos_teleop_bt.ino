/**
  Moviendo el robot desde nuestro smartphone
**/

#include <Servo.h>

// Pines de los motores
int leftpin = 9;
int rightpin = 10;

Servo leftservo, rightservo;  // create servo object to control a servo

void setup() {
  // Asociamos los objetos servos a los pines correspondientes
  leftservo.attach(leftpin);  // attaches the servo on pin 9 to the servo object
  rightservo.attach(rightpin);  // attaches the servo on pin 10 to the servo object
  Serial.begin(19200); // Iniciamos conexion con puerto de serie 
}

void loop() {
  int command = '0';
  // Leemos del puerto de serie
  if(Serial.available()>0){
    command = Serial.read();
  }
  // Movemos los motores en consecuencia
  switch(command){
  case '1':
    Serial.println("Arriba");
    leftservo.write(180);    
    rightservo.write(0);
    break;
  case '2':
    Serial.println("Derecha");
    leftservo.write(180);    
    rightservo.write(180);
    break;
  case '3':
    Serial.println("Abajo");
    leftservo.write(0);    
    rightservo.write(180);
    break;
  case '4':
    Serial.println("Izquierda");
    leftservo.write(0);    
    rightservo.write(0);
    break;

  case '0': // Paramos motores
    leftservo.write(90);    
    rightservo.write(85);
    break;
  }
}

