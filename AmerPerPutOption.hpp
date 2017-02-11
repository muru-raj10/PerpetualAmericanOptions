//AmerPerPutOption.hpp
//Derived class of EuropeanOptions. Generic inheritance

#ifndef AmerPerPutOption_hpp
#define AmerPerPutOption_hpp

#include <iostream>
#include <string>
#include <cmath>

#include "AmerPerOptions.hpp"
#include "stdlib.h"
using namespace std;

class AmerPerPutOption : public AmerPerOptions
{
private:
	string optType;	// Option name (call) is constant. But instead of making it const,
					//declared it as private so that it is not modifyable by users. 
					//No modifying member functions

public:
	
	//Constructors and destructors
	AmerPerPutOption();
	AmerPerPutOption(const AmerPerPutOption & o2);
	virtual ~AmerPerPutOption();

	//Assignment operator	 
	AmerPerPutOption& operator = (const AmerPerPutOption& option2);

	//Accessing Functions	//Normal inline 
	string TypeOfOption() const;

	//Member functions					//Const functions do not change the value of data member
	double Price() const;				//To determine Put option price
	double Price(const struct OptionDataAmerPer& Opt, double U);	//To determine Put option price using Struct

};
//Normal Inline function
inline string AmerPerPutOption::TypeOfOption() const { return optType; }

#endif