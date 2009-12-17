#ifndef __CHARLES_SPHEREINTERSECTION_H__
#define __CHARLES_SPHEREINTERSECTION_H__

#include "ObjectIntersection.h"
#include "Ray.h"
#include "Sphere.h"

#include <ImathColor.h>

class SphereIntersection : public ObjectIntersection
{
public:

	SphereIntersection( const Sphere& sphere, const Ray& ray, float distance );

	Imath::Color3< float > getColor() const;

private:

	SphereIntersection( const SphereIntersection& intersection );

	const Sphere& m_sphere;
};

#endif

