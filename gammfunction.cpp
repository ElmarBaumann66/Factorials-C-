//*********************************
//*                               *
//* Code-Sample                   *
//* BaumannSoftware               *
//* Elmar Baumann                 *
//*                               *
//*********************************

#include<iostream>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;

double DecimalFactorial( double z)
{
 double g = 0.5772156649;  // Euler-Mascheroni constant
 double zi = floor(z);     // integer part of z
 double zf = z - zi;       // fractional part of z
 double retVal = zf*exp(g*zf);
 double x = 1.0;
 unsigned n=0;

 do  // calculate Gamma for the fractional part of z
 {
  ++n;
  x = (1 + zf/n)*exp(-zf/n);
  retVal *= x;
 } 
 while( x < (1 - 1e-12) );

 retVal = 1.0/retVal;// invert

 // build up the value using the identity.
 for(double y = 0.0; y < zi - 0.5; ++y)
 {
  retVal *= y + zf;
 }


 retVal = retVal*z;
	    
 return retVal;
}


bool check(double value)
{
 return (value - std::floor(value)) == .0;
}


int IntegerFactorial(int Value)
{
 int factorial = 1;
    
 if(Value < 0)
 {
  cout << "\nError! Factorial of a negative Number doesn't exist.";
 }
 else
 {
  for(int i = 1; i <= Value; ++i) 
  {
   factorial *= i;
  }
 }

 return factorial;	
}


int main()
{
 int z;
 double num,gamma;
 
 cout<<"Enter the number to calculate: ";
 cin >> num;
 cout<<"\nCalculate Factorials of: " << num;
 
 if(check(num) == true)
 {
  //double-value is as well an integer, <.00> is given
    
  z = static_cast<int>(num);
  gamma = IntegerFactorial(z);
  cout<<"\nThe Factorial of the Integer is: "<<gamma<<endl;
 }
 else
 {
  gamma=DecimalFactorial(num);
  cout<<"\nThe Gamma-Factorial of the Decimal is: "<<gamma<<endl;
 }

 
 cin.get();
 return 0;
}
