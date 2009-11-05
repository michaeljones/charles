#ifndef __CHARLES_SPHERE_H__
#define __CHARLES_SPHERE_H__

#include <ImathVec.h>

class Sphere 
{
public:

	Sphere( float radius, Imath::V3f centre );

private:

	Sphere() {};
	Sphere( const Sphere& sphere ) {};

private:

	float m_radius;
	Imath::V3f m_centre;

};

#endif

