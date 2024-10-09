#include "vec3.h"
#include"color.h"

#include <iostream>

int main() {
	
	//Create the image file
	//Should probably handle file creation error but meh
	std::ofstream image("image.ppm");
	

	//Resolution
	int image_height = 256;
	int image_width = 256;

	image << "P3\n" << image_width << " " << image_height << "\n255\n";

	for (int i = 0; i < image_height; i++) {
		std::clog << "\rScanlines reamaining: " << (image_height - 1) << ' ' << std::flush;

		//Bitch y dis loop so unintuitive maaan
		for (int j = 0; j < image_width; j++) {
			color pixel_color(double(j) / (image_width - 1), double(i) / (image_height - 1), 0.0);
			write_color(image, pixel_color);
		}
	}

	std::clog << "\rDone!                         \n";

	image.close();

	return 0;
}