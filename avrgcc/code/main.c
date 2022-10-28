#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
int main(void)
{
bool a,b,c,d,p,q,r,s,x,y,z;
DDRB =  0b00111100;  // 13 pin as output
DDRD =  0b00000000;
PORTD = 0B11111111;
PORTD = 0B00000011;

while(1)
{
PORTB = 0b00000000;
s = (PINB & (1 << PINB1)) == (1 << PINB1);
r = (PINB & (1 << PINB0)) == (1 << PINB0);
q = (PIND & (1 << PIND7)) == (1 << PIND7);
p = (PIND & (1 << PIND6)) == (1 << PIND6);
d = (PIND & (1 << PIND5)) == (1 << PIND5);
c = (PIND & (1 << PIND4)) == (1 << PIND4);
b = (PIND & (1 << PIND3)) == (1 << PIND3);
a = (PIND & (1 << PIND2)) == (1 << PIND2);

x =(~(d|s))&&(~(c|r))&&(~(b|q))&&(!(a|p)); //A=B
y =((d&&s))|(~(d|s)&&(c&&~r))|(~(d|s)&(~(c|r))&&(b&&(~q))); //A>B
z =((d&&~(s))|(~(d|s)&&(~(c|r)))&&(~b&&q)|(~(d|s))&&(~(c|r))&&(a&&p)|(~(b|r)));//A<B
if(x)
{
PORTB |= 0b00110000;
break;
}
if(y)
{
PORTB |= 0b00010000;
break;
}
if(z)
{
PORTB |= 0b00100000;
break;
}

return 0;
}
}
