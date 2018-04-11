#include<NewPing.h> 

void Forward (), Backward (), Right (), Left (), Stop (), EasyDrive (), Follower();
float ReadPing ();
const int motorA1 = 7;
const int motorA2 = 6;
const int motorB1 = 5;
const int motorB2 = 4;
int enA = 3;
int enB = 5;
#define LS 12
#define RS 13
#define trig A0
#define echo A1

char state ;
float distance ;

NewPing sonar(trig, echo, 250);
  
void setup() {
  Serial.begin(9600);
pinMode(motorA1, OUTPUT);
pinMode(motorA2, OUTPUT);
pinMode(motorB1, OUTPUT);
pinMode(motorB2, OUTPUT);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(LS, INPUT);
pinMode(RS, INPUT);

}

void loop() {
  distance = ReadPing () ;
 
if(Serial.available()>0) {state = Serial.read();}
    switch(state)
    {
    case'f' : Forward(); break;
    case'b' : Backward(); break;
    case'l' : Left(); break;
    case'r' : Right(); break;
    case's' : Stop(); break;
    case'e' : EasyDrive(); break;
    case't' : Follower(); break;
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
analogWrite(enA, 150);
analogWrite(enB, 150);
  Forward () ;
  if (distance <=30)
  {
    Stop();
    delay(300);
    Backward();
    delay(800);
    Stop();
    delay(300);
    Right();
    delay(400);
    Stop();
    delay(300);
    Forward();
  }
}
void Follower ()
{
if(digitalRead(LS) && digitalRead(RS)) //move forward
{
analogWrite(enA, 100);
analogWrite(enB, 100);
Forward();
}
if(digitalRead(LS) && !digitalRead(RS)) //move right
{
  Right();
}
if(!digitalRead(LS) && digitalRead(RS)) //move left
{
  Left();
}

if(!digitalRead(LS) && !digitalRead(RS)) //Stop
{
Stop();
}


}



float ReadPing ()
{
  delay(70);
float cm= sonar.ping_cm();
if (cm==0)
  cm = 250;
return cm;
}
