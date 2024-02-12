#pragma once

#include "types.h"

namespace engine {

template<class T, class Tag>
T generate_incremental_id() {
	static T t{};
	return ++t;
}

template<class T>
class id_generator {
public:
	template<class U>
	T operator()() {
		static T new_id = ++id;
		return new_id;
	}
private:
	static T id;
};

template<class T>
T id_generator<T>::id = {};

template<class T>
object_id generate_id() {
	return generate_incremental_id<object_id, T>();
}

template<class T>
object_type_id generate_type_id() {
	static id_generator<object_type_id> generate{};
	return generate.operator() < T > ();
}

}