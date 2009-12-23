#include "ClippingPlaneIntersection.h"

ClippingPlaneIntersection::ClippingPlaneIntersection( const ClippingPlane& clippingPlane, const Ray& ray, float distance )
 :	ObjectIntersection( clippingPlane, ray, distance ),
	m_clippingPlane( clippingPlane )
{

}


