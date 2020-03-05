// Samuel DuBois and Michael Brauninger
// ECE 231: Embedded Systems
// Project 2 Test Program 6
// 03.04.2020

#include <asf.h>

// Definitions of Digit 'identities' (Bit representations of numbers on CLK display)
#define zero	0b11111101
#define one		0b11100001
#define two		0b11110011
#define three	0b11110011
#define four	0b01100111
#define five	0b01101111
#define six		0b00111111
#define seven	0b11100001
#define eight	0b01100111
#define nine	0b11100111

// An array of our Digit Identities
uint32_t identities[10] = { zero, one, two, three, four, five, six, seven, eight, nine }; 
	
// Program incrementer *Should move to another function location*
static uint32_t inc = 0b00000000;

// MARK: Handle any trigger sent by the TIMER_COMP_vect
ISR(TIMER1_COMPA_vect) {
	inc += 1;
}

// MARK: Handle any triggered flag sent by the SPI_STC_vect
ISR(SPI_STC_vect) {
	
	// Set the SS flag to end transmission
	PORTB = 0b00101100;
}

int main (void)
{
	// MARK: Instantiate all the pins that we need in order to 
	
	// Set the MOSI, SS, and SCK pin as outputs
	DDRB = 0b00101100;
	// Set the SPI to Master Mode, Set the SPI to 1 (enable), Set SPIE to 1 to enable interrupt
	SPCR = 0b11010000;
	// Lets us divide our clock frequency by 2 to get the 1MHz
	SPSR = 0b00000001;
	//SPDR = five;
	// Set the SREG to global interrupt to allow our ISR function to activate
	sei();
	
	// MARK: Set out clock pints to active
	
	// Set the compare value
	OCR1A = 25000;
	// Set the counter to CTC Mode
	TCCR1B |= (1 << WGM12);
	//Set Interrupt Compare Match
	TIMSK1 |= (1 << OCIE1A);
	// Set Pre-scaler to 8 and start the timer
	TCCR1B |= (1 << CS01);
	
	// MARK: Set up transistor bits as outputs
	DDRC =	0b00111100;
	// Set test transistor bit
	PORTC = 0b00000100;
	
	while (1) {
		
		// Set the SPDR (MOSI) output to the number 5
		SPDR = eight;
		// Turn off the SS Pin to configure communication and start transmission		
		PORTB = 0b00101000;
	}
	
	
}
