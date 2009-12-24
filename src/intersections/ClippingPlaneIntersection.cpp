#include "ClippingPlaneIntersection.h"

ClippingPlaneIntersection::ClippingPlaneIntersection( const ClippingPlane& clippingPlane, const Ray& ray, float distance )
 :	ObjectIntersection( clippingPlane, ray, distance ),
	m_clippingPlane( clippingPlane )
{

}

Imath::V3f ClippingPlaneIntersection::normal() const
{
	return m_clippingPlane.normal();
}


