// Colby Sheppard
// 801005669
// MATH 1165 Project 3
// Due: 11/22/2019
// Notes: Compiled and tested within Ubuntu Build 18.04

#include <iostream>						//Needed for std::cout, std::cin, std::fixed
#include <iomanip>						//Needed for std::setprecision()

using namespace std;

int main(){

	long double n,b,c,d,r = 0; 			//Long Double used for larger memory and higher precision
										
	std::cout << "Input any integer from 1 to infinity to find the number of routes for that square matrix." << endl;
	std::cin >> n;						//Input works for all integers between 1 and 1477
	
	b = 2*n;							//Doubles input to be used in first for loop
	c = 1;
	d = 1;
	
	for(int i = b; i > n; i--){			//Top of equation to find lattice paths
		c *= i;
	}
	
	for(int j = n; j > 1; j--){			//Bottom of equation to find lattice paths
		d *= j;
	}
	
	r = c/d;							//Combined equation of ((2n!/n!)/n!)
	
	std::cout << endl << std::fixed;	//std::fixed forces double form over scientific notation
	std::cout << "Number of possible routes:" << endl << std::setprecision(0) << r << endl;
										//std::setprecision(0) creates double with no decimals
										//and basically creating an integer with less precision
return 0;
}
