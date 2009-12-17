#include "SphereIntersection.h"

SphereIntersection::SphereIntersection( const Sphere& sphere, const Ray& ray, float distance )
 :	ObjectIntersection( sphere, ray, distance ),
	m_sphere( sphere )
{

}


Imath::Color3< float > SphereIntersection::getColor() const
{
	return Imath::Color3< float >( 1.0, 0.0, 0.0 );
}

