#include "stdafx.h"

#include <iostream>
#include <cassert>

template <size_t DIM, typename T>
struct vec
{};

template <typename T> struct vec<2, T>
{
	vec() : x(T()), y(T()) {}
	vec(T _x, T _y) : x(_x), y(_y) {}

	vec(const vec<2, T>& other) {
		x = other.x;
		y = other.y;
	}

	vec operator=(const vec<2, T>& other) {
		x = other.x;
		y = other.y;
	}

		  T& operator[](const size_t i) { assert(i < 2 && i >= 0); return i == 0 ? x : y; }
	const T& operator[](const size_t i) const { assert(i < 2 && i >= 0); return i == 0 ? x : y; }

private:
	T x, y;
};

template <size_t DIM, typename T>
vec<DIM, T> operator+(vec<DIM, T> lhs, const vec<DIM, T>& rhs)
{
	for(int i = 0; i < DIM; i++)
		lhs[i] += rhs[i];
	return lhs;
}

template <size_t DIM, typename T>
std::ostream& operator<<(std::ostream& out, const vec<DIM, T>& v)
{
	out << "v(";
	for(size_t i = 0; i < DIM; i++)
	{
		if(i == DIM - 1)
			out << v[i] << ")";
		else
			out << v[i] << ",";
	}

	return out;
}

using Vec2f = vec<2, float>;
using Vec2i = vec<2, int>;

int main()
{
	Vec2i v1(1, 2);
	//std::cout << v1 << "\n";

	Vec2i v2(2, 3);
	//std::cout << v2 << "\n";

	Vec2i v3 = v1 + v2;
	std::cout << v3 << "\n";

	return 0;
}
