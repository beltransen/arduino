#include <Servo.h>
#include <Ultrasonic.h>

// Pines para LED y motores
int ledpin = 13;
int leftpin = 9;
int rightpin = 10;

Servo leftservo, rightservo;  // create servo object to control a servo

Ultrasonic l_ultrasonic(7,6); // (Trig PIN,Echo PIN)
Ultrasonic r_ultrasonic(5,4); // (Trig PIN,Echo PIN)

void setup() {
  // put your setup code here, to run once
  leftservo.attach(leftpin);  // attaches the servo on pin 9 to the servo object
  rightservo.attach(rightpin);  // attaches the servo on pin 9 to the servo object
  Serial.println("Robot conectado!");
}

void moverMotores(int left_speed, int right_speed, int timems){
    leftservo.write(left_speed);    
    rightservo.write(right_speed);
//    delay(timems);
}

void loop() {  
  long l_distance = l_ultrasonic.Ranging(CM);
  long r_distance = r_ultrasonic.Ranging(CM);

  int left_speed = 180;
  int right_speed = 0;
  
  if(l_distance<10){
    right_speed = 50;
  }else if(l_distance>20){
    left_speed = 130;
  }
  moverMotores(left_speed, right_speed, 20);
}
