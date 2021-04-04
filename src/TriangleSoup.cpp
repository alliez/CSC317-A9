#include "TriangleSoup.h"
#include "Ray.h"
// Hint
#include "first_hit.h"

bool TriangleSoup::intersect(
    const Ray& ray, const double min_t, double& t, Eigen::Vector3d& n) const
{
    int hitId;
    bool findFirstHit = first_hit(ray, min_t, triangles, hitId, t, n);
    return findFirstHit;
}