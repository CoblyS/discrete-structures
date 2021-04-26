// Colby Sheppard
// 801005669
// MATH 1165 Project 1
// Due: 10/4/2019
// Notes: Compiled and tested within Ubuntu Build 18.04

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int gcd(int a, int b, int &x, int &y){          // I calculated the GCD using recursion
	
	int x1, y1, d;
	
	if (b==0){                              // If statements used to stop the function if either the a or b inputs are equal to 0
		x = 1;
		y = 0;
		return a;
	}
	else if(a==0){
		x = 0;
		y = 1;
		return b;
	}
	
	d = gcd(b, a%b, x1, y1);                // Recursion of variables using b and a mod b to find a common divider
						// Also passes values back to x1 and y1 to find the linear combination of a and b for the gcd
	x = y1;					// Uses recursion as well to find the x and y for the linar combination
	y = x1 - (a / b) * y1;
	
	return d;				// Returns the final gcd of a and b as variable d to int main()
}

int main() {
	
	int a, b, x, y, d;                      // Variables for gcd and linear combinations of a and b
	
	cout<<"Enter two integers for which you want to find the GCD:" << endl;
	cout<<"a: ";
	cin>>a;					// Separated input lines for a and b
	cout<<"\nb: ";
	cin>>b;

	if(abs(a) < abs(b)){			// Swaps a and b so they are in numerical order, reduces number of lines of code
		swap(a, b);
	}

	d=gcd(abs(a), abs(b), x, y);		// Sends a and b as absolute value to allow for negative inputs
						// Also sends variables for x and y using pass by reference in the function
        if(a<0){
                x = -x;				// Takes x and y and outputs the negative of x and y to correct the linear combination if neccessary
        }

        if(b<0){
                y = -y;
        }

	cout<<"\nThe GCD of " << a << " and " << b << " is equal to " << d << endl;
	cout<<"The Linear Combination for the GCD of " << a << " and " << b << " is equal to " << a << "x + " << b << "y, where x equals: " << x << " and y equals: " << y << "." << endl;
	cout<< a << "(" << x << ")" <<" + " << b << "(" << y << ")" << " = " << d << endl;
	
	return 0;
}
