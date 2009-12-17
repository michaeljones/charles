#ifndef __CHARLES_INTERSECTION_H__
#define __CHARLES_INTERSECTION_H__

#include "Ray.h"

#include <ImathColor.h>

#include <list>

class Intersection
{
public:

	Intersection( const float distance );
	Intersection( const Intersection& intersection ) {};

	float distance() const { return m_distance; };

	virtual Imath::Color3< float > getColor() const = 0;

public:

	struct PtrCompare
	{
		bool operator()( Intersection* a, Intersection* b ) { return a->distance() < b->distance(); }
	};

private:

	float m_distance;
};


typedef std::list< Intersection* > IntersectionPtrList;

#endif

