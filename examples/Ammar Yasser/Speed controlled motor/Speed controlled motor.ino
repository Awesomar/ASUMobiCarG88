#include<LiquidCrystal.h>
LiquidCrystal lcd(6,5,4,3,2,1);

const int sw=0;
const int mf=9;
const int mb=8;
float val,sp,x;
int sww;


void setup() {
lcd.begin(16,2);
pinMode(mf,OUTPUT);
pinMode(mb,OUTPUT);

}

void loop() {
x=analogRead(A0) ;

sp=map(x,0,1023,0,255);

analogWrite(mf,sp);

digitalWrite(mb,0);
lcd.setCursor (0,0);
lcd.print("speed =");
lcd.print(sp);
delay(50);
lcd.clear();
delay(50);
}

