/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <tsimmerman.ss@phystech.edu> wrote this file.  As long
 * as you retain this notice you can do whatever you want with this stuff. If we
 * meet some day, and you think this stuff is worth it, you can buy me a beer in
 * return.
 * ----------------------------------------------------------------------------
 */

#include <util/delay.h>

#include "attiny24a/ac.hpp"
#include "attiny24a/adc.hpp"
#include "attiny24a/boot_load.hpp"
#include "attiny24a/eeprom.hpp"
#include "attiny24a/porta.hpp"
#include "attiny24a/tc0.hpp"
#include "attiny24a/tc1.hpp"

#include "led.hpp"

namespace
{

using namespace avrcpp::attiny24a::mporta;

} // namespace

int
main()
{
    led_indicator::init();

    while ( 1 )
    {
        _delay_ms( 100 );
        led_indicator::toggle();
    }
}
