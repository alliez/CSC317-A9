#include "Sphere.h"
#include "Ray.h"
#include <cmath>
#include <algorithm>
#include <Eigen/Geometry>

bool Sphere::intersect(
    const Ray& ray, const double min_t, double& t, Eigen::Vector3d& n) const
{
    Eigen::Vector3d c;
    Eigen::Vector3d d;
    Eigen::Vector3d e;

    c = center;
    d = ray.direction;
    e = ray.origin;

    double r = radius;
    double A = d.dot(d);
    double B = 2 * d.dot(e - c);
    double C = (e - c).dot(e - c) - pow(r, 2);

    //using polinomial root-finding formula
    double delta = pow(B, 2) - 4 * A * C;



    //No intersection found
    if (delta < 0) {
        return false;
    }

    int flag = 0;

    //Two roots => two intersections
    if (delta >= 0) {
        //applying formula here to find two roots
        double root1 = (-B + sqrt(delta)) / (2 * A);
        double root2 = (-B - sqrt(delta)) / (2 * A);

        //case 1: eye is inside
        //intuitively we know root1>=root2 as  sqrt(delta) >= - sqrt(delta)
        if (root1 >= min_t && root2 < min_t) {
            flag = 1;
            t = root1;
            n = (e + t * d - c) / r;
            n = n.normalized();
        }

        else if (root1 >= min_t && root2 >= min_t) {
            flag = 1;
            t = root2;
            n = (e + t * d - c) / r;
            n = n.normalized();
        }

        else flag = 0;
    }

    return flag;
}