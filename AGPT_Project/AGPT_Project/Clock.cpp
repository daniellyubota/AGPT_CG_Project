#include "Clock.h"

#include <algorithm>
#include <iterator>

namespace engine {

Clock::Clock(unsigned frame_duration, bool permit_short_frames) : short_frames(permit_short_frames), frame_duration(frame_duration) {
}


Clock::~Clock() {
}

std::vector<unsigned> Clock::drain() {
	std::vector<unsigned> frames;
	auto t = clocc.reset();
	std::uint64_t ms = t + remainder;
	int frame_rem = ms % frame_duration;
	int frame_count = (ms / frame_duration) + (short_frames && frame_rem ? 1 : 0);

	frames.reserve(frame_count);
	std::fill_n(std::back_inserter(frames), (short_frames && frame_rem ? frame_count - 1 : frame_count), frame_duration);
	if (short_frames) {
		if (frame_rem)
			frames.push_back(frame_rem);
		remainder = 0;
	}
	else {
		remainder = frame_rem;
	}
	return frames;
}

void Clock::freeze() {
	frozen = true;
	remainder = static_cast<unsigned>(clocc.reset());
}

void Clock::unfreeze() {
	frozen = false;
	clocc.reset();
}


}