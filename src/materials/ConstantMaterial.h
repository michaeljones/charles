#ifndef __CHARLES_CONSTANTMATERIAL_H__
#define __CHARLES_CONSTANTMATERIAL_H__

#include "Material.h"


class ConstantMaterial : public Material
{
public:

	ConstantMaterial( Imath::Color4f color );

	virtual Imath::Color4f evaluate( const Intersection* intersection ) const;

private:

	ConstantMaterial( const ConstantMaterial& material );

private:

	Imath::Color4f m_color;

};

#endif

