//AmerPerOptions.cpp
//Defining Functions of EuropeanOptions.hpp

#ifndef AmerPerOptions_cpp
#define AmerPerOptions_cpp

#include <iostream>
#include <string>
#include <cmath>

#include "stdlib.h"
#include "AmerPerOptions.hpp"
#include "GlobalAmerOpt.hpp"
#include "OptionDataAmerPer.hpp"
using namespace std;


void AmerPerOptions::init()	//Function to inlitialise
{
	S=60.0;
	r = 0.08;
	sig= 0.3;
	K = 65.0;
	b = r;			// Black and Scholes stock option model (1973)
}

void AmerPerOptions::copy( const AmerPerOptions& o2)	//Function to copy
{
	S=o2.S;
	r	= o2.r;
	sig = o2.sig;	
	K	= o2.K;
	b	= o2.b;
	
}


AmerPerOptions::AmerPerOptions()	//Default European option
{
	init();
}

AmerPerOptions::AmerPerOptions(const AmerPerOptions& o2)
{ 
	// Copy constructor
	copy(o2);
}

AmerPerOptions::~AmerPerOptions()
{
	//Destructor
}

AmerPerOptions& AmerPerOptions::operator = (const AmerPerOptions& option2)	//Assignment operator
{
	if (this == &option2) return *this;

	copy (option2);

	return *this;
}



#endif