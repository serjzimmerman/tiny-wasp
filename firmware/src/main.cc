#include <util/delay.h>

#include "attiny24a/ac.hpp"
#include "attiny24a/adc.hpp"
#include "attiny24a/boot_load.hpp"
#include "attiny24a/eeprom.hpp"
#include "attiny24a/porta.hpp"
#include "attiny24a/tc0.hpp"
#include "attiny24a/tc1.hpp"

namespace
{

using namespace avrcpp::attiny24a::mporta;

} // namespace

int
main()
{
    ddra |= ddra_fields::pa7;

    while ( 1 )
    {
        ddra ^= ddra_fields::pa7;
        _delay_ms( 100 );
    }
}
