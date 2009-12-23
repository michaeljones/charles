#ifndef __CHARLES_NORMALMATERIAL_H__
#define __CHARLES_NORMALMATERIAL_H__

#include "Material.h"


class NormalMaterial : public Material
{
public:

	NormalMaterial() {};

	virtual Imath::Color4f evaluate( const Intersection* intersection ) const;

private:

	NormalMaterial( const NormalMaterial& material );

private:

};

#endif

