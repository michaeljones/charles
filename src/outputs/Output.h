#ifndef __CHARLES_OUTPUT_H__
#define __CHARLES_OUTPUT_H__

#include "Engine.h"

class Output 
{
public:

	Output( const ImagePlane& imagePlane )
	 :	m_imagePlane( imagePlane )
	{};

	void write();

private:

	const ImagePlane& m_imagePlane;

};

#endif

