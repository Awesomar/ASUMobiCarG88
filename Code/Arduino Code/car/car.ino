#include<NewPing.h> 
void Forward () ;
void Backward () ;
void Right () ;
void Left () ; 
void Stop () ;
void EasyDrive () ;
float ReadPing ();
const int motorA1 = 7;
const int motorA2 = 6;
const int motorB1 = 5;
const int motorB2 = 4;
char state ;
float distance ;
#define trig A0
#define echo A1
NewPing sonar(trig, echo, 250)



void setup() {
  Serial.begin(9600);
pinMode(motorA1, OUTPUT);
pinMode(motorA2, OUTPUT);
pinMode(motorB1, OUTPUT);
pinMode(motorB2, OUTPUT);

}

void loop() {
  distance = ReadPing () ;
    if (distance<=30)
    {
      Stop ();
    }
  if(Serial.available()>0)
  {
state = Serial.read();
    }
    switch(state)
    {
    case'f' : Forward(); break;
    case'b' : Backward(); break;
    case'l' : Left(); break;
    case'r' : Right(); break;
    case's' : Stop(); break;
    case'e' : EasyDrive(); break;
    default : Stop();
    
    }
}
void Forward ()
{
  Serial.println(state);
digitalWrite(motorA1, HIGH); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW);
}
void Backward ()
{
  Serial.println(state);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, HIGH);
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, HIGH);
}

void Right ()
{
  Serial.println(state);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW); 
}
void Left () 
{
  Serial.println(state);
digitalWrite(motorA1, HIGH); 
digitalWrite(motorA2, LOW);
digitalWrite(motorB1, LOW);
digitalWrite(motorB2, LOW); 
}
void Stop () 
{
  Serial.println(state);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, LOW);
}
void EasyDrive ()
{
  Forward () ;
  if (distance <=30)
  {Stop();}
}
float ReadPing ()
{
  delay(70);
float cm= sonar.ping_cm();
if (cm==0)
  cm = 250;
return cm;
}
