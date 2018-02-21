int pin1=1;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin1,HIGH);
  delay(500);
  digitalWrite(pin1,LOW);
  delay(1500);
}
