#include <NewPing.h>

// Bluetooth MAC address
// 00:21:13:00:E0:D7 

void Forward(), Backward(), Right(), Left(), Stop(), Rotate(int c), EasyDrive(), Follower(), 
     Distance(int number), Angle(int angle), Square(), Circle(bool dir, int x, int y, int z), Infinity(), Demo(), Phase1(), Phase2(), Phase3(), Left2(), Right2();
int ReadPing ();
int max_counts; 
const int motorA1 = 7;
const int motorA2 = 6;
const int motorB1 = 5;
const int motorB2 = 4;
const int enA = 10;
const int enB = 11;
int velocity = 100;
int counter = 0;
char state = 0;
int dist, number;
int MS,LS,RS,MSV,LSV,RSV;
#define trig A0
#define echo A1
int distance;
char s= 's';

NewPing sonar(trig, echo, 250);


void setup()
{
  Serial.begin(9600);
  attachInterrupt(0, sensor, RISING);
}

void loop()
{
  if(Serial.available()>0) 
  {
    state = Serial.read();
  }
  
  switch (state)
  {
      case 'A' :
        Phase1();
        state = 0;
        break;
        
      case 'B' :
        Phase2();
        state = 0;
        break;
        
      case 'C' :
        Phase3();
        state = 0;
        break;
      
      default: Stop();
    }
}

void Phase1()
{
  Serial.println("Phase1");
  int numb;
  while(true)
  {
    if (Serial.available() > 0)
      state = Serial.read();
  /*  
    while (Serial.available() == 0);
    state = Serial.read();
    numb = Serial.parseInt();
   */
    switch (state)
    {
      //case 'R': Rotate(numb); break;
        
      case 'f' :
          Forward();
          Serial.println("Forward()");
          //delay(10);
          //state = 0;
          break;
          
      case 'b' :
          Backward();
          Serial.println("Backward()");
          //delay(10);
          //state = 0;
          break;
          
      case 'l' :
          Left();
          Serial.println("Left()");
          //delay(10);
          //state = 0;
          break;
        
      case 'r' :
          Right();
          Serial.println("Right()");
          //delay(10);
          //state = 0;
          break;

      case 's' : Stop(); break;

      case 'e' : EasyDrive(); break;
  
          
      case 'B' :
          Phase2();
          state = 0;
          break;
          
       case 'C' :
          Phase3();
          state = 0;
          break;
        
       default: Stop();
      }
  }
}

void Distance(int number)
{
  Serial.print("Distance = ");
  Serial.println(number);
  
  counter = 0;
  while (dist < number)
  {
    Forward();

  }
  Stop();
  delay(1000);
  counter = 0;
}
void Angle(int angle)
{
  Serial.print("Angle = ");
  Serial.println(angle);

  counter = 0;
  
  max_counts = angle * 28 * 2 / 360;
  
  Rotate(max_counts);
  Stop();
  delay(1000);
  counter = 0;
}

void Square()
{
  Serial.println("Square");
  
  for (int i = 0; i < 8; i++)
  {
    Distance(200);
    if (i < 4)
      Rotate(10 + 2*i);
    if (i >= 4)
      Rotate(11);
    Serial.print("i= ");
    Serial.println(i);
  }
}

void Circle(bool dir, int x, int y, int z)
{
  // Circumference = 6.28318530718
  
  Serial.println("Circle");
  
  while(counter < z)
  //while(dist < 6.28318530718)
  {
    switch (dir)
    {
      case 0: //Right
          analogWrite(enA, x);
          analogWrite(enB, y);
          
          digitalWrite(motorA1, HIGH); 
          digitalWrite(motorA2, LOW); 
          digitalWrite(motorB1, HIGH); 
          digitalWrite(motorB2, LOW); 
      
      case 1: //Left
          analogWrite(enA, y);
          analogWrite(enB, x);
          
          digitalWrite(motorA1, HIGH); 
          digitalWrite(motorA2, LOW); 
          digitalWrite(motorB1, HIGH); 
          digitalWrite(motorB2, LOW); 
      
    }
  }
  Stop();
  delay(500);
  counter = 0;
}

void Infinity()
{
  Circle(true, 90, 170, 100);
  Stop();
  delay(1000);
  Circle(false, 90, 170, 100);
  Stop();
}

