#include <Arduino.h>

#define pind2 PINE
#define pind3 PINE
#define pind4 PING
#define pind5 PINE

#define portd6 PORTH
#define portd7 PORTH
#define portd8 PORTH
#define portd9 PORTH

#define d2 PE4
#define d3 PE5
#define d4 PG5
#define d5 PE3
#define d6 PH3
#define d7 PH4
#define d8 PH5
#define d9 PH6
void setup()
{

    DDRE |= (0 << d2) | (0 << d3) | (0 << d5);
    DDRG |= (0 << d4);
    DDRH |= (1 << d6) | (1 << d7) | (1 << d8) | (1 << d9);
    Serial.begin(9600);
}

void loop()
{

if((pind2 & (1<<d2)))  //
{
    Serial.println("a");
    _delay_ms(5);
}



if((pind2 & (1<<d2)))  //
{
    Serial.println("a");
    _delay_ms(5);
}

else if((pind3 & (1 << d3)) ) // when pind4 enter the black line this fynction work 
{
    Serial.println("b");
    _delay_ms(5);
}
else if((pind4 & (1 << d4))) // when pind5 enter the black line this fynction work 
{
    Serial.println("d");
    _delay_ms(5);
}
else if((pind5 & (1 << d5))) // when pind5 enter the black line this fynction work 
{
    Serial.println("d");
    _delay_ms(5);
}

}