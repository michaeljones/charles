#ifndef __CHARLES_OBJECT_H__
#define __CHARLES_OBJECT_H__

#include "materials/Material.h"
#include "intersections/Intersection.h"
#include "Ray.h"

#include <ImathVec.h>

class Object 
{
public:

	Object( Material& material );

	virtual IntersectionPtrList intersect( const Ray& ray ) const = 0;

	virtual Imath::Color4f shade( const Intersection* intersection ) const;

protected:

	Object( const Object& obj );

private:

	const Material& m_material;

};

typedef std::list< const Object* > ConstObjectPtrList;

#endif

