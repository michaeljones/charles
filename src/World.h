#ifndef __CHARLES_WORLD_H__
#define __CHARLES_WORLD_H__

#include "objects/Object.h"
#include "lights/PointLight.h"
#include "intersections/IntersectionFactory.h"
#include "Ray.h"

#include <vector>



class World 
{
public:

	World( const IntersectionFactory& intersectionFactory );

	void addObject( const Object& object );
	void addLight( const PointLight& light ) {};

	IntersectionPtrList intersect( const Ray& ray ) const;

private:

	World( const World& world );

private:

	ConstObjectPtrList m_objects;

	const IntersectionFactory& m_intersectionFactory;

};

#endif

