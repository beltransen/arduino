/**
 * Usando el Switch para tomar decisiones
 **/

void setup() {  
  // Iniciamos conexion con puerto de serie 
  Serial.begin(19200); // Baudrate correspondiente
  // Enviamos una pregunta
  Serial.println("La tortilla de patatas, con o sin cebolla?");
}

void loop() {
  // Declaramos la variable para guardar las respuestas
  int comando  = 'c';
  // Si hay datos para leer, los guardamos
  if(Serial.available()>0){
    comando = Serial.read();
    
    // Comprobamos la respuesta y realizamos la accion correspondiente
    switch(comando){
    case 'c':
      Serial.println("Respuesta correcta");
      break;   
    case 's':
      Serial.println("Mmm incorrecto, me has decepcionado");
      break;
    default:
      Serial.println("Pero entonces... CON o SIN?");
      break;
    }
  }
}


