#include "objects/Sphere.h"
#include "objects/ClippingPlane.h"
#include "lights/PointLight.h"
#include "materials/ConstantMaterial.h"
#include "materials/NormalMaterial.h"
#include "outputs/Output.h"
#include "Engine.h"
#include "World.h"
#include "View.h"

#include <ImathVec.h>

int main( int argc, char** argv )
{
	IntersectionFactory intersectionFactory;
	World world( intersectionFactory );

	Imath::Color4f blue( 0.0, 0.0, 1.0, 0.5 );
	ConstantMaterial blueMaterial( blue );

	NormalMaterial normalMaterial;

	Imath::V3f sphereCentre( 0.0, 0.0, 10.0 );
	Sphere sphere( 2.0, sphereCentre, blueMaterial );
	world.addObject( sphere );

	Imath::Color4f green( 0.0, 1.0, 0.0, 1.0 );
	ConstantMaterial greenMaterial( green );

	Imath::V3f sphereCentre2( 3.0, 0.0, 15.0 );
	Sphere sphere2( 2.0, sphereCentre2, greenMaterial );
	world.addObject( sphere2 );

	Imath::Color4f red( 1.0, 0.0, 0.0, 1.0 );
	ConstantMaterial redMaterial( red );

	Imath::V3f planePos( 0.0, 0.0, 20.0 );
	Imath::V3f planeNormal( 0.0, 0.0, 1.0 );
	ClippingPlane plane( planePos, planeNormal, redMaterial );
	world.addObject( plane );

	Imath::V3f lightLocation( 5.0, 5.0, 5.0 );
	PointLight pointLight( lightLocation );
	world.addLight( pointLight );

	Imath::V3f cameraPos( 0.0, 0.0, 0.0 );

	Camera camera( cameraPos );

	Imath::V3f centre( 0.0, 0.0, 3.0 );
	Imath::V3f x( 1.0, 0.0, 0.0 );
	Imath::V3f y( 0.0, 1.0, 0.0 );
	float height = 2.0;
	float width = 3.0;

	Imath::V2i resolution( 300, 200 );
	ImagePlane imagePlane( centre, x, y, height, width, resolution );

	View view( camera, imagePlane );

	Engine engine( view, world ); 

	engine.trace();

	Output output( imagePlane );
	output.write();

	return 0;
}

