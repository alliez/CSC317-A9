#include "raycolor.h"
#include "first_hit.h"
#include "blinn_phong_shading.h"
#include "reflect.h"
#include <iostream>

bool raycolor(
    const Ray& ray,
    const double min_t,
    const std::vector< std::shared_ptr<Object> >& objects,
    const std::vector< std::shared_ptr<Light> >& lights,
    const int num_recursive_calls,
    Eigen::Vector3d& rgb)
{
    ////////////////////////////////////////////////////////////////////////////
    // Replace with your code here:

    double epsilon = 1e-6;
    Eigen::Vector3d normal;
    int hitID;
    double t;

    if (num_recursive_calls >= 6) {
        return false;
    }

    rgb = Eigen::Vector3d(0, 0, 0);
       

    if (first_hit(ray, min_t, objects, hitID, t, normal)) {
        rgb = rgb + blinn_phong_shading(ray, hitID, t, normal, objects, lights);

        //reflected ray
        Ray rRay;
        //reflected RGB
        Eigen::Vector3d rRGB;

        rRay.origin = ray.origin + t * ray.direction;
        rRay.direction = reflect(ray.direction.normalized(), normal);

        if (raycolor(rRay, epsilon, objects, lights, num_recursive_calls + 1, rRGB))
            rgb = rgb + (objects[hitID]->material->km.array() * rRGB.array()).matrix();
       
        return true;
    }
    return false;
    ////////////////////////////////////////////////////////////////////////////
}