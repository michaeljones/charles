#ifndef __CHARLES_ENGINE_H__
#define __CHARLES_ENGINE_H__

#include "World.h"
#include "View.h"

class Engine 
{
public:

	Engine( View& view, const World& world )
	 :	m_world( world ),
		m_view( view)
	{};

	void trace();

private:

	const World& m_world;
	View& m_view;

};

#endif

