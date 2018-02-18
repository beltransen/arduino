/**
  Comunicacion por puerto de serie
**/

void setup() {  
  // Iniciamos conexion con puerto de serie 
  Serial.begin(19200); // Baudrate correspondiente
}

void loop() {
  // Si hay datos para leer, los guardamos y mostramos
  if(Serial.available()>0){
    char comando = Serial.read();
    Serial.print("Recibido: ");
    Serial.println(comando);
  }
}
