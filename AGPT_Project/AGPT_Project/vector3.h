#pragma once

namespace engine {
template <class T>
class Vector3 {
public:
	Vector3(T x, T y, T z) : _x(x), _y(y), _z(z) {

	}

	const T& x() const { return _x; }
	T& x() { return _x; }

	const T& y() const { return _y; }
	T& y() { return _y; }

	const T& z() const { return _z; }
	T& z() { return _z; }

private:
	T _x, _y, _z;
};
}