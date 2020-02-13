//
// Created by Ilia.Motornyi on 13/02/2020.
//

#ifndef CLION_AVR_C_DEMO_ARDUINO_LED_HPP
#define CLION_AVR_C_DEMO_ARDUINO_LED_HPP
extern "C" {
#include <util/delay.h>
#include <avr/io.h>
};

namespace LED {
    static auto constexpr LED_BITMASK = 1u << (unsigned) PB5;
}

inline void led_init() {
    DDRB |= LED::LED_BITMASK;
}
inline void led_on() {
    PORTB |= LED::LED_BITMASK;
}
inline void led_off() {
    PORTB &= (unsigned)~LED::LED_BITMASK;
}
#endif //CLION_AVR_C_DEMO_ARDUINO_LED_HPP
