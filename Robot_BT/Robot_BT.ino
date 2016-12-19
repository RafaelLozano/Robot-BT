/*
 * Talos Electronics
 * Tgo. Rafael Lozano Rolon 
 * Modificado por ultima vez 12 Diciembre 2016
 * Para inicializar el Robot BT se necesita definir los pines de la siguiente manera
 * Robot Nombre_Robot(In1,In2,Vss1-2,IN3,IN4,Vss3-4,TX_Bluetooth,RX_Bluettoth)
 * 
 *     /////////////////Parametros///////////////
 *    /            Puente H                     /
 *    /    Parametro -> Numero de pin           /
 *    /    IN1       ->     2                   /
 *    /    In2       ->     7                   /   
 *    /    Vss1-2    ->     1                   /  
 *    /    In3       ->     10                  /   
 *    /    In4       ->     15                  /                                      
 *    /    Vss3-4    ->     9                   /           
 *    / ----------------------------------------/     
 *    /         Modulo Bluetooth                /     
 *    /    Parametro -> Numero de pin           /       
 *    /    TX        ->    TX(3)                /       
 *    /    RX        ->    RX(2)                /             
 *    //////////////////////////////////////////
 */
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
