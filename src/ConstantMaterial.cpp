#include "ConstantMaterial.h"


ConstantMaterial::ConstantMaterial( Imath::Color4f color )
 :	m_color( color )
{

}

Imath::Color4f ConstantMaterial::evaluate( const Intersection* intersection ) const 
{
	return m_color;
}


