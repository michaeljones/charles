#include "Engine.h"
#include "World.h"
#include "Sphere.h"
#include "ClippingPlane.h"
#include "PointLight.h"
#include "Output.h"
#include "View.h"

#include <ImathVec.h>

int main( int argc, char** argv )
{
	IntersectionFactory intersectionFactory;
	World world( intersectionFactory );

	Imath::V3f sphereCentre( 0.0, 0.0, 10.0 );
	Sphere sphere( 2.0, sphereCentre );
	world.addObject( sphere );

	Imath::V3f planePos( 0.0, 0.0, 20.0 );
	Imath::V3f planeNormal( 0.0, 0.0, 1.0 );
	ClippingPlane plane( planePos, planeNormal );
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

	Imath::V2i resolution( 200, 300 );
	ImagePlane imagePlane( centre, x, y, height, width, resolution );

	View view( camera, imagePlane );

	Engine engine( view, world ); 

	engine.trace();

	Output output( imagePlane );
	output.write();

	return 0;
}

