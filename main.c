#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main ( ) {
	DDRB   = (1 << 1);
	TCCR0A = (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
	TCCR0B = (1 <<  WGM02) | (1 <<  CS01);
	OCR0A  = 52 - 4;
	OCR0B  = OCR0A / 2;

	while (1) { 
	/*	OCR0A += 6;
		OCR0B = OCR0A / 2;
		_delay_ms( 5 );
		OCR0A -= 6;
		OCR0B = OCR0A / 2;
		_delay_ms( 5 ); */
	} 
}
