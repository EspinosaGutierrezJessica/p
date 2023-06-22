// Constantes para el sensor ultrasónico
const int trigPin = 2;    // Pin de disparo del sensor ultrasónico
const int echoPin = 3;    // Pin de eco del sensor ultrasónico

// Constante para el LED
const int ledPin = 4;     // Pin del LED

// Constante para la distancia de detección
const int distanciaDeteccion = 10;  // Distancia de detección en centímetros

// Variables para el cálculo de la distancia
long duracion;
int distancia;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Generar un pulso ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Medir la duración del pulso de eco
  duracion = pulseIn(echoPin, HIGH);

  // Calcular la distancia en centímetros
  distancia = duracion * 0.034 / 2;

  // Imprimir la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Encender el LED si se detecta un objeto a la distancia especificada
  if (distancia <= distanciaDeteccion) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(100); // Esperar un breve periodo antes de realizar la siguiente medición
}
