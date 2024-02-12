#pragma once
#include <vector>
#include "ClockImpl.h"

namespace engine {

class Clock {
public:
	Clock(unsigned frame_duration, bool permit_short_frames = false);
	~Clock();
	std::vector<unsigned> drain();
	void freeze();
	void unfreeze();
private:
	ClockImpl clocc;
	bool short_frames;
	unsigned remainder = 0;
	bool frozen = false;
	unsigned frame_duration;
};

}