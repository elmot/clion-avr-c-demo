#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include "arduino-led.hpp"
int main() {
    LED::init();
    while (true) //infinite loop
    {
        LED::on();
        _delay_ms(300);
        LED::off();
        _delay_ms(50);
    }
}