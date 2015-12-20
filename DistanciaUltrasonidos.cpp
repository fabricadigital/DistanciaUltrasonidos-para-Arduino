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

#include "DistanciaUltrasonidos.h"

DistanciaUltrasonidos::DistanciaUltrasonidos(uint8_t trigPin = 0, uint8_t echoPin = 0) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;

  return;
}

DistanciaUltrasonidos::DistanciaUltrasonidos(uint8_t trigPin = 0, uint8_t echoPin = 0, uint16_t periodoMaximoRefresco = 0) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;
  this->periodoMaximoRefresco = periodoMaximoRefresco;

  return;
}

uint16_t DistanciaUltrasonidos::obtenerDistancia() {
  uint32_t duracion;

  // Comprueba si es muy pronto para hacer una nueva lectura
  if(millis() - this->tiempoUltimoDisparo < this->periodoMaximoRefresco) {
    return this->distancia;
  }

  // Registra el tiempo de la última distancia medida
  this->tiempoUltimoDisparo = millis();

  // Disparo del sensor
  pinMode(this->trigPin, OUTPUT);
  digitalWrite(this->trigPin,LOW); // Asegura que el pin TRIGGER está LOW antes de usarlo
  delayMicroseconds(4);
  digitalWrite(this->trigPin, HIGH); // Levanta TRIGGER al menos 10 microsegundos
  delayMicroseconds(10);
  digitalWrite(this->trigPin, LOW); // Vuelve a bajar TRIGGER tras el disparo

  // Espera la respuesta, calcula y actualiza última lectura
  pinMode(this->echoPin, INPUT);
  this->distancia = (this->VelocidadDelSonido * pulseIn(this->echoPin, HIGH, this->TimeoutEcho * 1000)) / 20000;

  return this->distancia;
}

void DistanciaUltrasonidos::establecerPeriodoMaximoRefresco(uint16_t periodoMaximoRefresco) {
  this->periodoMaximoRefresco = periodoMaximoRefresco;

  return;
}

uint16_t DistanciaUltrasonidos::obtenerPeriodoMaximoRefresco() {
  return this->periodoMaximoRefresco;
}
