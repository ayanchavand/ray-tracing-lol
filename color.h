#pragma once

#include "vec3.h"
#include <fstream>

using color = vec3;

void write_color(std::ofstream& image_file, const color& pixel_color) {
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	int ir = (255.999 * r);
	int ig = (255.999 * g);
	int ib = (255.999 * b);

	image_file << ir << ' ' << ig << ' ' << ib << std::endl;

}