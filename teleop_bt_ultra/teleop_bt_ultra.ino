#include <Servo.h>
#include <Ultrasonic.h>
#include <QTRSensors.h>

// Pines para LED y motores
int ledpin = 13;
int leftpin = 9;
int rightpin = 10;

// Sensor infrarrojos
const int NUM_SENSORS = 3;  // Numero de sensores
const int NUM_SAMPLES_PER_SENSOR = 4; // Hacer la media de 4 valores
unsigned char inf_sensor[] = {2, 1, 0}; // Entradas analogicas

QTRSensorsAnalog qtra(inf_sensor, NUM_SENSORS, NUM_SAMPLES_PER_SENSOR);

Servo leftservo, rightservo;  // create servo object to control a servo

Ultrasonic l_ultrasonic(7,6); // (Trig PIN,Echo PIN)
Ultrasonic r_ultrasonic(5,4); // (Trig PIN,Echo PIN)

unsigned int sensorValues[NUM_SENSORS];
bool hay_obstaculo = false;
int command='0';

void setup() {
  delay(500);
  Serial.begin(19200); 
  Serial.println("*:Calibrating*");
  for (int i=0; i<400; i++){
    qtra.calibrate(); 
  }
  Serial.println("*:Calibrated*");
  delay(1000);
  
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  leftservo.attach(leftpin);  // attaches the servo on pin 9 to the servo object
  rightservo.attach(rightpin);  // attaches the servo on pin 9 to the servo object
  Serial.println("*:Robot conectado!*");
}

void loop() {
  // Leer los valores de los sensores
  qtra.readCalibrated(sensorValues);
  
  long l_distance = l_ultrasonic.Ranging(CM);
  long r_distance = r_ultrasonic.Ranging(CM);

  if(l_distance<10 || r_distance<10){
    Serial.println("*:Obstaculo detectado!*");
    hay_obstaculo = true;
  }else{
    hay_obstaculo = false;
  }
    
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    command = Serial.read();
  }
  switch(command){
    case '1':
      if(!hay_obstaculo){
        Serial.println("*:Arriba*");
        leftservo.write(180);    
        rightservo.write(0);
      }else{ // Paramos motores
        leftservo.write(90);    
        rightservo.write(85);
      }
      break;
    case '2':
      Serial.println("*:Derecha*");
      leftservo.write(180);    
      rightservo.write(180);
      break;
    case '3':
      Serial.println("*:Abajo*");
      leftservo.write(0);    
      rightservo.write(180);
      break;
    case '4':
      Serial.println("*:Izquierda*");
      leftservo.write(0);    
      rightservo.write(0);
      break;
    case '5':
      Serial.println("*:LED on*");
      digitalWrite(ledpin, HIGH);
      delay(500);
      digitalWrite(ledpin, LOW);
      delay(10);
      Serial.println("*:Esperando comandos*");
      break;
    case '6':
      Serial.println("*:Long LED on*");
      digitalWrite(ledpin, HIGH);
      delay(1000);
      digitalWrite(ledpin, LOW);
      delay(10);
      Serial.println("*:Esperando comandos*");
      break;

    case '0': // Paramos motores
      leftservo.write(90);    
      rightservo.write(85);
      break;
  }
}
