#pragma once

namespace engine {
template <class T>
class Vector2 {
public:
	Vector2() : _x{}, _y{} {

	}
	Vector2(T x, T y) : _x(x), _y(y) {

	}

	Vector2 normalize() {
		return normalize(*this);
	}

	Vector2 normalize(const Vector2& relativeTo) {
		return Vector2{ x() / relativeTo.x(), y() / relativeTo.y() };
	}

	const T& x() const { return _x; }
	T& x() { return _x; }

	const T& y() const { return _y; }
	T& y() { return _y; }

	Vector2 operator+(const Vector2& other) const {
		return { _x + other._x, _y + other._y };
	}

	Vector2 operator-(const Vector2& other) const {
		return { _x - other._x, _y - other._y };
	}

	Vector2 operator*(const Vector2& other) const {
		return { _x * other._x, _y * other._y };
	}

	Vector2 operator/(const Vector2& other) const {
		return { _x / other._x, _y / other._y };
	}

	Vector2& operator+=(const Vector2& other) {
		_x += other._x;
		_y += other._y;
		return *this;
	}

	Vector2& operator-=(const Vector2& other) {
		_x -= other._x;
		_y -= other._y;
		return *this;
	}

	Vector2& operator*=(const Vector2& other) {
		_x *= other._x;
		_y *= other._y;
		return *this;
	}

	Vector2& operator/=(const Vector2& other) {
		_x /= other._x;
		_y /= other._y;
		return *this;
	}
private:
	T _x, _y;
};

}