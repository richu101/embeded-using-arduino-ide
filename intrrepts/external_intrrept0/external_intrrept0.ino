
ISR(INT_vect)
{
    if (bit_is_clear(PINE, PE4))
    {
        PORTB |= (1 << 6);
    }
    else
    {
        PORTB |= (1 << 6);
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
    PORTE |= (1 << 4); //enabling the internal pull up
}

void loop()
{
    PORTB ^= (1<<7);
    delay(500);
}
