//AmerPerCallOptiop.hpp
//derived class of options.

#ifndef AmerPerCallOption_hpp
#define AmerPerCallOption_hpp

#include <iostream>
#include <string>
#include <cmath>

#include "AmerPerOptions.hpp"
#include "stdlib.h"
using namespace std;

class AmerPerCallOption : public AmerPerOptions
{
private:
	string optType;	// Option name (call) is constant. But instead of making it const,
					//declared it as private so that it is not modifyable by users. 
					//No modifying member functions
public:
	//Constructors and destructors
	AmerPerCallOption();
	AmerPerCallOption(const AmerPerCallOption & o2);
	virtual ~AmerPerCallOption();

	//Assignment operator
	AmerPerCallOption& operator = (const AmerPerCallOption& option2);

	//Accessing Functions	//Normal inline 
	string TypeOfOption() const;

	//Member functions				//Const functions do not change the value of data member
	double Price() const;			//To determine call option price
	double Price(const struct OptionDataAmerPer& Opt, double U);	//To determine call option price using Struct

};
//Normal inline
inline string AmerPerCallOption::TypeOfOption() const { return optType; }

#endif