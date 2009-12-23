#include "Engine.h"


void Engine::trace()
{
	// iterate over Rays
	View::iterator it = m_view.begin();
	View::iterator end = m_view.end();

	for ( ; it != end; ++it )
	{
		// Ask world for first intersect
		const IntersectionPtrList intersectionList = m_world.intersect( it.ray() );

		Imath::Color4f pixelColor(0.0f, 0.0f, 0.0f, 0.0f);

		IntersectionPtrList::const_iterator intersection = intersectionList.begin();
		IntersectionPtrList::const_iterator endIntersection = intersectionList.end();

		for ( ; intersection != endIntersection; ++intersection )
		{
			Imath::Color4f color = (*intersection)->getColor();

			pixelColor += color;

			if ( color.a >= 1.0f )
				break;
		}

		it.setColor( pixelColor );
	}

	std::cerr << "mpj-debug: Done trace" << std::endl;
}


