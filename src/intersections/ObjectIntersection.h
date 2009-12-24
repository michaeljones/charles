#ifndef __CHARLES_OBJECTINTERSECTION_H__
#define __CHARLES_OBJECTINTERSECTION_H__

#include "Ray.h"
#include "Intersection.h"

#include <ImathColor.h>

class Object;

class ObjectIntersection : public Intersection
{
public:

	ObjectIntersection( const Object& object, const Ray& ray, float distance );
	ObjectIntersection( const ObjectIntersection& intersection );

	virtual Imath::V3f normal() const = 0;

	virtual Imath::Color4< float > getColor() const;

private:

	const Object& m_object;
};

#endif

