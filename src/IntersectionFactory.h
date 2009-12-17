#ifndef __CHARLES_INTERSECTIONFACTORY_H__
#define __CHARLES_INTERSECTIONFACTORY_H__

#include "Intersection.h"

class Object;

class IntersectionFactory
{
public:

	IntersectionFactory() {};

	IntersectionPtrList create( const Object& object, const Ray& ray ) const;

private:

	IntersectionFactory( const IntersectionFactory& intersectionFactory ) {};

};

#endif


