#ifndef __CHARLES_VIEW_H__
#define __CHARLES_VIEW_H__

#include "Camera.h"
#include "ImagePlane.h"
#include "Ray.h"

class View
{
public:

	View( const Camera& camera, ImagePlane& imagePlane )
	 :	m_camera( camera ),
		m_imagePlane( imagePlane )
	{}

	class iterator
	{
	public:

		iterator(
			const Camera& camera,
			ImagePlane& imagePlane,
			const Imath::V2i& coordinate
			);

		iterator( const iterator& it );

		Ray ray() const;

		void setColor( const Imath::Color3f& color );

		iterator& operator++();
		bool operator==( const iterator& it );
		bool operator!=( const iterator& it );

	private:

		ImagePlane& m_imagePlane;
		const Camera& m_camera;

		Coordinate m_coordinate;
	};

	iterator begin() const;

	iterator end() const;

private:

	const Camera& m_camera;
	ImagePlane& m_imagePlane;
};

#endif

