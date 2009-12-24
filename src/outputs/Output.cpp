#include "Output.h"

#include <fstream>

#include <ImfRgbaFile.h>


void Output::write()
{
	Imath::V2i resolution = m_imagePlane.resolution();
	Imf::Rgba* pixels = new Imf::Rgba[ resolution.x * resolution.y ];

	for ( int i=0; i<resolution.x; ++i )
	{
		for ( int j=0; j<resolution.y; ++j )
		{
			Imath::Color4f color = m_imagePlane.getColor( Coordinate( i, j ) );
			Imf::Rgba& pixel = pixels[ j * resolution.x + i ];

			pixel.r = color.r;
			pixel.g = color.g;
			pixel.b = color.b;
			pixel.a = 1.0;
		}
	}

	Imf::RgbaOutputFile file( "test.exr", resolution.x, resolution.y, Imf::WRITE_RGBA );
	file.setFrameBuffer( pixels, 1, resolution.x );
	file.writePixels( resolution.y );
}

