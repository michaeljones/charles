#include "Sphere.h"

#include "SphereIntersection.h"


Sphere::Sphere( float radius, Imath::V3f centre )
 :	Object(),
	m_radius( radius ),
	m_centre( centre )
{

}

Sphere::Sphere( const Sphere& sphere )
 :	Object(),
	m_radius( sphere.m_radius ),
	m_centre( sphere.m_centre )
{
	
}

IntersectionPtrList Sphere::intersect( const Ray& ray ) const
{
	// Calculate if there is an intersection
	const Imath::V3f rayStart = ray.start();

	const float d = rayStart.x - m_centre.x;
	const float e = rayStart.y - m_centre.y;
	const float f = rayStart.z - m_centre.z;

	const Imath::V3f rayDir = ray.direction();
	const float a = 1;
	const float b = 2 * ( rayDir.x * d + rayDir.y * e + rayDir.z * f );
	const float c = ( d*d + e*e + f*f ) - m_radius*m_radius;

	const float determinant = b*b - 4 * a * c;

	if ( determinant < 0 )
	{
		return IntersectionPtrList();
	}

	// a is non-zero so no checks required
	const float intersectionDistancePlus = ( -b + sqrt( determinant ) ) / ( 2 * a );
	const float intersectionDistanceMinus = ( -b - sqrt( determinant ) ) / ( 2 * a );

	IntersectionPtrList intersections;

	// Minus distance should be closer then plus so put it in first
	intersections.push_back( new SphereIntersection( *this, ray, intersectionDistanceMinus ) );
	intersections.push_back( new SphereIntersection( *this, ray, intersectionDistancePlus ) ); 
	
	return intersections;
}

