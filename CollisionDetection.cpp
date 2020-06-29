#include "CollisionDetection.h"

bool CollisionDetection::operator()(const SolidSphere& sph1, const SolidSphere& sph2) {
	if (dotProduct((sph1.getCenter() - sph2.getCenter()), (sph1.getCenter() - sph2.getCenter())) <= pow(sph1.getRadius() + sph2.getRadius(), 2)) {
		return 1;
	}
	else {
		return 0;
	}
}