#pragma once

#include <iostream>
#include <cmath>

class vec3 {
public:
	double e[3];

	vec3() : e{ 0,0,0 } {}
	vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

	double x() const { return e[0]; }
	double y() const { return e[1]; }
	double z() const { return e[2]; }

	vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

	double operator[](int i) const { return e[i]; }
	double& operator[](int i) { return e[i]; }

	vec3& operator+=(const vec3& v) {
		e[0] += v.e[0];
		e[1] += v.e[1];
		e[2] += v.e[2];

		return *this;
	}

	vec3& operator *=(double t) {
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;

		return *this;
	}

	vec3& operator/=(double t) {
		return *this *= 1 / t;
	}

	double length() const {
		return std::sqrt(length_squared());
	}

	double length_squared() const {
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}
};

using point3 = vec3;

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& v1, const vec3& v2) {
	return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline vec3 operator-(const vec3& v1, const vec3& v2) {
	return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

//Element Wise multiplication
inline vec3 operator*(const vec3& v1, const vec3& v2) {
	return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

//Scalar multiplication
inline vec3 operator*(double t, const vec3& v) {
	return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
	return t * v; // Uses the previous function
}

//Scalar division
inline vec3 operator/(const vec3& v, double t) {
	return (1 / t) * v; // Reuses the scalar multiplication
}

inline double dot(const vec3& v1, const vec3& v2) {
	return	v1.e[0] * v2.e[0] 
		+ v1.e[1] * v2.e[1] 
		+ v1.e[2] * v2.e[2];		
}

inline vec3 cross(const vec3& v1, const vec3& v2) {
	return vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
		v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
		v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
	return v / v.length();
}