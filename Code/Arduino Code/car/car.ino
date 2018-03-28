const int motorA1 = 7;
const int motorA2 = 6;
const int motorB1 = 5;
const int motorB2 = 4;
int state = '0';

void setup() {
  Serial.begin(9600);
pinMode(motorA1, OUTPUT);
pinMode(motorA2, OUTPUT);
pinMode(motorB1, OUTPUT);
pinMode(motorB2, OUTPUT);

}

void loop() {
  if(Serial.available()>0){
state = Serial.read();
    }
    if(state=='f'){// forward
      Serial.println(state);
digitalWrite(motorA1, HIGH); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW);
  }
if(state=='b'){ // Backward
  Serial.println(state);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, HIGH);
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, HIGH); 
}
if(state=='r'){ // Right
  Serial.println(state);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, HIGH); 
digitalWrite(motorB2, LOW); 
}
if(state=='l'){ // Left
  Serial.println(state);
digitalWrite(motorA1, HIGH); 
digitalWrite(motorA2, LOW);
digitalWrite(motorB1, LOW);
digitalWrite(motorB2, LOW); 
} 
if(state=='s'){ // Stop
  Serial.println(state);
digitalWrite(motorA1, LOW); 
digitalWrite(motorA2, LOW); 
digitalWrite(motorB1, LOW); 
digitalWrite(motorB2, LOW);
}
}
