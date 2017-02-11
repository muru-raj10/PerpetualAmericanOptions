//OptionData.hpp
//To define struct to input option data

#ifndef OptionDataAmerPer_hpp
#define OptionDataAmerPer_hpp

//Encapsulate all data in one place with the exception of Underlying Stock price S
struct OptionDataAmerPer
{//Option data + behaviour(all public)
	double r;
	double sig;
	double K;
	double b;
};


#endif