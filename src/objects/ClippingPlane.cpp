#include "ClippingPlane.h"

#include "intersections/ClippingPlaneIntersection.h"


ClippingPlane::ClippingPlane( Imath::V3f position, Imath::V3f normal, Material& material )
 :	Object( material ),
	m_position( position ),
	m_normal( normal )
{

}

ClippingPlane::ClippingPlane( const ClippingPlane& clippingPlane )
 :	Object( clippingPlane ),
	m_position( clippingPlane.m_position ),
	m_normal( clippingPlane.m_normal )
{
	
}

IntersectionPtrList ClippingPlane::intersect( const Ray& ray ) const
{
	const float d = m_position.dot( m_normal );
	const float ndotRayStart = m_normal.dot( ray.start() );
	const float ndotRayDir = m_normal.dot( ray.direction() );

	// TODO: Check ndotRayDir is not zero
	const float distance = ( d - ndotRayStart ) / ndotRayDir;

	IntersectionPtrList intersections;

	// Minus distance should be closer then plus so put it in first
	intersections.push_back( new ClippingPlaneIntersection( *this, ray, distance ) );
	
	return intersections;
}

