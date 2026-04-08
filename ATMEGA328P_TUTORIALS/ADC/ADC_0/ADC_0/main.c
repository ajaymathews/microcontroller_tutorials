 /*
 * ADC_0.c
 *
 * Created: 04-06-2019 00:11:59
 * Author : [Developer]
 
 
 ADCSRA->ADEN:1 //ADC TURNING  ON/OFF
 ADSRA->ADIE:1//TURN ADC INTERRPT ON
 ADSRA->ADPS2,ADPS1,ADPS0:1 //PRESCLR FOR ADC, SET THE '/128'(MAX)
 ADSRA->ADSC: 1,  TO START CONVERSION
 DIDR0:ADC5D:1//DISABLIN THE SELECTD ADC PIN, DIGITAL OUTPUT,SO THAT ADC WORKS SMOOTHLY AND LESS POWER
 
 ADMUX->REFS0=1 //EXTERNAL AVCC
 ADMUX->MUX2=1 //SELECTING CHANNEL AD5
 ADMUX->MUX0=1 //SELECTING CHANNEL AD5
 
 ADLAR=0, THE ARRNGMNT OF DATA IN ADC REG
 
 ADC 9:0 CONTAINS THE RESULT
 
 ADSC WILL BE 1 AS LONG AS CONVERSION GOING ON, 0 IF CONVERSION STOPS.
 ADC DATA IN ADCH,ADCL REG
 BEFORE ADCH READ CONV COMPLETS,AFTER READ RENABLE
 IF LESS THAN 8BIT CONV, DATA IN ADCH. ELSE ADCL&ADCH
  ADCSRA->ADTA:1 //AUTO TRIGGER ADC
 
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000L
#include <util/delay.h>
double DutyCycle=50;
void pwm_init()
{
	DDRD=1<<PORTD6;
	TCCR0A=((1<<COM0A1)|(1<<WGM00)|(1<<WGM01));//SETTTING FAST PWM AND WHEN RESET TART FROM BOTTOM
	TCCR0B=((1<<CS02)|(1<<CS00));//PRESCALR
}
void pwm_interrupt()
{
	TIMSK0=(1<<TOIE0);//INTERRUPT ON OVER FLOW
	sei();//SETTING EXTERNAL INTERRUPT
}

void adc_init()
{
	 ADCSRA=(1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	 DIDR0=(1<<ADC5D);	 
	 ADMUX=(1<<REFS0)|(1<<MUX2)|(1<<MUX0);
	 
}
void adc_start_conversion()
{
	 ADCSRA|=(1<<ADSC);
	 
}

int main(void)
{
	DDRB=1<<PORTB7; //OUTPUT AS B7
	PORTB=1<<PORTB7;//SETTING HIGH B7
	PORTB^=(1<<PORTB7); // NEGETAION

	pwm_init();
	adc_init();
	adc_start_conversion();
	pwm_interrupt();
	
	
	//OCR0A=(DutyCycle*255)/100;
    while (1) 
    {
		
		
    }
}
ISR(TIMER0_OVF_vect)
{
	PORTB^=(1<<PORTB7);
	OCR0A=DutyCycle;//no need of conversion since adc output is already 10 bits,and ocroa read only 8 bits from that.
}
ISR(ADC_vect)
{
	DutyCycle=ADC;//ADC VALUE IN ADC REG, WHICH IS OF 0-255
    adc_start_conversion();//each time it needs to start, because we didnt set free running
	
}
