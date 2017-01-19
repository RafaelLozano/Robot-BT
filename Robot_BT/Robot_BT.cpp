#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include "Robot_BT.h"
void Robot_BT::Inicializar()
{
  Robot.Inicializar_Robot();
  Bluetooth.begin(9600);//Iniciar la comunicacion a 9600
}
char Robot_BT::Leer_BT()
{
  char Estado;
  if (Bluetooth.available() > 0)
      {
        Estado = Bluetooth.read();
      }
  return Estado;
}
void Robot_BT::Modo_Bluetooth()
{
  int Estado;
  int Velocidad_Max=255;
  int Velocidad_Med=200;
  Estado=Leer_BT();
  if (Estado == '1')
      {
        //Arriba_Izquierda
        Robot.Adelante(Velocidad_Med,Velocidad_Max);
      }
      if (Estado == '2')
      {
        //Derecho
        Robot.Adelante(Velocidad_Max,Velocidad_Max);
      }
      if (Estado == '3')
      {
        //Arriba_Derecha
        Robot.Adelante(Velocidad_Max,Velocidad_Med);
      }
      if (Estado == '4')
      {
        //Girar a la izquierda
        Robot.Motor_2.Adelante(Velocidad_Max);
        Robot.Motor_1.Atras(Velocidad_Max);
      }
      if (Estado == '5')
      {
        //Serial.println("Logo talos");
      }
      if (Estado == '6')
      {
        //Girar a la derecha
        Robot.Motor_2.Atras(Velocidad_Max);
        Robot.Motor_1.Adelante(Velocidad_Max);
      }
      if (Estado == '7')
      {
        //Abajo Izquierda
        Robot.Atras(Velocidad_Med,Velocidad_Max); 
      }
      if (Estado == '8')
      {
        //Reversa
        Robot.Atras(Velocidad_Max,Velocidad_Max);
      }
      if (Estado == '9')
      {
        //Abajo Derecha
        Robot.Atras(Velocidad_Max,Velocidad_Med);
      }
      if (Estado == 'w')
      {
        Robot.Stop();
      }
}
