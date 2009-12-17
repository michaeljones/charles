#ifndef __CHARLES_RAY_H__
#define __CHARLES_RAY_H__

#include <ImathVec.h>

class Ray 
{
public:

	Ray( Imath::V3f start, Imath::V3f direction )
	 :	m_start( start ),
		m_direction( direction )
	{};

	Ray( const Ray& ray )
	 :	m_start( ray.m_start ),
		m_direction( ray.m_direction )
	{};

	const Imath::V3f start() const { return m_start; };
	const Imath::V3f direction() const { return m_direction; };

private:

	Imath::V3f m_start;
	Imath::V3f m_direction;
};

#endif

