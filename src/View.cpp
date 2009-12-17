#include "View.h"


View::iterator View::begin() const
{
	Coordinate start( 0, 0 );
	return View::iterator( m_camera, m_imagePlane, start );
}

View::iterator View::end() const
{
	Coordinate coordinate( m_imagePlane.resolution() );
	coordinate.x -= 1;
	coordinate.y -= 1;

	return View::iterator( m_camera, m_imagePlane, coordinate );
}

View::iterator::iterator(
	const Camera& camera,
	ImagePlane& imagePlane,
	const Imath::V2i& coordinate
	)
 :	m_camera( camera ),
	m_imagePlane( imagePlane ),
	m_coordinate( coordinate )
{
}

View::iterator::iterator( const iterator& it )
 :	m_camera( it.m_camera ),
	m_imagePlane( it.m_imagePlane ),
	m_coordinate( it.m_coordinate )
{
}

void View::iterator::setColor( const Imath::Color3f& color )
{
	m_imagePlane.setColor( m_coordinate, color );
}


Ray View::iterator::ray() const
{
	Imath::V3f start( m_imagePlane.worldSpace( m_coordinate ) );
	Imath::V3f direction( m_imagePlane.worldSpace( m_coordinate ) - m_camera.position() );

	direction = direction.normalize();

	return Ray( start, direction );
}

View::iterator& View::iterator::operator++()
{
	m_coordinate.x = ( m_coordinate.x + 1 ) % m_imagePlane.resolution().x;

	if ( m_coordinate.x == 0 )
		++m_coordinate.y;
}

bool View::iterator::operator==( const View::iterator& it )
{
	return m_coordinate == it.m_coordinate;
}

bool View::iterator::operator!=( const View::iterator& it )
{
	return m_coordinate != it.m_coordinate;
}


