static inline void adc0init(void)
{
    ADMUX  |= (1<<REFS0);     // Refference voltage on avcc             
    
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); //set adc clock at 125 Khz
    ADCSRA |= (1<<ADEN);    //enable the adc
    ADMUX  |= (1<<ADLAR);   // left adjust the result
}


uint16_t readadc(uint8_t ch)
{
    ADMUX  |= (0xf0 & ADMUX) | ch ; // set which chnnel we need to start conversion 
    ADCSRA |= (1<<ADSC);
    loop_until_bit_is_clear(ADCSRA,ADSC);

  return(ADC>>6);  
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
    Serial.println(readadc(1)); //printing the adc value serialy
    delay(1);    
}




/* static inline void adcfrnit(void)    // initilize adc free running mode
{
    ADMUX  |= (1<<REFS0);     // Refference voltage on avcc               
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); //set adc clock at 125 Khz  

    ADMUX  |= (1<<ADLAR);   // left adjust the result

    ADCSRA |= (1<<ADEN);
    ADCSRA |= (1<<ADATE); //auto trigering enable 
    ADCSRA |= (1<<ADSC);  //adc start convertion

}
*/

https://github.com/arduino/Arduino/blob/bb7a044884f20d3b1d470cfb30b111a73dbee8e6/hardware/arduino/cores/arduino/HardwareSerial.cpp