#include "Output.h"

#include <fstream>


void Output::write()
{
	std::ofstream out;
	
	out.open( "test.txt" );

	Imath::V2i resolution = m_imagePlane.resolution();

	for ( int i=0; i<resolution.x; ++i )
	{
		for ( int j=0; j<resolution.y; ++j )
		{
			if ( m_imagePlane.getColor( Coordinate( i, j ) ) == Imath::Color3f( 1.0, 0.0, 0.0 ) )
				out << "# ";
			else if ( m_imagePlane.getColor( Coordinate( i, j ) ) == Imath::Color3f( 0.0, 0.0, 1.0 ) )
				out << ". ";
		}
		out << std::endl;
	}

	out.close();
}

