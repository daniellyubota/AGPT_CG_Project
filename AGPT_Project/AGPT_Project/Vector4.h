#pragma once

template <class T>
class Vector4 {
public:
	Vector4(T x, T y, T z, T w) : _x(x), _y(y), _z(z), _w(w) {

	}

	const T& x() const { return _x; }
	T& x() { return _x; }

	const T& y() const { return _y; }
	T& y() { return _y; }

	const T& z() const { return _z; }
	T& z() { return _z; }

	const T& w() const { return _w; }
	T& w() { return _w; }

private:
	T _x, _y, _z, _w;
};