static inline void adc0init(void)
{
    ADMUX  |= (1<<REFS0);
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
    ADCSRA |= (1<<ADEN);
}
void setup() 
{
    adc0init();
}

void loop() 
{
    
}
