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
