

#include "Triangle.h"
#include "Ray.h"


bool Triangle::intersect(
    const Ray& ray, const double min_t, double& t, Eigen::Vector3d& n) const
{
    //get the three vertices of the triangle
    Eigen::Vector3d p1 = std::get<0>(corners);
    Eigen::Vector3d p2 = std::get<1>(corners);
    Eigen::Vector3d p3 = std::get<2>(corners);

    //declaring direction, origin, and a-l;
    Eigen::Vector3d Direction, Origin;
    float a, b, c, d, e, f, g, h, i, j, k, l;

    //get the direction and origin of the triangle
    Direction = ray.direction; Origin = ray.origin;

    a = p1[0] - p2[0];
    b = p1[1] - p2[1];
    c = p1[2] - p2[2];
    d = p1[0] - p3[0];
    e = p1[1] - p3[1];
    f = p1[2] - p3[2];
    g = Direction[0];
    h = Direction[1];
    i = Direction[2];
    j = p1[0] - Origin[0];
    k = p1[1] - Origin[1];
    l = p1[2] - Origin[2];

    float M = a * (e * i - h * f) + b * (g * f - d * i) + c * (d * h - e * g);
    float temp = -(f * (a * k - j * b) + e * (j * c - a * l) + d * (b * l - k * c)) / M;
    float beta = (j * (e * i - h * f) + k * (g * f - d * i) + l * (d * h - e * g)) / M;
    float gamma = (i * (a * k - j * b) + h * (j * c - a * l) + g * (b * l - k * c)) / M;

    //does not intersect
    if (temp < min_t || beta < 0 || beta >(1 - gamma) || gamma < 0 || gamma > 1) {
        return false;
    }

    //intersect
    t = temp;
    Eigen::Vector3d v1 = p1 - p2;
    Eigen::Vector3d v2 = p1 - p3;
    n = v1.cross(v2) / (v1.cross(v2).norm());

    return true;
}