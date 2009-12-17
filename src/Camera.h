#ifndef __CHARLES_CAMERA_H__
#define __CHARLES_CAMERA_H__

#include <ImathVec.h>

class Camera 
{
public:

	Camera( Imath::V3f location)
	 :	m_position( location )
	{};

	const Imath::V3f& position() const { return m_position; };

private:

	Camera() {};
	Camera( const Camera& camera ) {};

private:

	Imath::V3f m_position;

};

#endif

