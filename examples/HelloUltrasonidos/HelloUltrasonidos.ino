/**
 * HelloUltrasonidos
 * Ultrasonidos simple con monitor serie
 * 
 * Lee el sensor de ultrasonidos una vez por segundo y envía la medida por el puerto serie.
 * 
 * Conexiones:
 * TRIGGER -> 2
 * ECHO -> 3
 * 
 * Este ejemplo es de dominio público.
 * 
 * Modificado el 20 de diciembre de 2015
 * por Pablo Bacho para Fábrica Digital (fabricadigital.org)
 */

// Incluye la librería DistanciaUltrasonidos
#include "DistanciaUltrasonidos.h"

// Trigger en pin 2 y Echo en pin 3
const int TriggerPin = 2;
const int EchoPin = 3;

// Crea el objeto que controla el sensor:
// Clase: DistanciaUltrasonidos
// Nombre del objeto: sensorUltrasonidos
// Argumentos para crearlo: TriggerPin y EchoPin
DistanciaUltrasonidos sensorUltrasonidos(TriggerPin, EchoPin);

// Variable para guardar la distancia obtenida
int distancia;

void setup()
{
  // Inicializamos el puerto serie
  Serial.begin(9600);
}

void loop()
{
  // Leemos el sensor
  distancia = sensorUltrasonidos.obtenerDistancia();

  // Imprimimos la distancia obtenida en el monitor serie
  Serial.print(distancia);

  // Imprimimos las unidades (cm) en el monitor serie
  Serial.println(" cm");

  // Espera un segundo para hacer la siguiente medida
  delay(1000);
}
