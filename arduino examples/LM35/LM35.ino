void setup() {
  Serial.begin(9600);
}

void loop() {
  
  float temp = analogRead(A0);
  temp = (temp / 1023.) * 5 * 100;
  Serial.println(temp);
  delay(1000); //delays 1 second
  
}
