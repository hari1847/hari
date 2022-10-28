.include "/home/hari/hari/assembly/codes/m328Pdef.inc"
ldi R16,0b00000000
out DDRD, R16
ldi R16,0b00111100
out DDRB,R16
ldi R16,0b11111111
out PORTB,R16
ldi R16,0b00000011
out PORTD,R16
start:
in R16,PIND
in R17,PINB
ldi R18,0b00111100
and R18,R16
LSR R18
LSR R18
ldi R19,0b11000000
and R19,R16
ldi R20,0b00000100
loop:
lsr R19
dec R20
brne loop
ldi R20,0b00000011
and R17,R20
or R19,R17 
SUB R18,R19
BREQ  print3
BRLO  print1
BRSH  print2
print3:
       ldi R23,0b00110000
       out PORTB,R23
	jmp start
print1:
       ldi R23,0b00100000
       out PORTB,R23
	jmp start
print2:
       ldi R23,0b00010000
       out PORTB,R23
	jmp start

