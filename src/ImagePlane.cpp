#include "ImagePlane.h"

ImagePlane::ImagePlane(
			Imath::V3f centre,
			Imath::V3f x,
			Imath::V3f y,
			float height,
			float width,
			Imath::V2i resolution
			)
 :	m_position( centre ),
	m_x( x ),
	m_y( y ),
	m_height( height ),
	m_width( width ),
	m_resolution( resolution ),
	m_imageData( 0 )
{
	m_imageData = new Imath::Color4f[ resolution.x * resolution.y ];
};


ImagePlane::~ImagePlane()
{
	delete m_imageData;
}


void ImagePlane::setColor( Coordinate coord, Imath::Color4< float > color )
{
	m_imageData[ coord.y * m_resolution.x + coord.x ] = color;
}

Imath::Color4< float > ImagePlane::getColor( Coordinate coord ) const
{
	return m_imageData[ coord.y * m_resolution.x + coord.x ];
}


Imath::V3f ImagePlane::worldSpace( const Imath::V2i& coordinate ) const
{
	Imath::V3f pos( m_position );
	pos += ( ( float( coordinate.x ) / m_resolution.x ) - 0.5f ) * m_width * m_x;
	pos += ( ( float( coordinate.y ) / m_resolution.y ) - 0.5f ) * m_height * m_y;

	return pos;
}

