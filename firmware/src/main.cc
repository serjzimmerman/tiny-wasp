#include <util/delay.h>

#include "attiny24a/adc.hpp"
#include "attiny24a/porta.hpp"

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
