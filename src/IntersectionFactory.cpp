#include "IntersectionFactory.h"

#include "Object.h"

IntersectionPtrList IntersectionFactory::create( const Object& object, const Ray& ray ) const
{
	return object.intersect( ray );
}

