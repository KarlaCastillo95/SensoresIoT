// Declaración de variables para los pines de los LEDs
int led1 = 13;  // LED conectado al pin digital 13
int led2 = 12;  // LED conectado al pin digital 12
int led3 = 11;  // LED conectado al pin digital 11
int identificador = 0; // Variable para rastrear el estado actual del ciclo

// Configuración inicial del programa
void setup() {
  pinMode(led1, OUTPUT); // Configura el pin 13 como salida
  pinMode(led2, OUTPUT); // Configura el pin 12 como salida
  pinMode(led3, OUTPUT); // Configura el pin 11 como salida
}

// Bucle principal que se ejecuta continuamente
void loop() {
  // Verifica si el botón conectado al pin 7 está presionado
  if (digitalRead(7) == HIGH) {
    delay(20); // Breve pausa para evitar lecturas inestables del botón
    
    // Si `identificador` es 0, enciende el LED1 y apaga los demás
    if (identificador == 0) {
      digitalWrite(led1, HIGH); // Enciende el LED1
      delay(200);               // Pausa de 200 ms para mantener el LED encendido
      digitalWrite(led2, LOW);  // Asegura que el LED2 esté apagado
      digitalWrite(led3, LOW);  // Asegura que el LED3 esté apagado
      identificador += 1;       // Cambia el estado a 1 para la siguiente iteración
    } 
    // Si `identificador` es 1, enciende el LED2 y apaga los demás
    else if (identificador == 1) {
      digitalWrite(led1, LOW);  // Asegura que el LED1 esté apagado
      digitalWrite(led2, HIGH); // Enciende el LED2
      delay(200);               // Pausa de 200 ms para mantener el LED encendido
      digitalWrite(led3, LOW);  // Asegura que el LED3 esté apagado
      identificador += 1;       // Cambia el estado a 2 para la siguiente iteración
    } 
    // Si `identificador` es 2, enciende el LED3 y apaga los demás
    else if (identificador == 2) {
      digitalWrite(led1, LOW);  // Asegura que el LED1 esté apagado
      digitalWrite(led2, LOW);  // Asegura que el LED2 esté apagado
      digitalWrite(led3, HIGH); // Enciende el LED3
      delay(200);               // Pausa de 200 ms para mantener el LED encendido
      identificador = 0;        // Reinicia el ciclo al estado inicial
    }
  } 
  // Si el botón no está presionado, apaga todos los LEDs
  else {
    digitalWrite(led1, LOW); // Apaga el LED1
    digitalWrite(led2, LOW); // Apaga el LED2
    digitalWrite(led3, LOW); // Apaga el LED3
  }
}

