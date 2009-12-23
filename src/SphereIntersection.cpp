#include "SphereIntersection.h"

SphereIntersection::SphereIntersection( const Sphere& sphere, const Ray& ray, float distance )
 :	ObjectIntersection( sphere, ray, distance ),
	m_sphere( sphere )
{

}

