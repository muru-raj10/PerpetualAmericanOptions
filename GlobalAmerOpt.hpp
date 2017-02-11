//GlobalAmerOpt.hpp
//To define some global functions for American Options

#ifndef GlobalAmerOpt_hpp
#define GlobalAmerOpt_hpp

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#include "OptionDataAmerPer.hpp"


namespace globalAmerOpt	//To solve the problem of nameclashes in a global scope
{
	//Price functions
	double PerCallPrice(double S,double r,double sig,double K,double b);	//Price of a general call option
	double PerPutPrice(double S,double r,double sig,double K,double b);	//Price of a general put option

	void print(const vector<double>& myVector);		//a print function for vector

	vector<double> MeshArray(double Start, double h, double End); //Function that creates a mesh in 1 variable
	

}


#endif