#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>

Eigen::Vector3d blinn_phong_shading(
	const Ray& ray,
	const int& hit_id,
	const double& t,
	const Eigen::Vector3d& n,
	const std::vector< std::shared_ptr<Object> >& objects,
	const std::vector<std::shared_ptr<Light> >& lights)
{
	////////////////////////////////////////////////////////////////////////////
	// Replace with your code here:
	  Eigen::Vector3d p = ray.origin + t * ray.direction;
	  Eigen::Vector3d rgb(0, 0, 0);

	  //constants
	  double ia = 0.1;
	  double epsilon = 1e-6;

	  //calcute rgb values
	  rgb = rgb + (objects[hit_id]->material->ka.array() * Eigen::Vector3d(ia, ia, ia).array()).matrix();


	  for (int i = 0; i < lights.size(); i++) {

	  	Eigen::Vector3d lDirection;
		Eigen::Vector3d lightNormal;
		Eigen::Vector3d h;
	  	double max_t;
	  	int hitID;
		double light_t;
		Ray l_ray;
		bool Hit = 0;


		lights[i]->direction(p, lDirection, max_t);
		l_ray.origin = p;
		l_ray.direction = lDirection;

		Hit = first_hit(l_ray, epsilon, objects, hitID, light_t, lightNormal);


		if (!Hit || light_t >= max_t) {
			h = (-ray.direction.normalized() + l_ray.direction.normalized()).normalized();
			rgb = rgb +  (objects[hit_id]->material->kd.array() * lights[i]->I.array()).matrix() * fmax(0.0, n.dot(l_ray.direction));
			rgb = rgb + (objects[hit_id]->material->ks.array() * lights[i]->I.array()).matrix() * pow(fmax(0.0, n.dot(h)), objects[hit_id]->material->phong_exponent);
		}

	  }
	return rgb;
	////////////////////////////////////////////////////////////////////////////
}
