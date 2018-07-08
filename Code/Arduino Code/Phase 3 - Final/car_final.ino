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
