const int sensorH1 = 9; // Pin digital 9 conectado al sensor.
const int ledPin = 2;   // Pin digital 2 conectado al LED.
int buzzer = A1;        // Pin analógico A1 conectado al buzzer.

void setup() {
  // Configura el pin del sensor como entrada con resistencia pull-up interna.
  pinMode(sensorH1, INPUT_PULLUP);

  // Configura el pin del LED como salida.
  pinMode(ledPin, OUTPUT);

  // Configura el pin del buzzer como salida.
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Lee el estado del sensor (HIGH o LOW).
  int estadoP1 = digitalRead(sensorH1);

  // Si el sensor detecta un estado bajo (LOW):
  if (estadoP1 == LOW) {
    // Enciende el LED.
    digitalWrite(ledPin, HIGH);
    
    // Apaga el buzzer (asegura que no emita sonido).
    noTone(buzzer);
  } else {
    // Si el sensor detecta un estado alto (HIGH):
    // Apaga el LED.
    digitalWrite(ledPin, LOW);
    
    // Activa el buzzer y emite un tono de 600 Hz.
    tone(buzzer, 600);
  }
}

