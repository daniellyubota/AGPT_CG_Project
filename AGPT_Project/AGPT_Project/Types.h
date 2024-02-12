#pragma once
#include <cstdint>

namespace engine {

using object_id = std::uint64_t;
using object_type_id = std::uint32_t;

using entity_id = object_id;
using entity_type_id = object_type_id;
using component_id = object_id;
using component_type_id = object_type_id;

using time_millis_t = std::uint64_t;

inline float asSeconds(time_millis_t millis) {
	return float(millis) / 1000.0f;
}

}