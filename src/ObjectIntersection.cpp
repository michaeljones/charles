#include "ObjectIntersection.h"

ObjectIntersection::ObjectIntersection( const Object& object, const Ray& ray, float distance )
 :	Intersection( distance ),
	m_object( object ),
	m_ray( ray )
{
	
}

ObjectIntersection::ObjectIntersection( const ObjectIntersection& intersection )
 :	Intersection( intersection.distance() ),
	m_object( intersection.m_object ),
	m_ray( intersection.m_ray )
{

}


