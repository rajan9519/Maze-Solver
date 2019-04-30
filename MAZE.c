/* Line folower robot for white background and black strips*/
/* using only five sensors */

#define F_CPU 12000000UL
#include<avr/io.h>
#include<avr/delay.h>

int main()
{


    
	DDRD  = 0b11111111;
	PORTD = 0b11111111;
	DDRB  = 0b00000000;
	PINB  = 0b00000000;
	DDRC  = 0b11111111;
	PORTC = 0b00000000;
	while(1)
	{    

		if( PINB == 0b00100010 )
		{	// MOVE FORWARD
			PORTC = 0b00010100;
		}
		else if( PINB == 0b00000110 )
		{
			//MOVE FORWARD FOR 50ms
			PORTC = 0b00000100;
				// LEFT TURN
			if( PINB == 0b00111110 )
			{
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00001100;
				while( PINB == 00111110 )
				{}
			}
			// RIGHT TURN
			else if( PINB == 0b00000000 )
			{
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00010010;
				_delay_ms(1200);
			}
		}
		else if( PINB == 0b00110000 )
		{
			// MOVE FORWARD FOR 50ms
			PORTD &= (1<<7);
			PORTC = 0b000000100;
			_delay_ms(15);
			PORTC = 0b00010100;
			_delay_ms(15);
			// MOVE RIGHT
			if( PINB == 0b00111110 )
			{
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00010010;
				while( PINB == 0b00111110 )
				{}
			}
			// MOVE LEFT
			else if( PINB == 0b00000000 )
			{
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00001100;
				_delay_ms(1200);
			}
		}
		else if( PINB == 0b00100000 )
		{
			//MOVE FORWARD 
			PORTD &= (1<<7);
			PORTC = 0b00010100;
			_delay_ms(50);
			// LEFT TURN
			if(PINB == 0b00000000)
			{
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00001100;
				_delay_ms(1200);
			}
			else if( PINB == 0b00100000 )
			{	// MOVE FORWARD
				PORTC = 0b00010100;
				_delay_ms(300);
				//IF THERE IS BLACK LINE PRESENT do nothing just follow other instruction
				if ( PINB == 0b00100110 || PINB == 0b00100010 || PINB == 0b00110010 || PINB ==0b00011110 || PINB == 0b00100000 || PINB == 0b00001110 || PINB == 0b00111000 || PINB == 0b00000110 || PINB ==0b00110000)
				{
				}
				//otherwise take right turn if no black line is there
				else if( PINB == 0b00111110 )
				{
					PORTC = 0b00010010;
					while( PINB == 0b00111110 )
					{}
				}
			}
		}
		else if( PINB == 0b00000010)
		{	
			PORTC = 0b00010100;
			/*TAKE RIGHT ANGLE LEFT TURN*/
			PORTC = 0b00010100;
			_delay_ms(300);
			PORTC = 0b00001100;
			_delay_ms(1200);
		}
		else if(PINB == 0b00100110)
		{	/*turn on right motor turn off left motor*/
			PORTD = 0b00100000;
			PORTC = 0b00000100;
			if(PINB == 0b00000000)
			{
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00001100;
				_delay_ms(1200);
			}
		}
		else if(PINB == 0b00110010)
		{	/*turn on right motor turn off left motor*/
			PORTD = 0b00100000;
			PORTC = 0b00010000;
			if(PINB == 0b00000000)
			{
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00001100;
				_delay_ms(1200);
			}
		}
		else if(PINB == 0b00111100)
		{	/*turn on left motor turn off right motor*/
			PORTD = 0b10000000;
			PORTC = 0b00010000;
			_delay_ms(50);
			if( PINB == 0b00111110 )
			{
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00010010;
				while( PINB == 0b00111110 )
				{}
			}
			else if( PINB == 0b00000000 )
			{
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00001100;
				_delay_ms(1200);
			}
		}
		else if(PINB == 0b00011110)
		{	/*turn on right motor turn off left motor*/
			PORTD = 0b00100000;
			PORTC = 0b00000100;
			_delay_ms(50);
			// LEFT TURN
			if( PINB == 0b00111110 )
			{
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00001100;
				while( PINB == 0b00111110 )
				{}
			}
			// RIGHT TURN
			else if( PINB == 0b00000000 )
			{
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00010010;
				_delay_ms(1200);
			}
		}
		else if(PINB == 0b00001110)
		{	/*turn on RIGHT motor turn off LEFT motor*/
			PORTD = 0b10000000;
			PORTC = 0b000000100;
			_delay_ms(50);
			// LEFT TURN
			if( PINB == 0b00111110 )
			{
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00001100;
				while( PINB == 0b00111110 )
				{}
			}
			// RIGHT TURN
			else if( PINB == 0b00000000 )
			{
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00010010;
				_delay_ms(1200);
			}
		}
		else if(PINB == 0b00111000)
		{	/*turn on LEFT motor turn off RIGHT motor*/
			PORTD = 0b00100000;
			PORTC = 0b00010000;
			_delay_ms(50);
			// RIGHT TURN
			if( PINB == 0b00111110 )
			{
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00010010;
				while( PINB == 0b00111110 )
				{}
			}
			// LEFT TURN
			else if( PINB == 0b00000000 )
			{
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00001100;
				_delay_ms(1200);
			}
		}
		else if(PINB == 0b00111110)
		{
				PORTD &= (1<<5);
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00001100;
				while(PINB == 0b00111110 )
				{}
		}
		else if( PINB == 0b00000000 )
		{
				PORTD &= (1<<5);
				PORTC = 0b00010100;
				_delay_ms(300);
				PORTC = 0b00001100;
				_delay_ms(1200);
		}
	}
}
