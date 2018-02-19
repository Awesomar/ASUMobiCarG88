void setup() {
  // put your setup code here, to run once:
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
for (int i=0;i<10;i++){

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
  digitalWrite(4, 1);
  delay(1000);
  digitalWrite(4, 0);
    }
}
