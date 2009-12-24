#include "Intersection.h"


Intersection::Intersection( const Ray& ray, const float distance )
 :	m_distance( distance ),
	m_ray( ray )
{
	
}

Intersection::Intersection( const Intersection& intersection )
 :	m_distance( intersection.m_distance ),
	m_ray( intersection.m_ray )
{
	
}


