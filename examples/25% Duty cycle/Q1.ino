const int led = 10;

void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led, 1);
delay(250);
digitalWrite(led, 0);
delay(1750);
}
