#include "IntersectionFactory.h"

#include "objects/Object.h"

IntersectionPtrList IntersectionFactory::create( const Object& object, const Ray& ray ) const
{
	return object.intersect( ray );
}

