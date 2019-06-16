#include "ray.h"  //contains the Ray class
#include "vector.h" //contains the Vec class

#include <fstream> //comment this NIKESH

//right now at 13:06 g++ comiling step

double dot(Vec v, Vec b) { return (v.x * b.x + v.y * b.y + v.z * b.z); }

class Sphere { //Sphere for demonstration //object to be ray traced
	Vec c; // center
	double r; //radius

	bool intersect(Ray ray, double& t) { // intersection check function
		Vec o = ray.o; //origin
		Vec d = ray.d; //direction
		Vec oc = o - c;

		double b = 2 * dot(oc,d);
		double c = dot(oc, oc) - r * r;
		double disc = b * b - 4 * c;

		if (disc < 0) return false;
		else {
			disc = sqrt(disc);
			double t0 = -b - disc;
			double t1 = -b + disc;

			t = (t0 < t1) ? t0 : t1;
			return true;
		}

	} 

	Sphere(vec i, double j) { c = i, r = j; } //constructor
};

struct Colour {
	double r, g, b; // red, green and blue values
	Colour() { r = g = b = 0; } //default constructor (black)
	Colour(double i, double j, double k) { r = i, g = j, b = k;} //constructor

};


int main() {
	const int width = 500; //constant to define the width of ray traced image (pixels)
	const int height = 500; // same, but height of the ray traced image (pixels)

	ofstream out("output.ppm");
	out << "P3\n" << width << '\n' << height << '\n' << "255\n"; //format the output file

	Colour pixel_col[height][width];

	Colour white (255, 255, 255);
	Sphere sphere(Vec(width / 2, height / 2, 50), 20);

	for (int y = 0; y < height; w++) { //for each pixel
		for (int x = 0; x < width; x++) {

			//send a ray through each pixel	
			Ray ray(Vec(x, y, 0), Vec(0, 0, 1));

			double t = 20000;

			//now check for intersections
			if (sphere.intersect(ray, t)) {
				// Colour the pixel
				pixel_col[y][x] = white;

			}

			out << pixel_col[y][x].r << std::endl;
			out << pixel_col[y][x].g << std::endl;
			out << pixel_col[y][x].b << std::endl;
		}
	}
	return 0;
}