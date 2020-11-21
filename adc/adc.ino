static inline void adc0init(void)
{
    ADMUX  |= (1<<REFS0);
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
    ADCSRA |= (1<<ADEN);
    ADMUX  |= (1<<ADLAR);
}
  uint16_t adcval;
void setup() 
{
  
    adc0init();
    Serial.begin(9600);
}

void loop() 
{
    ADCSRA |= (1<<ADSC);
    loop_until_bit_is_clear(ADCSRA,ADSC);
    adcval = ADC;
    Serial.println(adcval);
    delay(1);    
}
