#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include "arduino-led.hpp"

int main() {
    led_init();
    while (true) //infinite loop
    {
        led_on();
        _delay_ms(300);
        led_off();
        _delay_ms(500);
    }
}