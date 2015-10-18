/*
 * Piatra.c
 *
 * Created: 3/19/2015 6:42:19 PM
 *  Author: Marius
 */ 



/*------------Includes-------------*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "/AtmelRepos/Piatra/Piatra/Headers/main.h"
#include "/AtmelRepos/Piatra/Piatra/Headers/ADC.h"
#include "/AtmelRepos/Piatra/Piatra/Headers/PWM.h"
#include "/AtmelRepos/Piatra/Piatra/Headers/USART.h"
#include "/AtmelRepos/Piatra/Piatra/Headers/Armanag.h"
#include <util/delay.h>

/*------------Declarations----------*/
uint8_t state;

/*---------------------prototypes--------------------------*/
void dim(uint8_t bec);
void flash(void);


int main(void)
{	
	DDRB |=  (1<<DDB5) ;
	pwm_init();                            //PWM init
	

    while(1)
    {
		dim(1);
		dim(2);
		flash();
    }
}

void dim(uint8_t bec)
{
	uint8_t i = 0;
	
	switch(bec)
	{
		case 1:
		{
				for(i = 0; i < 255; i++)
				{
					setOC1A(i);
					_delay_ms(3);
					
				}
				for(i = 255; i > 0; i--)
				{
					setOC1A(i);
					_delay_ms(3);
				}
		}
		break;
		case 2: 
		{
				for(i = 0; i < 255; i++)
				{
					setOC1B(i);
					_delay_ms(3);
				}
				for(i = 255; i > 0; i--)
				{
					setOC1B(i);
					_delay_ms(3);
				}
		}
		break;
		default:
		{
			for(i = 0; i < 255; i++)
			{
				setOC1B(i);
				setOC1A(i);
				_delay_ms(10);
			}
			for(i = 255; i > 0; i--)
			{
				setOC1B(i);
				setOC1A(i);
				_delay_ms(10);
			}
		}
	}

	
}
void flash(void)
{
	uint8_t i = 0;
	for(i = 0;i<10;i++)
	{
		setOC1A(255);
		_delay_ms(80);
		setOC1B(255);
		_delay_ms(20);
		setOC1A(0);
		_delay_ms(80);
		setOC1B(0);
		_delay_ms(20);
	}
	
}

