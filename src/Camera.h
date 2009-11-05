#ifndef __CHARLES_CAMERA_H__
#define __CHARLES_CAMERA_H__

class Camera 
{
public:

	Camera( Imath::V3f location)
	 :	m_postion( location )
	{};

private:

	Camera() {};
	Camera( const Camera& camera ) {};

private:

	Imath::V3f m_postion;

};

#endif

