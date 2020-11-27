ISR(INT4_vect)
{
    if (bit_is_set(PINE,4))
    {
        PORTB |= (1 << 7);
    }
    else
    {
        PORTB &= ~(1 << 7);
    }
    
}



void intrrept_init(void)
{
    EIMSK |= (1<<INT4);
    EICRB |= (1<<ISC40);
    sei();
}


void setup()
{

    DDRB |= 0xff; // set DDRB pins as 
    DDRE |= (0<<2)  | (0<<3);
    PORTE |= (1<<4) ; //enabling the internal pull up
    intrrept_init();
}

void loop()
{
     delay(100);
     PORTB ^= (1<<6);
    
   
}


