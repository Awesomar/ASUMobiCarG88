void setup() {
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);

}

void loop() {

  digitalWrite(4, 1);
  delay(1000);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  delay(1000);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  delay(1000);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delay(1000);
  digitalWrite(7, 0);
  digitalWrite(7, 1);
  delay(1000);
  digitalWrite(7, 0);
  digitalWrite(6, 1);
  delay(1000);
  digitalWrite(6, 0);
  digitalWrite(5, 1);
  delay(1000);
  digitalWrite(5, 0);
 
}
