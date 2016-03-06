/*
 * tng.c
 *
 * Created: 3/6/2016 12:37:13 PM
 *  Author: Marius
 */ 

// 9.6 MHz, built in resonator
#define F_CPU 9600000UL
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <math.h>

#define LED PB1
#define ARRAY {106, 141, 145, 189, 175, 175, 170, 153, 175, 119, 220, 206, 208, 123, 143, 117, 128, 158, 169, 174, 213, 129, 122, 155, 196, 181, 174, 179, 245, 242, 236, 238, 227, 138, 246, 227, 123, 234, 179, 212, 188, 224, 215, 109, 154, 211, 190, 163, 245, 222, 251, 111, 215, 111, 152, 233, 191, 222, 134, 198, 114, 203, 177, 245, 221, 218, 107, 165, 212, 172, 131, 189, 110, 221, 236, 220, 163, 225, 114, 235, 194, 206, 111, 178, 114, 217, 182, 160, 177, 146, 110, 220, 150, 130, 235, 133, 186, 116, 163, 246, 244, 171, 219, 135, 195, 235, 224, 189, 196, 118, 217, 118, 165, 249, 133, 220, 188, 136, 177, 154, 179, 244, 217, 214, 159, 110, 120, 113, 217, 145, 109, 254, 161, 235, 190, 138, 100, 184, 195, 167, 151, 163, 186, 106, 206, 170, 135, 103, 205, 247, 127, 252, 252, 112, 136, 223, 134, 219, 181, 202, 190, 201, 149, 105, 167, 110, 189, 168, 203, 192, 163, 114, 120, 217, 190, 243, 250, 233, 200, 215, 176, 180, 174, 212, 229, 185, 234, 124, 247, 237, 220, 251, 173, 226, 165, 117, 103, 135, 108, 136, 237, 244, 248, 170, 237, 249, 148, 124, 134, 154, 142, 223, 108, 167, 252, 247, 253, 185, 192, 134, 159,223,145,182,127,198,192,197,102,126,181,194,204,133,196,164,132,204,147,115,142,237,247,167,231,100,189,189,107,159,157,220,123,250};
//
//void adc_setup (void)
//{
	//// Set the ADC input to PB2/ADC1
	//ADMUX |= (1 << MUX0);
	//ADMUX |= (1 << ADLAR);
//
	//// Set the prescaler to clock/128 & enable ADC
	//ADCSRA |= (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN);
//}
//
//int adc_read (void)
//{
	//// Start the conversion
	//ADCSRA |= (1 << ADSC);
//
	//// Wait for it to finish
	//while (ADCSRA & (1 << ADSC));
//
	//return ADCH;
//}
void pwm_setup(void)
{
	// Set Timer 0 prescaler to clock/8.
	// At 9.6 MHz this is 1.2 MHz.
	TCCR0B |= (1 << CS01) | (1 << CS00);
	// Set to 'Fast PWM' mode
	TCCR0A |= (1 << WGM01) | (1 << WGM00);

	// Clear OC0B output on compare match, upwards counting.
	TCCR0A |= (1 << COM0B1);
}
void pwm_write (int val)
{
	OCR0B = val;
}
//// Assumes 0 <= max <= RAND_MAX
//// Returns in the half-open interval [0, max]
//long random_at_most(long max) {
	//unsigned long
	//// max <= RAND_MAX < ULONG_MAX, so this is okay.
	//num_bins = (unsigned long) max + 1,
	//num_rand = (unsigned long) RAND_MAX + 1,
	//bin_size = num_rand / num_bins,
	//defect   = num_rand % num_bins;
//
	//long x;
	//do {
		//x = random();
	//}
	//// This is carefully written not to overflow
	//while (num_rand - defect <= (unsigned long)x);
//
	//// Truncated division is intentional
	//return x/bin_size;
//}
unsigned int rand_interval(unsigned int min, unsigned int max)
{
    int r;
    const unsigned int range = 1 + max - min;
    const unsigned int buckets = RAND_MAX / range;
    const unsigned int limit = buckets * range;

    /* Create equal size buckets all in a row, then fire randomly towards
     * the buckets until you land in one of them. All buckets are equally
     * likely. If you land off the end of the line of buckets, try again. */
    do
    {
        r = rand();
    } while (r >= limit);

    return min + (r / buckets);
}
int main(void)
{
   // int adc_in;
  // uint8_t howBright[255] = ARRAY
   uint8_t rando = 0;
  // uint8_t i = 0;
    // LED is an output.
    DDRB |= (1 << LED);
  //  adc_setup();
    pwm_setup();
    while (1) {
	    // Get the ADC value
	  //  adc_in = adc_read();
	    // Now write it to the PWM counter
		//rando = random_at_most(254);
		//howBright = (rando > 128)?rando : (rando+128);     // Change brightness to something between 128 and 255 
		//for(i=0; i<255;i++)
		//{
			rando = rand_interval(50, 254);
			pwm_write(rando);
			//rando = random_at_most(150);
			_delay_ms(100);
		//}
    }
}