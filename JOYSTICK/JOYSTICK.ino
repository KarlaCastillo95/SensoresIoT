// Declaración de variables globales
int y;  // Variable para almacenar la lectura del pin analógico A1
int x;  // Variable para almacenar la lectura del pin analógico A0

// Función que se ejecuta una sola vez al inicio
void setup (){
  Serial.begin(9600);  // Inicia la comunicación serial a 9600 baudios para enviar datos al monitor serial
  pinMode(9, OUTPUT);  // Configura el pin 9 como salida (para controlar un dispositivo)
  pinMode(10, OUTPUT); // Configura el pin 10 como salida (para controlar otro dispositivo)
  pinMode(11, OUTPUT); // Configura el pin 11 como salida (para controlar otro dispositivo)
  pinMode(12, OUTPUT); // Configura el pin 12 como salida (para controlar otro dispositivo)
}

// Función principal que se ejecuta de forma repetitiva
void loop() {
  y = analogRead(A1);  // Lee el valor analógico en el pin A1 (0 a 1023) y lo guarda en la variable y
  x = analogRead(A0);  // Lee el valor analógico en el pin A0 (0 a 1023) y lo guarda en la variable x
  
  // Imprime los valores de x e y en el monitor serial para su visualización
  Serial.print("y=");
  Serial.print(y);
  Serial.print("x=");
  Serial.println(x);
  
  // Espera 200 milisegundos antes de realizar la siguiente lectura
  delay(200);

  // Si el valor de x es mayor a 520, enciende el pin 9
  if (x > 520){
    digitalWrite(9, HIGH);  // Establece el pin 9 en alto (enciende el dispositivo)
  }
  else {
    digitalWrite(9, LOW);   // Si no, establece el pin 9 en bajo (apaga el dispositivo)
  }

  // Si el valor de x es menor a 500, enciende el pin 10
  if (x < 500){
    digitalWrite(10, HIGH);  // Establece el pin 10 en alto (enciende el dispositivo)
  }
  else {
    digitalWrite(10, LOW);   // Si no, establece el pin 10 en bajo (apaga el dispositivo)
  }

  // Si el valor de y es mayor a 1020, enciende el pin 11
  if (y > 1020){
    digitalWrite(11, HIGH);  // Establece el pin 11 en alto (enciende el dispositivo)
  }
  else {
    digitalWrite(11, LOW);   // Si no, establece el pin 11 en bajo (apaga el dispositivo)
  }

  // Si el valor de y es menor a 500, enciende el pin 12
  if (y < 500){
    digitalWrite(12, HIGH);  // Establece el pin 12 en alto (enciende el dispositivo)
  }
  else {
    digitalWrite(12, LOW);   // Si no, establece el pin 12 en bajo (apaga el dispositivo)
  }
}

