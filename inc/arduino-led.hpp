//
// Created by Ilia.Motornyi on 13/02/2020.
//

#ifndef CLION_AVR_C_DEMO_ARDUINO_LED_HPP
#define CLION_AVR_C_DEMO_ARDUINO_LED_HPP
extern "C" {
#include <avr/io.h>
#include <util/delay.h>
};

namespace LED {
namespace {
static auto constexpr LED_BITMASK = 1u << (unsigned)PB7;
}
inline void init() { DDRB |= LED::LED_BITMASK; }
inline void on() { PORTB |= LED::LED_BITMASK; }
inline void off() { PORTB &= (unsigned)~LED::LED_BITMASK; }
} // namespace LED
#endif // CLION_AVR_C_DEMO_ARDUINO_LED_HPP
