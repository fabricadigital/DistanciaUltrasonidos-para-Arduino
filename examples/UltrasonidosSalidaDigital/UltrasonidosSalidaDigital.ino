/**
 * UltrasonidosSalidaDigital
 * Usa el sensor de distancia por ultrasonidos con una salida digital
 * 
 * La salida digital puede ser, por ejemplo, un LED que parpadea o un buzzer activo, que varía su frecuencia según la distancia obtenida.
 * Cuando la distancia es menor que la constante UmbralInferior, la señal se mantiene activa continua.
 * Cuando la distancia es mayor que la constante UmbralSuperior, la señal se mantiene desactivada.
 * Cuando la distancia está entre ambas constantes, la señal parpadea con un tiempo de apagado proporcional.
 * 
 * Conexiones:
 * TRIGGER -> 2
 * ECHO -> 3
 * SALIDA -> 13 (LED en placa)
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
// Salida en pin 13
const int SalidaPin = 13;

// Umbral de distancia por debajo del cual la señal digital se activa continua
const int UmbralInferior = 8; // en cm
// Umbral de distancia por encima del cual la señal digital no se activa
const int UmbralSuperior = 50; // en cm
// Tiempo maximo de espera entre medida y medida
const int TiempoMaximoEspera = 2000; // en ms

// Crea el objeto que controla el sensor:
DistanciaUltrasonidos sensorUltrasonidos(TriggerPin, EchoPin);

// Variable para guardar la distancia obtenida
int distancia;
// Variable para calcular el tiempo de espera
int tiempoEspera;

void setup()
{
  // Inicializamos la salida
  pinMode(SalidaPin, OUTPUT);

  // Establecemos el periodo máximo de refresco del sensor en 1s
  sensorUltrasonidos.establecerPeriodoMaximoRefresco(500);
}

void loop()
{
  // Leemos el sensor
  distancia = sensorUltrasonidos.obtenerDistancia();

  // Solo activar la señal si esta por debajo de UmbralSuperior
  if(distancia < UmbralSuperior) {
    // Calculamos el tiempo de espera para UmbralSuperior = TiempoMaximoEspera
    tiempoEspera = map(distancia, UmbralInferior, UmbralSuperior, 0, TiempoMaximoEspera);
    // Limitamos el tiempo de espera a estar entre 0 y TiempoMaximoEspera.
    tiempoEspera = constrain(tiempoEspera, 0, TiempoMaximoEspera);
  
    digitalWrite(SalidaPin, HIGH);
    delay(200);
    digitalWrite(SalidaPin, LOW);
    delay(tiempoEspera);
  }
}
