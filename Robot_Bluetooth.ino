#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(2, 3); // RX, TX

int Estado;
int Motor1_A=4;
int Motor1_B=5;
int Velocidad_Motor1=6;
int Motor2_A=7;
int Motor2_B=8;
int Velocidad_Motor2=9;
int Velocidad=255;

void Adelante();
void Atras();
void Derecha();
void Izquierda();
void Stop();
void Arriba_Derecha();
void Arriba_Izquierda();
void Abajo_Derecha();
void Abajo_Izquierda();

void setup()
{
  // Open serial communications and wait for port to open:
  Bluetooth.begin(9600);
  Serial.begin(9600);
  pinMode(Motor1_A,OUTPUT);
  pinMode(Motor1_B,OUTPUT);
  pinMode(Velocidad_Motor1,OUTPUT);
  pinMode(Motor2_A,OUTPUT);
  pinMode(Motor2_B,OUTPUT);
  pinMode(Velocidad_Motor2,OUTPUT);
  
}

void loop()
{ 
  
  if (Bluetooth.available() > 0) 
  {
    Estado = Bluetooth.read();
  }
  if(Estado=='1')
  {
    Serial.println("Arriba izquierda");
    Arriba_Izquierda();
  }
  if(Estado=='2')
  {
    Serial.println("Arriba");
   Adelante();
  }
  if(Estado=='3')
  {
    Serial.println("Arriba derecha");
    Arriba_Derecha();
  }
  if(Estado=='4')
  {
    Serial.println("Izquierda");
    Izquierda();
  }
  if(Estado=='5')
  {
    Serial.println("Logo talos");
    
  }
  if(Estado=='6')
  {
    Serial.println("Derecha");
    Derecha();
  }
  if(Estado=='7')
  {
    Serial.println("Abajo izquierda");
    Abajo_Izquierda();
  }
  if(Estado=='8')
  {
    Serial.println("Abajo");
    Atras();
  }
  if(Estado=='9')
  {
    Serial.println("Abajo Derecha");
    Abajo_Derecha();
  }
  if (Estado=='w')
  {
    Stop();
  }
  delay(100);
  
}

void Adelante()
{
  analogWrite(Velocidad_Motor1,Velocidad);
  analogWrite(Velocidad_Motor2,Velocidad);
  digitalWrite(Motor1_A,HIGH);
  digitalWrite(Motor1_B,LOW);
  digitalWrite(Motor2_A,LOW);
  digitalWrite(Motor2_B,HIGH);
}

void Izquierda()
{
  analogWrite(Velocidad_Motor1,Velocidad);
  analogWrite(Velocidad_Motor2,Velocidad);
  digitalWrite(Motor1_A,LOW);
  digitalWrite(Motor1_B,HIGH);
  digitalWrite(Motor2_A,LOW);
  digitalWrite(Motor2_B,HIGH);
  
}
void Derecha()
{
  analogWrite(Velocidad_Motor1,Velocidad);
  analogWrite(Velocidad_Motor2,Velocidad);
  digitalWrite(Motor1_A,HIGH);
  digitalWrite(Motor1_B,LOW);
  digitalWrite(Motor2_A,HIGH);
  digitalWrite(Motor2_B,LOW);
 }
void Atras()
{
  analogWrite(Velocidad_Motor1,Velocidad);
  analogWrite(Velocidad_Motor2,Velocidad);
  digitalWrite(Motor1_A,LOW);
  digitalWrite(Motor1_B,HIGH);
  digitalWrite(Motor2_A,HIGH);
  digitalWrite(Motor2_B,LOW);
}
void Stop()
{
  analogWrite(Velocidad_Motor1,Velocidad);
  analogWrite(Velocidad_Motor2,Velocidad);
  digitalWrite(Motor1_A,LOW);
  digitalWrite(Motor1_B,LOW);
  digitalWrite(Motor2_A,LOW);
  digitalWrite(Motor2_B,LOW);
}
void Arriba_Derecha()
{
  analogWrite(Velocidad_Motor1,Velocidad);
  analogWrite(Velocidad_Motor2,Velocidad/2);
  digitalWrite(Motor1_A,HIGH);
  digitalWrite(Motor1_B,LOW);
  digitalWrite(Motor2_A,LOW);
  digitalWrite(Motor2_B,HIGH);
}
void Arriba_Izquierda()
{
  analogWrite(Velocidad_Motor1,Velocidad/2);
  analogWrite(Velocidad_Motor2,Velocidad);
  digitalWrite(Motor1_A,HIGH);
  digitalWrite(Motor1_B,LOW);
  digitalWrite(Motor2_A,LOW);
  digitalWrite(Motor2_B,HIGH);
}
void Abajo_Derecha()
{
  analogWrite(Velocidad_Motor1,Velocidad);
  analogWrite(Velocidad_Motor2,Velocidad/2);
  digitalWrite(Motor1_A,LOW);
  digitalWrite(Motor1_B,HIGH);
  digitalWrite(Motor2_A,HIGH);
  digitalWrite(Motor2_B,LOW);
}
void Abajo_Izquierda()
{
  analogWrite(Velocidad_Motor1,Velocidad/2);
  analogWrite(Velocidad_Motor2,Velocidad);
  digitalWrite(Motor1_A,LOW);
  digitalWrite(Motor1_B,HIGH);
  digitalWrite(Motor2_A,HIGH);
  digitalWrite(Motor2_B,LOW);
}

