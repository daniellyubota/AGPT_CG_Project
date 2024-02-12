#pragma once
#include <cstdint>
#include "Types.h"

namespace engine {

class ClockImpl
{
public:
	ClockImpl();
	time_millis_t getTime() const;
	time_millis_t reset();
private:
	time_millis_t timeFrom;
};

}