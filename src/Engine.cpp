#include "Engine.h"


void Engine::trace()
{
	// iterate over Rays
	View::iterator it = m_view.begin();
	View::iterator end = m_view.end();

	for ( ; it != end; ++it )
	{
		// Ask world for first intersect
		const Intersection& intersect = m_world.intersect( it.ray() );

		it.setColor( intersect.getColor() );
	}

	std::cerr << "mpj-debug: Done trace" << std::endl;
}


