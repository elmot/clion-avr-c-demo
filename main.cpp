#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>

auto constexpr LED_BITMASK = 1u << (unsigned)PB7;
int main(int arcv,char* argv[])
{
    DDRB = LED_BITMASK; //Makes LED pin as Output
    while(true) //infinite loop
    {

        PORTB |= LED_BITMASK;
        _delay_ms(150); //1 second delay
        PORTB &= ~LED_BITMASK;
        _delay_ms(700); //1 second delay
    }
}