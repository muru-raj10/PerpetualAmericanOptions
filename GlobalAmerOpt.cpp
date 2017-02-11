//GlobalAmerOpt.cpp
//To define the functions declared in Global.hpp

#ifndef GlobalAmerOpt_cpp
#define Global_cpp

#include <iostream>
#include <string>
#include <cmath>
#include "NormalFunction.cpp"
#include "OptionDataAmerPer.hpp"
#include "GlobalAmerOpt.hpp"

using namespace boost::math;


namespace globalAmerOpt	
{

double PerCallPrice(double S,double r,double sig,double K,double b)
{
	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y1 = 0.5 - b/sig2 + sqrt(fac + 2.0*r/sig2);
	

	if (1.0 == y1)
		return S;

	double fac2 = ((y1 - 1.0)*S) / (y1 * K);
	double c = K * pow(fac2, y1) / (y1 - 1.0);

	return c;
}

double PerPutPrice(double S,double r,double sig,double K,double b) 
{
	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y2 = 0.5 - b/sig2 - sqrt(fac + 2.0*r/sig2);
	
	if (0.0 == y2)
		return S;

	double fac2 = ((y2 - 1.0)*S) / (y2 * K);
	double p = K * pow(fac2, y2) / (1.0 - y2);

	return p;
}


void print(const vector<double>& myVector)	//a print function for vector
{
	vector<double>::const_iterator i;

	for (i = myVector.begin(); i != myVector.end(); ++i)
	{
		cout << *i << ",";
	}
	cout<< endl;
}
//A Mesh Array function
vector<double> MeshArray(double Start, double h, double End)	//creating a mesh
{
	vector<double> mesh;

	for(double i=Start; i<=End; i+=h)
		mesh.push_back(i);

	return mesh;
}

}


#endif