#ifndef __CHARLES_VIEW_H__
#define __CHARLES_VIEW_H__

#include "Camera.h"
#include "ImagePlane.h"

class View
{
public:

	View( const Camera& camera, const ImagePlane& imagePlane )
	 :	m_camera( camera ),
		m_imagePlane( imagePlane )
	{}

private:

	const Camera& m_camera;
	const ImagePlane& m_imagePlane;

};

#endif

