#include "SphereIntersection.h"

SphereIntersection::SphereIntersection( const Sphere& sphere, const Ray& ray, float distance )
 :	ObjectIntersection( sphere, ray, distance ),
	m_sphere( sphere )
{

}

Imath::V3f SphereIntersection::normal() const
{
	Imath::V3f position = m_ray.start() + ( m_distance * m_ray.direction() );

	return (position - m_sphere.centre() ).normalize();
}


