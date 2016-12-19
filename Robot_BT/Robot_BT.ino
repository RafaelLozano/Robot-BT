#include "Robot_BT.h"
Robot_BT Robot(13,12,11,10,8,9,2,3);
void setup() 
{
  Robot.Inicializar();
  Serial.begin(9600);
}

void loop() 
{
  Robot.Modo_Bluetooth();
}   
