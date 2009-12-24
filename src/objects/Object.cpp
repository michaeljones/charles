#include "Object.h"

#include "materials/Material.h"

Object::Object( Material& material )
 :	m_material( material )
{

}


Object::Object( const Object& obj )
 :	m_material( obj.m_material )
{

}


Imath::Color4f Object::shade( const Intersection* intersection ) const
{
	return m_material.evaluate( intersection );
}

