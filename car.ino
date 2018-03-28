const int motorA1 = 7;
const int motorA2 = 6;
const int motorB1 = 5;
const int motorB2 = 4;
int state = '0';
void setup() {
pinMode(motorA1, OUTPUT);
pinMode(motorA2, OUTPUT);
pinMode(motorB1, OUTPUT);
pinMode(motorB2, OUTPUT);

}

void loop() {
  if(state=='f'){ // forward
analogWrite(motorA1, HIGH); 
analogWrite(motorA2, LOW); 
analogWrite(motorB1, HIGH); 
analogWrite(motorB2, LOW);
  }
if(state=='b'){ // Backward
analogWrite(motorA1, LOW); 
analogWrite(motorA2, HIGH);
analogWrite(motorB1, LOW); 
analogWrite(motorB2, HIGH); 
}
if(state=='r'){ // Right
analogWrite(motorA1, LOW); 
analogWrite(motorA2, LOW); 
analogWrite(motorB1, HIGH); 
analogWrite(motorB2, LOW); 
}
if(state=='l'){ // Left
analogWrite(motorA1, HIGH); 
analogWrite(motorA2, LOW);
analogWrite(motorB1, LOW);
analogWrite(motorB2, LOW); 
} 
if(state=='s'){ // Stop
analogWrite(motorA1, LOW); 
analogWrite(motorA2, LOW); 
analogWrite(motorB1, LOW); 
analogWrite(motorB2, LOW);
}
