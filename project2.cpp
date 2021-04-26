// Colby Sheppard
// 801005669
// MATH 1165 Project 2
// Due: 10/18/2019
// Notes: Compiled and tested within Ubuntu Build 18.04

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

	int euclid(int a, int b, int &x, int &y){          	//Used Extended Euclidean algorithm from project 1
														//Same recursive method to find gcd of a and b
		int x1, y1, d;									//a and b are integer and modulo inputs respectively
														//finds linear combination ax+by=gcd(a,b)
		if (b==0){                              
			x = 1;
			y = 0;
			return a;
		}
		else if(a==0){
			x = 0;
			y = 1;
			return b;
		}
		
		d = euclid(b, a%b, x1, y1);                
							
		x = y1;					
		y = x1 - (a/b) * y1;
		
		return d;										//returns d being the gcd of a and b
	}

	int main() {
		
		int a, b, x, y, gcd, modinv, n;                      
		
		cout<<"Enter modulus n and integer a." << endl;
		cout<<"n: ";
		cin>>n;
		cout<<"\na: ";
		cin>>a;
		
		b = n;											//sets b equal to n for a and b to go to gcd function
		
		gcd=euclid(abs(a), abs(b), x, y);				//calls gcd function, x and y for pass by reference
							
		if(a<0){
		    x = -x;				
		}

		if(b<0){
		    y = -y;
		}

	    if(x < 0){										//invmod must be positive
		    modinv = b + x;								//x is the variable tied to the integer a
	    }												//x signifies the invmod
	    else{											//method of finding x was using backwards substitution
		    modinv = x;									//within the recursive function to find gcd
	    }
        
		cout<<"\nGCD: " << gcd << endl;
		cout<< a << "(" << x << ")" <<" + " << b << "(" << y << ")" << " = " << gcd << endl;
		cout<<"Inverse Modulo (a^-1): " << modinv << endl;
		
		return 0;
	}
