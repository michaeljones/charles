#ifndef __CHARLES_OUTPUT_H__
#define __CHARLES_OUTPUT_H__

#include "Engine.h"

class Output 
{
public:

	Output( const Engine& engine )
	 :	m_engine( engine )
	{};

	void write() {};

private:

	const Engine& m_engine;

};

#endif

