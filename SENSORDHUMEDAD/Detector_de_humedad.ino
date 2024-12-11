// Definición de pines
const int sensorH1 = 9;  // El pin 9 está conectado al sensor de humedad
const int led = 2;        // El pin 2 está conectado al LED

void setup() {
  // Se configura el pin del sensor como entrada con resistencia pull-up
  pinMode(sensorH1, INPUT_PULLUP);  // Activa la resistencia pull-up interna para el sensor (esto puede ser útil si el sensor tiene una salida digital que se activa a LOW cuando hay humedad)
  
  // Se configura el pin del LED como salida
  pinMode(led, OUTPUT);  // Establece el pin del LED como salida, para que podamos encenderlo o apagarlo
}

void loop() {
  // Lectura del estado del sensor de humedad
  int estadoP1 = digitalRead(sensorH1);  // Lee el valor digital del sensor (HIGH o LOW)
  
  // Condicional para verificar el estado del sensor
  if(estadoP1 == LOW) {  // Si el sensor detecta humedad (o un valor LOW)
    digitalWrite(led, HIGH);  // Enciende el LED (el sensor está "activo" cuando está en LOW)
  } else {
    digitalWrite(led, LOW);   // Si no se detecta humedad (estado HIGH del sensor), apaga el LED
  }
}

