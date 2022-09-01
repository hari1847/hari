
#include <Arduino.h>
bool  X,Y,Z;
int P[4],Q[4];
 int D,C,B,A;
void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(13, A); //LSB
  digitalWrite(12, B);
  digitalWrite(11, C);
  digitalWrite(10, D); //MSB
}

void setup()
{
    pinMode(2,  INPUT);
    pinMode(3,  INPUT);
    pinMode(4,  INPUT);
    pinMode(5,  INPUT);
    pinMode(6,  INPUT);
    pinMode(7,  INPUT);
    pinMode(8,  INPUT);
    pinMode(9,  INPUT);
    pinMode(10,  OUTPUT);
    pinMode(11,  OUTPUT);
    pinMode(12,  OUTPUT);
    pinMode(13,  OUTPUT);
}
void loop()
{

P[0] = digitalRead(2);
P[1] = digitalRead(3);
P[2] = digitalRead(4);
P[3] = digitalRead(5);
Q[0] = digitalRead(6);
Q[1] = digitalRead(7);
Q[2] = digitalRead(8);
Q[3] = digitalRead(9);
X  =((!(P[3] ^ Q[3])) && (!(P[2] ^ Q[2])) && (!(P[1]^ Q[1])) && (!(P[0] ^ Q[0])));  //A=B
Y  = ((P[3]&&!(Q[3])) || (!(P[3] ^ Q[3])&&P[2]&&!(Q[2])) || (!(P[3]^Q[3])&&!(P[2]^Q[2])&&P[1]&&!(Q[1])));  //A>B
Z  =(!P[3]&&Q[3]) || (!(P[3]^Q[3])&&(!(P[2]^Q[2])) && !P[1] && Q[1]) ||  (!(P[3]^Q[3])&&(!(P[2]^Q[2])) && !P[0] && Q[0] &&(!(P[1]^Q[1])));  //A<B
if(X){
D=0;C=0;A=1;B=1;
}
if(Z){
D=0;C=0;A=1;B=0;
}if(Y){
D=0;C=1;A=0;B=1;
}
disp_7447(D,C,B,A);
}
