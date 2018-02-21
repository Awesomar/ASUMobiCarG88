const int led = 10;

void setup() {
pinMode(led, OUTPUT);
}

void loop() {
digitalWrite(led, 1);
delay(500);
digitalWrite(led, 0);
delay(1500);
}
