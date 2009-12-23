#include "World.h"


World::World( const IntersectionFactory& intersectionFactory )
 :	m_intersectionFactory( intersectionFactory )
{
	
}

void World::addObject( const Object& object )
{
	m_objects.push_back( &object );
}


IntersectionPtrList World::intersect( const Ray& ray ) const
{
	ConstObjectPtrList::const_iterator it = m_objects.begin();
	ConstObjectPtrList::const_iterator end = m_objects.end();

	IntersectionPtrList intersections;

	// For each object
	for ( ; it != end; ++it )
	{
		// Check for intersection with ray
		IntersectionPtrList objectIntersections = m_intersectionFactory.create( *(*it), ray );

		IntersectionPtrList::iterator it = objectIntersections.begin();
		IntersectionPtrList::iterator end = objectIntersections.end();

		for ( ; it != end; ++it )
		{
			intersections.push_back( *it );
		}
	}

	//	Sort intersections by distance
	intersections.sort( Intersection::PtrCompare() );

	//	Return first intersection
	return intersections;
}


