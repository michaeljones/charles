#ifndef __CHARLES_IMAGEPLANE_H__
#define __CHARLES_IMAGEPLANE_H__

#include <ImathColor.h>

typedef Imath::V2i Coordinate;

class ImagePlane
{
public:

	ImagePlane(
			Imath::V3f centre,
			Imath::V3f x,
			Imath::V3f y,
			float height,
			float width,
			Imath::V2i resolution
			);

	~ImagePlane();

	const Imath::V2i& resolution() const { return m_resolution; }

	Imath::V3f worldSpace( const Imath::V2i& coordinate ) const;

	void setColor( Coordinate coord, Imath::Color3< float > color );
	Imath::Color3< float > getColor( Coordinate coord ) const;

private:

	ImagePlane() {};
	ImagePlane( const ImagePlane& imagePlane ) {};

private:

	Imath::V3f m_position;
	Imath::V3f m_x;
	Imath::V3f m_y;
	float m_height;
	float m_width;
	Imath::V2i m_resolution;

	Imath::Color3< float >* m_imageData;

};

#endif

