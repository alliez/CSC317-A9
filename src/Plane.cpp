#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
    const Ray& ray, const double min_t, double& t, Eigen::Vector3d& n) const
{   
    Eigen::Vector3d d;
    Eigen::Vector3d e;

    d = ray.direction;
    e = ray.origin;


    //dot product = 0  => no intersection of the ray and the plane
    if (d.dot(normal) == 0) {
        return false;
    }

    double temp = -((e - point).dot(normal)) / d.dot(normal);

    if (temp >= min_t){
        t = temp;
        n = normal;
        return true;
    }

    return false;
}
