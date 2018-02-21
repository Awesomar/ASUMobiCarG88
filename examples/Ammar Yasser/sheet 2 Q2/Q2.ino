const int A = 13;
const int B = 12;
const int C = 11;
const int D = 10;
const int E = 9;
const int F = 8;
const int G = 7;
const int H = 6;

int s1state;
int s2state;
int s3state;
int s4state;
int s5state;
int s6state;
int s7state;
int s8state;
int value;
void setup() {
pinMode(3, OUTPUT);
  // pins for switches are inputs
pinMode(A, INPUT);
pinMode(B, INPUT);
pinMode(C, INPUT);
pinMode(D, INPUT);
pinMode(E, INPUT);
pinMode(F, INPUT);
pinMode(G, INPUT);
pinMode(H, INPUT);
}

void loop() {
s1state=digitalRead(A);
s2state=digitalRead(B);
s3state=digitalRead(C);
s4state=digitalRead(D);
s5state=digitalRead(E);
s6state=digitalRead(F);
s7state=digitalRead(G);
s8state=digitalRead(H);
delay(50);
value = 4*(s1state*1 + s1state*2 + s1state*4 + s1state*8 + s1state*16 + s1state*32 + s1state*64 + s1state*132) ;
digitalWrite(3, 1);
delay(value);
digitalWrite(3,0);
delay(value);
}
