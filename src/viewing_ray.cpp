#include "viewing_ray.h"

void viewing_ray(
	const Camera& camera,
	const int i,
	const int j,
	const int width,
	const int height,
	Ray& ray)
{
	////////////////////////////////////////////////////////////////////////////
	// Add your code here

	double focalLength = camera.d;

	//calculate four coordinates
	double right = camera.width / 2;
	double left = -camera.width / 2;

	double top = -camera.height / 2;
	double bottom = camera.height / 2;

	//calculate Nx and Ny for u and v
	//the origin is in the top-left,  is a row index, and  is a column index.
	double u = left + (right - left) * (j + 0.5) / width;
	double v = bottom + (top - bottom) * (i + 0.5) / height;

	//assign to ray
	ray.direction = camera.u * u + camera.v * v - focalLength * camera.w;
	ray.origin = camera.e;
	////////////////////////////////////////////////////////////////////////////
}

