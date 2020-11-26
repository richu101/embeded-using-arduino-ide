
ISR(INT0_vect)
{
    if (PINE &= ~(1<<4))
    {
        PORTB |= (1 << 7);
    }
    else
    {
        PORTB |= (0 << 7);
    }
}

void intrrept_init()
{
    EIMSK |= (1<<INT0);
    EICRA |= (1<<ISC00);
    sei();
}

void setup()
{

    DDRB |= (1 << 7) | (1 << 6);
    PORTE |= (1 << 3); //enabling the internal pull up
    intrrept_init();
}

void loop()
{
    PORTB ^= (1<<6);
    delay(1000);
}
