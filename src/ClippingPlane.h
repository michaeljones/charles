#ifndef __CHARLES_CLIPPINGPLANE_H__
#define __CHARLES_CLIPPINGPLANE_H__

#include "Object.h"

#include "Intersection.h"
#include "Ray.h"

#include <ImathVec.h>

class ClippingPlane : public Object
{
public:

	ClippingPlane( Imath::V3f position, Imath::V3f normal );
	ClippingPlane( const ClippingPlane& clippingPlane );

	IntersectionPtrList intersect( const Ray& ray ) const;

private:

	ClippingPlane() {};

private:

	Imath::V3f m_position;
	Imath::V3f m_normal;

};

#endif
