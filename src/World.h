#ifndef __CHARLES_WORLD_H__
#define __CHARLES_WORLD_H__

#include "Sphere.h"
#include "PointLight.h"

class World 
{
public:

	World() {};

	void addObject( const Sphere& object ) {};
	void addLight( const PointLight& light ) {};

private:

	World( const World& world ) {};

private:

};

#endif

