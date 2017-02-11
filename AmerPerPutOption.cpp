//AmerPerPutOption.cpp
//To declare functions from EurPutOption.hpp

#ifndef AmerPerPutOption_cpp
#define AmerPerPutOption_cpp

#include <iostream>
#include <string>
#include <cmath>

#include "stdlib.h"
#include "AmerPerPutOption.hpp"
#include "AmerPerOptions.hpp"
#include "GlobalAmerOpt.hpp"
#include "OptionDataAmerPer.hpp"
using namespace std;
using globalAmerOpt::PerCallPrice;
using globalAmerOpt::PerPutPrice;


AmerPerPutOption:: AmerPerPutOption() : AmerPerOptions() , optType("P")	//Put option //Default Constructor
{

}

AmerPerPutOption::AmerPerPutOption(const AmerPerPutOption& o2) : AmerPerOptions(o2), optType(o2.optType)
{ 
	//Copy constructor
}

AmerPerPutOption::~AmerPerPutOption()	//Destructor
{
	
}

AmerPerPutOption& AmerPerPutOption::operator = (const AmerPerPutOption& option2)	//Assignment operator
{
	if (this == &option2) return *this;
	{
		AmerPerOptions::operator=(option2);
		optType=option2.optType;
	}
	return *this;
}

double AmerPerPutOption::Price() const		//Use global function for put option price
{
	cout << "Put option price: ";
	return PerPutPrice(S,r,sig,K,b);
}

double AmerPerPutOption::Price(const struct OptionDataAmerPer& Opt, double U)
{
	//Assign values of the struct to an Object of EurPutOption and pass it to the function in main
	r=Opt.r;
	sig=Opt.sig;
	K=Opt.K;
	b=Opt.b;

	//cout << "Put option price: ";
	return PerPutPrice(U,r,sig,K,b);
}

#endif