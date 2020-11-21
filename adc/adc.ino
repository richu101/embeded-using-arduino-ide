static inline void adc0init(void)
{
    ADMUX  |= (1<<REFS0);
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
    ADCSRA |= (1<<ADEN);
}
void setup() 
{
    uint16_t adcval;
    adc0init();
    Serial.begin(9600);
}

void loop() 
{
    ADCSRA |= (1<<ADCSC);
    loop_until_bit_is_clear(ADCSRA,ADSC);
    adcval = ADCH;
    Serial.println(adcval);
    delay(1);    
}
