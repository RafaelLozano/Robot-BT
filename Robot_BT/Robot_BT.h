#include <SoftwareSerial.h>//Libreria para nuevo puerto serial para el bluetooth
#include "Base_Robot.h"
class Robot_BT
{
  private:
  Base_Robot Robot;
  SoftwareSerial Bluetooth; // RX, TX
  
  public:
  Robot_BT(int Pin_Motor_1A,int Pin_Motor_1B,int PWM_1, int Pin_Motor_1C, int Pin_Motor_1D,int PWM_2,int TX, int RX): Robot(Pin_Motor_1A, Pin_Motor_1B, PWM_1, Pin_Motor_1C, Pin_Motor_1D, PWM_2), Bluetooth(TX,RX){}
  void Inicializar();
  char Leer_BT();
  void Modo_Bluetooth();
};

