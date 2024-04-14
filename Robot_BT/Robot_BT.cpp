#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include "Robot_BT.h"
int parseD1Value(String json)
{
  if (json == 's')
  {
    return 'w';
  }
  int d1Value = 0;
  int pos = json.indexOf("\"D1\":"); // Encontrar la posición donde comienza la clave "D1"
  if (pos != -1)
  {                                     // Si se encuentra la clave "D1"
    pos += 6;                           // Avanzar 6 posiciones para omitir la clave "D1": "
    String d1Str = json.substring(pos); // Obtener la subcadena que contiene el valor de D1
    d1Value = d1Str.toInt();            // Convertir la subcadena a un entero
  }
  return d1Value;
}
char traslateD1(int d1Value)
{
  char Estado;
  if (d1Value == 1)
  {
    Estado = '1';
  }
  if (d1Value == 2)
  {
    Estado = '2';
  }
  if (d1Value == 3)
  {
    Estado = '3';
  }
  if (d1Value == 4)
  {
    Estado = '4';
  }
  if (d1Value == 5)
  {
    Estado = '5';
  }
  if (d1Value == 6)
  {
    Estado = '6';
  }
  if (d1Value == 7)
  {
    Estado = '7';
  }
  if (d1Value == 8)
  {
    Estado = '8';
  }
  if (d1Value == 9)
  {
    Estado = '9';
  }

  return Estado;
}

void Robot_BT::Inicializar()
{
  Robot.Inicializar_Robot();
  Bluetooth.begin(9600); // Iniciar la comunicacion a 9600
}
char Robot_BT::Leer_BT()
{
  if (Bluetooth.available())
  {
    char _command = Bluetooth.read();

    if (_command == '1')
    {
      return 'a';
    }
    if (_command == 's')
    {
      return 'w';
    }
    if (_command == '2')
    {
      return 'c';
    }
    if (_command == '{')
    {
      // Si hay datos disponibles para leer desde el módulo Bluetooth
      String data = Bluetooth.readStringUntil('}'); // Leer los datos hasta que se reciba un salto de línea (\n)
      int d1Value = parseD1Value(data);
      return traslateD1(d1Value);
    }
  }
}
void Robot_BT::Modo_Bluetooth()
{
  int Estado;
  int Velocidad_Max = 255;
  int Velocidad_Med = 180;
  Estado = Leer_BT();

  if (Estado == '6')
  {
    // Arriba_Izquierda
    Robot.Adelante(Velocidad_Med, Velocidad_Max);
  }
  else if (Estado == '3')
  {
    // Derecho
    Robot.Adelante(Velocidad_Max, Velocidad_Max);
  }
  else if (Estado == '8')
  {
    // Arriba_Derecha
    Robot.Adelante(Velocidad_Max, Velocidad_Med);
  }
  else if (Estado == '1')
  {
    // Girar a la izquierda
    Robot.Motor_2.Adelante(Velocidad_Max);
    Robot.Motor_1.Atras(Velocidad_Max);
  }
  else if (Estado == '2')
  {
    // Girar a la derecha
    Robot.Motor_2.Atras(Velocidad_Max);
    Robot.Motor_1.Adelante(Velocidad_Max);
  }
  else if (Estado == '7')
  {
    // Abajo Izquierda
    Robot.Atras(Velocidad_Med, Velocidad_Max);
  }
  else if (Estado == '4')
  {
    // Reversa
    Robot.Atras(Velocidad_Max, Velocidad_Max);
  }
  else if (Estado == '9')
  {
    // Abajo Derecha
    Robot.Atras(Velocidad_Max, Velocidad_Med);
  }
  else if (Estado == 'w')
  {
    Robot.Stop();
  }
  return Estado;
}
