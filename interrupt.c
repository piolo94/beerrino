interrupt.c
#include <wiringPi.h>
int main(){
wiringPiSetup();
pinMode(0,OUTPUT);digitalWrite(0,HIGH);
delay(1000);
digitalWrite(0,LOW);return 0;
}
