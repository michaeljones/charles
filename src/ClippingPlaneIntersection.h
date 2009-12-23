#ifndef __CHARLES_CLIPPINGPLANEINTERSECTION_H__
#define __CHARLES_CLIPPINGPLANEINTERSECTION_H__

#include "ObjectIntersection.h"
#include "Ray.h"
#include "ClippingPlane.h"

#include <ImathColor.h>

class ClippingPlaneIntersection : public ObjectIntersection
{
public:

	ClippingPlaneIntersection( const ClippingPlane& clippingPlane, const Ray& ray, float distance );

private:

	ClippingPlaneIntersection( const ClippingPlaneIntersection& intersection );

	const ClippingPlane& m_clippingPlane;
};

#endif

