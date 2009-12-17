#ifndef __CHARLES_OBJECT_H__
#define __CHARLES_OBJECT_H__

#include "Intersection.h"
#include "Ray.h"

#include <ImathVec.h>

class Object 
{
public:

	Object() {};

	virtual IntersectionPtrList intersect( const Ray& ray ) const = 0;

private:

	Object( const Object& obj ) {};

private:

};

typedef std::list< const Object* > ConstObjectPtrList;

#endif

