#include "ClippingPlaneIntersection.h"

ClippingPlaneIntersection::ClippingPlaneIntersection( const ClippingPlane& clippingPlane, const Ray& ray, float distance )
 :	ObjectIntersection( clippingPlane, ray, distance ),
	m_clippingPlane( clippingPlane )
{

}

Imath::Color3< float > ClippingPlaneIntersection::getColor() const
{
	return Imath::Color3< float >( 0.0, 0.0, 1.0 );
}

