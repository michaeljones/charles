#ifndef __CHARLES_SPHERE_H__
#define __CHARLES_SPHERE_H__

#include "Object.h"

#include "Intersection.h"
#include "Ray.h"

#include <ImathVec.h>

class Sphere : public Object
{
public:

	Sphere( float radius, Imath::V3f centre, Material& material );
	Sphere( const Sphere& sphere );

	IntersectionPtrList intersect( const Ray& ray ) const;

private:

	Sphere();

private:

	float m_radius;
	Imath::V3f m_centre;

};

#endif

