#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include "Sensor_TCRT5000.h"

void Sensor::Inicializar()
{
  pinMode(Pin_sensor, OUTPUT);
}

int Sensor::Leer_sensor()
{
  int Estado;
  Estado=digitalRead(Pin_sensor);
  return Estado;
}

