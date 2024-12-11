#include <Servo.h>  // Incluye la librería Servo para controlar servos.

Servo ioe;  // Crea un objeto 'ioe' de la clase Servo para controlar el servo.

int trig = 2;  // Define el pin 2 como el pin de activación (trigger) del sensor ultrasónico.
int echo = 3;  // Define el pin 3 como el pin de recepción (echo) del sensor ultrasónico.
int tiempo;  // Variable para almacenar el tiempo que tarda el sonido en ir y regresar.
int distancia;  // Variable para almacenar la distancia calculada en cm.

void setup() {
  // Configura los pines de entrada y salida, y el servo.
  
  pinMode(trig, OUTPUT);  // Configura el pin 'trig' como salida (para enviar el pulso).
  pinMode(echo, INPUT);   // Configura el pin 'echo' como entrada (para recibir el eco).
  ioe.attach(4);  // Asocia el servo al pin 4 de la placa Arduino.
}

void loop() {
  // Bucle principal donde se realiza la medición y el control del servo.
  
  digitalWrite(trig, HIGH);  // Envía una señal alta al pin 'trig' para activar el sensor ultrasónico.
  delay(500);  // Espera 500 milisegundos para asegurar que el pulso se haya emitido completamente.
  digitalWrite(trig, LOW);   // Apaga el pin 'trig' después de haber enviado el pulso.
  
  tiempo = pulseIn(echo, HIGH);  // Lee el tiempo que tarda el eco en volver al pin 'echo'.
  distancia = tiempo / 58.2;  // Calcula la distancia en centímetros dividiendo el tiempo por 58.2.
  
  delay(500);  // Espera 500 milisegundos antes de tomar una nueva medición.

  // Si la distancia es menor o igual a 10 cm, mueve el servo a 120 grados.
  if (distancia <= 10) {
    ioe.write(120);  // Mueve el servo a 120 grados.
    delay(2000);  // Espera 2 segundos (para dar tiempo al servo de moverse completamente).
  }
  
  // Si la distancia es mayor a 10 cm, mueve el servo a 45 grados.
  if (distancia > 10) {
    ioe.write(45);  // Mueve el servo a 45 grados.
  }
}

