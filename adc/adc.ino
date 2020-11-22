static inline void adc0init(void)
{
    ADMUX  |= (1<<REFS0);     // Refference voltage on avcc               
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); //set adc clock at 125 Khz
    ADCSRA |= (1<<ADEN);    //enable the adc
    ADMUX  |= (1<<ADLAR);   // left adjust the result
}

static inline void adcfrnit(void)    // initilize adc free running mode
{
    ADMUX  |= (1<<REFS0);     // Refference voltage on avcc               
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); //set adc clock at 125 Khz  

    ADMUX  |= (1<<ADLAR);   // left adjust the result

    ADCSRA |= (1<<ADEN);
    ADCSRA |= (1<<ADATE); //auto trigering enable 
    ADCSRA |= (1<<ADSC);  //adc start convertion

}
  uint16_t adcval;
void setup() 
{
  
    adc0init();
    // adcfrnit();
    Serial.begin(9600);
}

void loop() 
{
     ADCSRA |= (1<<ADSC);
     loop_until_bit_is_clear(ADCSRA,ADSC);
    adcval = (ADC>>6);
    Serial.println(adcval);
    delay(1);    
}
