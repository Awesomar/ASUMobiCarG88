#include<NewPing.h> 

void Forward(), Backward(), Right(), Left(), Stop(), EasyDrive(), Follower(), Forward_Low(), Backward_Low(), Right_Low(), Left_Low();
float ReadPing ();
const int motorA1 = 7;
const int motorA2 = 6;
const int motorB1 = 5;
const int motorB2 = 4;
const int enA = 10;
const int enB = 11;
int MS,LS,RS,MSV,LSV,RSV;


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
pinMode(MS,INPUT);

}

void loop() {

LS = analogRead(A3);
if (LS < 200)
  LSV = 1; //black
  else
  LSV = 0; //white

Serial.println(LS);

MS = analogRead(A5);
if (MS < 200)
  MSV = 1; //black
  else
  MSV = 0; //white

Serial.print(MS);

 RS = analogRead(A4);
if (RS < 200)
  RSV = 1; //black
  else
  RSV = 0; //white
  
Serial.print(RS);


  
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
analogWrite(enA, 255);
analogWrite(enB, 255);
digitalWrite(motorA1, HIGH); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW);
}

void Backward ()
{
  Serial.println(state);
analogWrite(enA, 255);
analogWrite(enB, 255);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, HIGH);
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, HIGH);
}

void Right ()
{
  Serial.println(state);
analogWrite(enA, 255);
analogWrite(enB, 255);  
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW); 
}

void Left () 
{
  Serial.println(state);
analogWrite(enA, 255);
analogWrite(enB, 255);  
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

void Forward_Low ()
{
  Serial.println(state);
analogWrite(enA, 150);
analogWrite(enB, 150);
digitalWrite(motorA1, HIGH); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW);
}

void Backward_Low ()
{
  Serial.println(state);
analogWrite(enA, 150);
analogWrite(enB, 150);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, HIGH);
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, HIGH);
}

void Right_Low ()
{
  Serial.println(state);
analogWrite(enA, 150);
analogWrite(enB, 150);  
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW); 
}

void Left_Low () 
{
  Serial.println(state);
analogWrite(enA, 150);
analogWrite(enB, 150);  
digitalWrite(motorA1, HIGH); 
digitalWrite(motorA2, LOW);
digitalWrite(motorB1, LOW);
digitalWrite(motorB2, LOW); 
}


void EasyDrive ()
{
  Forward_Low () ;
  if (distance <=30)
  {
    Stop();
    delay(300);
    Backward_Low();
    delay(800);
    Stop();
    delay(300);
    Right_Low();
    delay(500);
    Stop();
    delay(300);
    Forward_Low();
  }
}
void Follower ()
{
if(!LSV && MSV && !RSV) //move forward
{
Serial. println( "forward" ) ;

Forward_Low();
}
if(!LSV && MSV && RSV) //move right
{
  Serial. println( "low right" ) ;
  Right_Low();
}

if(!LSV && !MSV && RSV) //move right
{
  Serial. println( "right" ) ;
  Right();
}

if(LSV && MSV && !RSV) //move left
{
  Serial. println( "low left" ) ;
  Left_Low();
}

if(LSV && !MSV && !RSV) //move left
{
  Serial. println( "left" ) ;
  Left();
}

if(LSV && MSV && RSV) //Stop
{
  Serial. println( "stop" ) ;
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
