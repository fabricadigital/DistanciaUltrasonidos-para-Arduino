/**
 * Librería DistanciaUltrasonidos para Arduino
 * Copyright 2015 - Fábrica Digital (fabricadigital.org)
 * 
 * Publicado bajo licencia CC-BY-SA 4.0
 * Creative Commons: Reconocimiento - Compartir Igual 4.0 Internacional
 * http://creativecommons.org/licenses/by-sa/4.0/deed.es_ES
 *
 * Modificado el 20 de diciembre de 2015
 * por Pablo Bacho para Fábrica Digital
 */

#ifndef _DISTANCIAULTRASONIDOS_H_
#define _DISTANCIAULTRASONIDOS_H_

#include "Arduino.h"

class DistanciaUltrasonidos {
  private:
    static const uint16_t VelocidadDelSonido = 343; // Velocidad del sonido en m/s
    static const uint8_t TimeoutEcho = 20; // Timeout en milisegundos para esperar ECHO despues de TRIGGER
    
    uint8_t trigPin = 0; // Pin TRIGGER
    uint8_t echoPin = 0; // Pin ECHO
    uint16_t distancia = 0; // Última distancia medida
    uint32_t tiempoUltimoDisparo = 0; // Tiempo de la función millis() en el último disparo del sensor
    uint16_t periodoMaximoRefresco = 0; // Solicitudes de distancia por debajo de este umbral en milisegundos devuelven el último dato sin usar el sensor
    
  public:
    DistanciaUltrasonidos(uint8_t trigPin, uint8_t echoPin);
    DistanciaUltrasonidos(uint8_t trigPin, uint8_t echoPin, uint16_t periodoMaximoRefresco);
    uint16_t obtenerDistancia();
    void establecerPeriodoMaximoRefresco(uint16_t periodoMaximoRefresco);
    uint16_t obtenerPeriodoMaximoRefresco();
};

#endif // _DISTANCIAULTRASONIDOS_H_
