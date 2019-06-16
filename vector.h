#include <cmath>

class Vec {
	double x, y, z;
	Vec() { x = y = z = 0; } //default constructor parameters
	Vec(double a, double b, double c) { x=a, y=b, z=c; } //constructor

	Vec operator - (Vec v) { return Vec(x - v.x, y - v.y, z - v.z); }
};