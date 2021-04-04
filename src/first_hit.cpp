#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
	bool hit = 0;
	Eigen::Vector3d normal;
	double min = std::numeric_limits<double>::infinity();
	auto numObject = objects.size();

	for (auto i = 0; i < numObject; i++) {
		bool Intersected = objects[i]->intersect(ray, min_t, t, normal);
		if (Intersected) {
			if (t < min) {
				min = t;
				hit_id = i;
				n = normal;
				hit = true;
			}
		}
	}
	t = min;
  return hit;
  ////////////////////////////////////////////////////////////////////////////
}

