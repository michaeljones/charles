#include "NormalMaterial.h"

#include "intersections/Intersection.h"

Imath::Color4f NormalMaterial::evaluate( const Intersection* intersection ) const
{
	Imath::V3f normal = intersection->normal();

	return Imath::Color4f( normal.x, normal.y, normal.z, 1.0f );
}


