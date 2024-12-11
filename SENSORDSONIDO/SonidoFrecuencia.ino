// Definición del pin al que está conectado el sensor de sonido (entrada analógica)
const int pinSensorSonido = A0;  // A0 es un pin analógico en la placa Arduino
// Definición del número de LEDs que se usarán (en este caso, 6 LEDs)
const int numLEDs = 6;           // El sistema controlará 6 LEDs
// Arreglo que almacena los pines a los que están conectados los LEDs (del 2 al 7)
int leds[numLEDs] = {2, 3, 4, 5, 6, 7};  // Los LEDs están conectados a los pines 2 a 7

void setup() {
  // Configuración de los pines de los LEDs como salidas
  for (int i = 0; i < numLEDs; i++) { 
    pinMode(leds[i], OUTPUT);  // Establece el modo de cada pin de LED como salida
  }
  
  // Inicialización de la comunicación serial con la PC para monitorear los datos
  Serial.begin(9600); // Configura la velocidad de comunicación serial a 9600 baudios
}

void loop() {
  // Lee el valor del sensor de sonido en un rango de 0 a 1023 (valor analógico)
  int nivelRuido = analogRead(pinSensorSonido);  // Obtiene el valor de ruido del sensor

  // Muestra el valor crudo del sensor en el monitor serial
  Serial.print("Valor crudo del sensor: ");
  Serial.println(nivelRuido); // Muestra el valor sin procesar de la lectura del sensor

  // Mapea el valor crudo del sensor (0-1023) a un rango más manejable (0-200)
  int ruidoMapeado = map(nivelRuido, 0, 1023, 0, 200);  // Ajusta el valor al rango 0-200
  // Muestra el valor mapeado del nivel de ruido
  Serial.print("Nivel de ruido mapeado: ");
  Serial.println(ruidoMapeado); // Muestra el valor mapeado (escala de 0 a 200)

  // Controla cuántos LEDs encender según el nivel de ruido
  for (int i = 0; i < numLEDs; i++) {
    // Comprueba si el nivel de ruido mapeado es mayor que un umbral calculado
    // El umbral aumenta gradualmente para encender más LEDs conforme el ruido sube
    if (ruidoMapeado > (i * (38 / numLEDs))) {
      // Enciende el LED correspondiente si el ruido es suficiente
      digitalWrite(leds[i], HIGH);  // Pone el pin del LED a HIGH (encendido)
    } else {
      // Apaga el LED si el ruido no alcanza el umbral
      digitalWrite(leds[i], LOW);   // Pone el pin del LED a LOW (apagado)
    }
  }

  // Pausa de 100 milisegundos antes de la siguiente lectura
  delay(100); // Espera 100ms para estabilizar las lecturas y no hacerlas demasiado rápidas
}

