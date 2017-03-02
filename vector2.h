#ifndef VECTOR2_H
#define VECTOR2_H

#include <type_traits>
#include <iostream>
#include <math.h>

template <typename T>
class Vector2 {

	public:
		T x, y;
		
		Vector2(): Vector2((T)0, (T)0) {}
		Vector2(T _x, T _y);
		double magnitude() const;
		Vector2<double> unit() const;

		template <typename U>
		friend bool operator==(const Vector2<U>&, const Vector2<U>&);

		template <typename U>
		friend bool operator!=(const Vector2<U>&, const Vector2<U>&);

		template <typename U>
		friend std::ostream& operator<<(std::ostream&, const Vector2<U>&);

};

template <typename T>
bool operator==(const Vector2<T>& left, const Vector2<T>& right) {
	return left.x == right.x && left.y == right.y; 
}	

template <typename T>
bool operator!=(const Vector2<T>& left, const Vector2<T>& right) {
	return !(left == right);
}	

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Vector2<T>& vec) {
	stream << "[" << vec.x << ", " << vec.y << "]";
	return stream;
}

template <typename T>
double Vector2<T>::magnitude() const {
	return sqrt(x*x + y*y);
}

template <typename T>
Vector2<double> Vector2<T>::unit() const {
	double mag = magnitude();
	return Vector2<double>(x/mag, y/mag);
}

template <typename T>
Vector2<T>::Vector2(T _x, T _y): x(_x), y(_y) {
	static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value, 
				  "vector must be numberic type");
}

#endif
