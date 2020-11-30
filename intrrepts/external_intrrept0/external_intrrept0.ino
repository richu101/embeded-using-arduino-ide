ISR(INT4_vect)
{
    if (bit_is_set(PINE,4)) // When the pin change the state low to high then the led will turn on
    {
        PORTB |= (1 << 7);
        _delay_ms(500);
        Serial.println("am in the intrrept");
        PORTB &= (0 << 7);
        _delay_ms(500);
    }
    else
    {
        PORTB &= ~(1 << 7);
        Serial.print("0");
    }
    
}

void intrrept_init(void)
{ 
    // This function is to initilize the intrrepts
    EIMSK |= (1<<INT4);
    EICRB |= (1<<ISC40);
    sei();
}


void setup()
{
    Serial.begin(9600);
    DDRB |= 0xff; // set DDRB pins as 
    DDRE |= (0<<2)  | (0<<3);
     //PORTE |= (1<<4) ; //enabling the internal pull up
    //desabled the intrrepts
    intrrept_init();
    
}

void loop()
{
     delay(1000);
     PORTB ^= (1<<6);
    
}


