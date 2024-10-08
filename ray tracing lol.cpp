#include <iostream>
#include <fstream>
int main() {
	
	//create the image file
	std::ofstream image("image.ppm");

	//should  probably handle file creation error but meh

	//resolution
	int image_height = 256;
	int image_width = 256;

	image << "P3\n" << image_width << " " << image_height << "\n255\n";

	for (int i = 0; i < image_height; i++) {
		std::clog << "\rScanlines reamaining: " << (image_height - 1) << ' ' << std::flush;
		for (int j = 0; j < image_width; j++) {
			double r = double(j) / (image_width - 1);
			double g = double(i) / (image_height - 1);
			double b = 0.0;

			int ir = (255.999 * r);
			int ig = (255.999 * g);
			int ib = (255.999 * b);

			image << ir << ' ' << ig << ' ' << ib << std::endl;
		}
	}

	std::clog << "\rDone!                         \n";

	image.close();

	return 0;
}