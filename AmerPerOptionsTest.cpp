//Group B
//To test American perpetual options

//Test file for Group A functions. 
//Batch 1,2,3,4 are stock options. Let C and P denote calls and puts for each batch. Batch1C is a call option for batch 1
//

#include <cmath>
#include <iostream>
#include <vector>
#include "AmerPerOptions.hpp"
#include "GlobalAmerOpt.hpp"
#include "OptionDataAmerPer.hpp"
#include "AmerPerCallOption.hpp"
#include "AmerPerPutOption.hpp"

using namespace std;
using namespace globalAmerOpt;



int main()
{
	AmerPerCallOption Batch1C;	//Test the Call option

	Batch1C.InterestRate(0.1);
	Batch1C.Strike(100.0);
	Batch1C.Volatility(0.1);
	Batch1C.CostOfCarry(0.02);
	Batch1C.StockPrice(110.0);

	cout<< Batch1C.Price()<<endl;

	AmerPerPutOption Batch1P;	//Test the Put option

	Batch1P.InterestRate(0.1);
	Batch1P.Strike(100.0);
	Batch1P.Volatility(0.1);
	Batch1P.CostOfCarry(0.02);
	Batch1P.StockPrice(110.0);

	cout<< Batch1P.Price()<<endl;

/////////////////////////////////////////////////////////////////////////////////////
	//Using Struct to encapsulate option data
	struct OptionDataAmerPer Data1={0.1, 0.1, 100.0, 0.02};
	AmerPerCallOption B1C;
	AmerPerPutOption B1P;
	cout<<"Call option price: "<< B1C.Price(Data1, 110.0)<<endl;	
	cout<<"Put option price: "<< B1P.Price(Data1, 110.0)<<endl;	


/////////////////////////////////////////////////////////////////////////////////////////
	//Mesh size for underlying Stock price. Let the _S indicate it is a mesh for stock price
	double h_S=0;
	double Start_S=0;
	double End_S=0;
	 //User input mesh
	cout<< "Enter Starting value for underlying stock price S: "<<endl;
	cin>> Start_S;

	cout<< "Enter Mesh Size: "<<endl;		
	cin>> h_S ; 

	cout<< "Enter Ending value for S: "<<endl;
	cin>> End_S;

	vector<double> mesh_S = MeshArray(Start_S,h_S,End_S);
	cout<<"Your mesh for S"<<endl;
	print(mesh_S);

	//Option prices at each mesh point of underlying Stock price S for Batch 1. Call and Put
	vector<double> OptionPrice_B1C_S;	//Option price of Batch 1 call, under mesh of stock prices

	for (int i= 0; i< mesh_S.size(); ++i)
	{
		OptionPrice_B1C_S.push_back(B1C.Price(Data1,mesh_S[i])); 
	}
	cout<<"Call Option prices along mesh points of S"<<endl;
	print(OptionPrice_B1C_S);

	vector<double> OptionPrice_B1P_S;	//option price of Batch 1 put, under mesh of stock prices

	for (int i= 0; i< mesh_S.size(); ++i)
	{
		OptionPrice_B1P_S.push_back(PerPutPrice(mesh_S[i],0.1,0.1,100.0,0.02)); 
	}
	cout<<"Put Option prices along mesh points of S"<<endl;
	print(OptionPrice_B1P_S);
//////////////////////////////////////////////////////////////////////////////////////////////
	double K, S, sig , r, b;  

	cout << "K: "; cin >> K;  
	cout << "S: "; cin >> S; 
	cout << "sig: "; cin >> sig;  
	cout << "r: "; cin >> r;  
	cout << "b: "; cin >> b;  
 
	cout << "Price, put, S=" << S<<" :  " << PerPutPrice (S, r, sig, K, b)<<endl;  
	cout << "Price, call, S=" << S<<" :  " << PerCallPrice (S, r, sig, K, b)<<endl; 

}