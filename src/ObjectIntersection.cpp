#include "ObjectIntersection.h"

#include "Object.h"

ObjectIntersection::ObjectIntersection( const Object& object, const Ray& ray, float distance )
 :	Intersection( ray, distance ),
	m_object( object )
{
	
}

ObjectIntersection::ObjectIntersection( const ObjectIntersection& intersection )
 :	Intersection( intersection ),
	m_object( intersection.m_object )
{

}


Imath::Color4f ObjectIntersection::getColor() const
{
	return m_object.shade( this );
}

