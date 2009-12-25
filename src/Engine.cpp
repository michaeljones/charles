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

		Imath::Color3f pixelColor(0.0f, 0.0f, 0.0f);
		float pixelOpacity = 0.0f;

		IntersectionPtrList::const_iterator intersection = intersectionList.begin();
		IntersectionPtrList::const_iterator endIntersection = intersectionList.end();

		for ( ; intersection != endIntersection; ++intersection )
		{
			Imath::Color4f color = (*intersection)->getColor();

			pixelColor.x = pixelOpacity * pixelColor.x + (1.0f - pixelOpacity) * color.r;
			pixelColor.y = pixelOpacity * pixelColor.y + (1.0f - pixelOpacity) * color.g;
			pixelColor.z = pixelOpacity * pixelColor.z + (1.0f - pixelOpacity) * color.b;

			pixelOpacity += (1.0f - pixelOpacity) * color.a; 

			if ( pixelOpacity >= 1.0f )
				break;
		}

		it.setColor( Imath::Color4f( pixelColor.x, pixelColor.y, pixelColor.z, pixelOpacity ) );
	}

	std::cerr << "mpj-debug: Done trace" << std::endl;
}


