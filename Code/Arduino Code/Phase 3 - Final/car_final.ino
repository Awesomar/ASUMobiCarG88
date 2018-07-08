void Phase1(), Phase2(), Phase3();


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
