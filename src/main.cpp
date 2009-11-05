#include "Engine.h"
#include "World.h"
#include "Sphere.h"
#include "PointLight.h"
#include "Output.h"
#include "View.h"

#include <ImathVec.h>

int main( int argc, char** argv )
{
	Imath::V3f sphereCentre( 0.0, 0.0, 10.0 );

	Sphere sphere( 1.0, sphereCentre );

	Imath::V3f lightLocation( 5.0, 5.0, 5.0 );
	PointLight pointLight( lightLocation );

	World world;
	world.addObject( sphere );
	world.addLight( pointLight );

	Imath::V3f cameraPos( 0.0, 0.0, 0.0 );

	Camera camera( cameraPos );

	Imath::V3f centre( 0.0, 0.0, 3.0 );
	Imath::V3f normal( 0.0, 0.0, 1.0 );
	float height = 2.0;
	float width = 3.0;

	Imath::V2i resolution( 200, 300 );
	ImagePlane imagePlane( centre, normal, height, width, resolution );

	View view( camera, imagePlane );

	Engine engine( view, world ); 

	engine.trace();

	Output output( engine );

	output.write();

	return 0;
}

