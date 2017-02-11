//AmerPerOptions.hpp
//Abstract Base Class for American perpetual call and put options

#ifndef AmerPerOptions_hpp
#define AmerPerOptions_hpp

#include <iostream>
#include <string>
#include <cmath>

#include "stdlib.h"
using namespace std;

class AmerPerOptions
{
protected:

	//Protected functions to initialise variables and copy variables. Accessible by derived class
	void init();				// To Initialise all default values
	void copy(const AmerPerOptions& o2);	//To copy the values

	//Data members for an option. Protected members to be accessible by derived class
	double S;		// Stock Price 
	double r;		// Interest rate
	double sig;		// Volatility
	double K;		// Strike price
	double b;		// Cost of carry

public:

	//Constructors and destructors
	AmerPerOptions();
	AmerPerOptions(const AmerPerOptions & o2);
	virtual ~AmerPerOptions();

	//Assignment operator
	AmerPerOptions& operator = (const AmerPerOptions& option2);

	//Accessing functions	//Normal inline functions
	double StockPrice() const;
	double InterestRate() const;
	double Volatility() const;
	double Strike() const;
	double CostOfCarry() const;

	//Modifiers //Default inline functions
	void StockPrice(double newS) {S=newS;};
	void InterestRate(double newr) {r=newr;};
	void Volatility(double newsig) {sig=newsig;};
	void Strike(double newK) {K=newK;};
	void CostOfCarry(double newb) {b=newb;};

	//Using polymorphism to define different behaviours for functions
	//Other member function(Pure virtual functions since Price will be overridden by either put price or call price)
	virtual double Price() const=0;					//Price function to determine the price in derived class
	virtual double Price(const struct OptionDataAmerPer& Opt, double U)=0;		//To determine price using Struct in derived class


};
//Normal inline functions
inline double AmerPerOptions::StockPrice() const {return S; }
inline double AmerPerOptions::InterestRate() const { return r; }
inline double AmerPerOptions::Volatility() const { return sig; }
inline double AmerPerOptions::Strike() const { return K; }
inline double AmerPerOptions::CostOfCarry() const { return b; }


#endif