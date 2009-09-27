#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void set_freq( uint16_t freq_tone ) {
	uint32_t freq_cpu = F_CPU;
	uint32_t clocks   = freq_cpu / freq_tone;
	
	if ( clocks > 0xFFFF )
		return; 
	
	TCCR0B &= ~( (1 << CS02) | (1 << CS01) | (1 << CS00) );
	if ( clocks < 256 ) {
		TCCR0B |= ( 0 << CS02 ) | ( 0 << CS01 ) | ( 1 CS00 );
		OCR0A   = clocks;
	} else if ( clocks < 256 *   8 ) {
		
	} else if ( clocks < 256 *  64 ) {

	} else if ( clocks < 256 * 256 ) {
	
	}
	
	OCR0B = OCR0A / 2;
}

int main ( ) {
	DDRB   = (1 << 1);
	TCCR0A = (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
	TCCR0B = (1 <<  WGM02) | (1 <<  CS01);
	OCR0A  = 20; // 52 - 4;
	OCR0B  = OCR0A / 2;
	ACSR   = (1 << ACD);
	
	while (1) { 
		OCR0A += 2; OCR0B++;
		_delay_ms( 1000 );
		/* OCR0A += 6;
		OCR0B = OCR0A / 2;
		_delay_ms( 5 );
		OCR0A -= 6;
		OCR0B = OCR0A / 2;
		_delay_ms( 5 ); */
	} 
}
