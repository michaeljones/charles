#ifndef __CHARLES_MATERIAL_H__
#define __CHARLES_MATERIAL_H__

#include "Intersection.h"

#include "ImathColor.h"


class Material
{
public:

	Material();

	virtual Imath::Color4f evaluate( const Intersection* intersection ) const = 0;

private:

	Material( const Material& material );

private:

};

#endif

