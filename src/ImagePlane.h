#ifndef __CHARLES_IMAGEPLANE_H__
#define __CHARLES_IMAGEPLANE_H__

class ImagePlane
{
public:

	ImagePlane(
			Imath::V3f centre,
			Imath::V3f normal,
			float height,
			float width,
			Imath::V2i resolution
			)
	 :	m_position( centre ),
		m_normal( normal ),
		m_height( height ),
		m_width( width ),
		m_resolution( resolution )
	{};

private:

	ImagePlane() {};
	ImagePlane( const ImagePlane& imagePlane ) {};

private:

	Imath::V3f m_position;
	Imath::V3f m_normal;
	float m_height;
	float m_width;
	Imath::V2f m_resolution;

};

#endif

