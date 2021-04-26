// Colby Sheppard
// 801005669
// MATH 1165 Project 4
// Due: 12/10/2019
// Notes: Compiled and tested within Ubuntu Build 18.04

#include <iostream>
#include <math.h>

using namespace std;

int main(){
	double c, d, a0, a1, r1, r2, r, u, v, ut, vt, ub, sqrroot = 0;
	// Uses double variables in the case of decimals
	
	cout << "Input variables c, d, a0 and a1." << endl;
	cin >> c;
	cin >> d;
	cin >> a0;
	cin >> a1;
	// Takes all four inputs from user
	
	c = 0 - c;
	d = 0 - d;
	
	//cout << c << endl << d << endl << a0 << endl << a1 << endl;
	
	sqrroot = (c*c)-(4*d);
	
	if(sqrroot < 0){
		cout << "INVALID INPUTS -- ROOTS ARE IMAGINARY" << endl;
		return 0;
	}
	// Checks for imaginary roots from inputs, cuts code if imaginary
	
				//cout << "square root = " << sqrroot << endl;
	
	r1 = ((-1*c)-(sqrt(sqrroot)))/2;
	r2 = ((-1*c)+(sqrt(sqrroot)))/2;
	// Gets roots using quadratic formula
				cout << "r1 = " << r1 << endl << "r2 = " << r2 << endl;
	
	if(r1 == r2){
		r = r1;
		u = a0;
		
		vt = a1 - (r*u);
		v = vt/r;
		
		cout << "a_n = (" << u << ")(" << r << ")^n + n(" << v << ")(" << r << ")^n" << endl;
	}
	else{
		ut = (r2*a0) - a1;
		ub = r2 - r1;
		u = ut/ub;
		
		vt = a1 - (r1*u);
		v = vt/r2;
		
		cout << "a_n = (" << u << ")(" << r1 << ")^n + (" << v << ")(" << r2 << ")^n" << endl;
	}
	// Closed form using either formula with r1 = r2 or r1 != r2
	// r1 != r2 uses a_n = u*(r1^n) + v*(r2^n)
	// r1 = r2 uses a_n = u*(r^n) + v*n*(r^n) 
	
	
return 0;
}
