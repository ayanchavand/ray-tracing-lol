#include "vec3.h"
#include "color.h"
#include "ray.h"

#include <iostream>

color ray_color(const ray& r) {
	return color(0, 0, 0);
}

int main() {
	


	//Create the image file
	//Should probably handle file creation error but meh
	std::ofstream image("image.ppm");
	
	//Resolution of the image
	double aspect_ratio = 16.0 / 9.0;
	int image_width = 400;
	int image_height = image_width / aspect_ratio;
	image_height = (image_height < 1) ? 1 : image_height;

	/*
	 * If you're wondering why we don't just use aspect_ratio when computing viewport_width,
     * it's because the value set to aspect_ratio is the ideal ratio, it may not be the actual
	 * ratio between image_width and image_height. If image_height was allowed to be real valued—rather 
	 * than just an integer—then it would be fine to use aspect_ratio. 
	 * But the actual ratio between image_width and image_height can vary based on two parts of the code.
	 */

	//Camera
	double focal_length = 1.0;
	double viewport_height = 2.0;
	double viewport_width = viewport_height * (image_width / image_height);
	point3 camera_center = point3(0, 0, 0);
	
	//Viewport Vectors
	vec3 viewport_u = vec3(viewport_width, 0, 0);
	vec3 viewport_v = vec3(0, -viewport_height, 0);

	//Delta vectors from pixel to pixel
	auto pixel_delta_u = viewport_u / image_width;
	auto pixel_delta_v = viewport_v / image_height;

	//I still have no clue what this code does (I need mental healing)
	//Nvm I think I got it
	
	//I think it computes the vector to the upper left point of the viewport
	auto viewport_upper_left = camera_center
		- vec3(0, 0, focal_length)
		- viewport_u / 2
		- viewport_v / 2;
	//and this basically gives the center of the pixel 
	auto pixel00_loc = viewport_upper_left
		+ 0.5 * (pixel_delta_u + pixel_delta_v);

	//Render
	image << "P3\n" << image_width << " " << image_height << "\n255\n";

	for (int i = 0; i < image_height; i++) {
		std::clog << "\rScanlines reamaining: " << (image_height - 1) << ' ' << std::flush;
		for (int j = 0; j < image_width; j++) {
			point3 pixel_center = pixel00_loc + (j * pixel_delta_u) + (j * pixel_delta_v);
			//Someone help me visualize this lol
			vec3 ray_direction = pixel_center - camera_center;
			ray r = ray(camera_center, ray_direction);
			color pixel_color = ray_color(r);
			write_color(image, pixel_color);
		}
	}

	std::clog << "\rDone!                         \n";

	image.close();

	return 0;
}