#ifndef __CHARLES_POINTLIGHT_H__
#define __CHARLES_POINTLIGHT_H__

#include <ImathVec.h>

class PointLight 
{
public:

	PointLight( Imath::V3f location );

private:

	PointLight() {};
	PointLight( const PointLight& pointLight ) {};

private:

	Imath::V3f m_position;

};

#endif

