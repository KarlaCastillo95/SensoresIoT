// Definición de pines para el sensor y los LEDs
int activador = A5;      // Pin analógico A5 conectado al sensor
int verde = 8;           // Pin digital 8 conectado al LED verde
int amarillo = 9;        // Pin digital 9 conectado al LED amarillo
int rojo = 10;           // Pin digital 10 conectado al LED rojo

void setup() {
  // Configuración de los pines y la comunicación serial
  pinMode(verde, OUTPUT);     // Configura el pin del LED verde como salida
  pinMode(rojo, OUTPUT);      // Configura el pin del LED rojo como salida
  pinMode(amarillo, OUTPUT);  // Configura el pin del LED amarillo como salida
  pinMode(activador, INPUT);  // Configura el pin del sensor como entrada
  
  Serial.begin(9600);         // Inicia la comunicación serial a 9600 baudios
}

void loop() {
  // Leer el valor del sensor analógico en el pin activador
  int sensorValue = analogRead(activador);  // Lee el valor del sensor (entre 0 y 1023)
  
  // Enviar el valor leído al monitor serial
  Serial.println(sensorValue);  // Imprime el valor del sensor para monitoreo
  delay(500);                   // Espera 500 ms antes de continuar
  
  // Condicional para encender el LED verde si el valor del sensor está entre 400 y 550
  if(sensorValue > 400 && sensorValue < 550) {
    digitalWrite(verde, HIGH);   // Enciende el LED verde
    delay(1000);                 // Mantiene encendido el LED por 1 segundo
    digitalWrite(verde, LOW);    // Apaga el LED verde
  }

  // Condicional para encender el LED amarillo si el valor del sensor está entre 551 y 650
  if(sensorValue > 551 && sensorValue < 650) {
    digitalWrite(amarillo, HIGH); // Enciende el LED amarillo
    delay(1000);                  // Mantiene encendido el LED por 1 segundo
    digitalWrite(amarillo, LOW);  // Apaga el LED amarillo
  }

  // Condicional para encender el LED rojo si el valor del sensor está entre 651 y 700
  if(sensorValue > 651 && sensorValue < 700) {
    digitalWrite(rojo, HIGH);     // Enciende el LED rojo
    delay(1000);                  // Mantiene encendido el LED por 1 segundo
    digitalWrite(rojo, LOW);      // Apaga el LED rojo
  }

  // Condicional para apagar todos los LEDs si no se cumple ninguna condición anterior
  else {
    digitalWrite(rojo, LOW);      // Apaga el LED rojo
    digitalWrite(amarillo, LOW);  // Apaga el LED amarillo
    digitalWrite(verde, LOW);     // Apaga el LED verde
  }
}

