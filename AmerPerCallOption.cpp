//AmerPerCallOption.cpp
//To declare functions from AmerPerCallOption.hpp

#ifndef AmerPerCallOption_cpp
#define AmerPerCallOption_cpp

#include <iostream>
#include <string>
#include <cmath>

#include "stdlib.h"
#include "AmerPerCallOption.hpp"
#include "AmerPerOptions.hpp"
#include "GlobalAmerOpt.hpp"
#include "OptionDataAmerPer.hpp"
using namespace std;
using globalAmerOpt::PerCallPrice;
using globalAmerOpt::PerPutPrice;


AmerPerCallOption:: AmerPerCallOption() : AmerPerOptions(), optType("C")	//Call option 
{
	//Default Constructor. 
}

AmerPerCallOption::AmerPerCallOption(const AmerPerCallOption& o2) : AmerPerOptions(o2), optType(o2.optType)
{ 
	//Copy constructor
}

AmerPerCallOption::~AmerPerCallOption()	//Destructor
{

}

AmerPerCallOption& AmerPerCallOption::operator = (const AmerPerCallOption& option2)	//Assigmnent operator
{
	if (this == &option2) return *this;
	{
		AmerPerOptions::operator=(option2);
		optType=option2.optType;				
	}
	return *this;
}

double AmerPerCallOption::Price() const	//Use global function for Call option Price
{
	cout<<"Call Option Price: ";
	return PerCallPrice(S,r,sig,K,b);
}

double AmerPerCallOption::Price(const struct OptionDataAmerPer& Opt, double U)
{
	//Assign values of the struct to an Object of EurCallOption and pass it to the function in main
	r=Opt.r;
	sig=Opt.sig;
	K=Opt.K;
	b=Opt.b;

	//cout << "Call option price: ";
	return PerCallPrice(U,r,sig,K,b);
}


#endif