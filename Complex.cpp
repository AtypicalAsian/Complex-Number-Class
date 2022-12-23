//=================================================
// Nicolas Nguyen
// Complex.cpp 
// This file contains the class implementation for the 
// Complex number class. 
//=================================================

#include "Complex.h" 
#include <iomanip> 
#include <math.h> 
#include <sstream> 

//======================================================
// Default Constructor to create Complex object
// PARAMETERS: none
// RETURN: none but sets real=0 and imaginary=0
//======================================================
		Complex::Complex ( void )
{ 
	real = 0; 
	imag = 0; 
} 

//====================================================== 
// Complex (a,b)
// Complex constructor to create Complex object 
// imaginary components  
// PARAMETERS: 
//	a: a specified real component
//	b: a specified imaginary component 
// RETURN: None but constructs a new Complex type with 
// 		   specified real and imaginary components 
//======================================================
		Complex::Complex ( float a, float b )
{
	real = a; 
	imag = b;
	
}


//======================================================
// copy
// Create a new complex type from an existing one 
// PARAMETERS: const reference to Complex c 
// RETURN: none but creates a new Complex identical to the 
// 		   existing one 
//======================================================
		Complex::Complex ( const Complex &c )
{
	real = c.real; 
	imag = c.imag; 
}


//======================================================
// destructor
// PARAMETERS: none
// RETURN: none 
//======================================================
		Complex::~Complex     ( void )
{

}


//======================================================
// operator=
// c1 = c2
// Assignment operator
// PARAMETERS:
// const Complex object c
// RETURN VALUE:
// real and imaginary components are assigned to *this and then
// *this is returned
//======================================================
Complex	  Complex::operator=	( const Complex &c )
{
	real = c.real; 
	imag = c.imag;
	return *this;  
}

//======================================================
// operator+
// c1 = c2 + c3
// Will take the components of c2 + c3 and return them
// to c1.
// PARAMETERS:
// const reference to Complex c 
// RETURN VALUE:
// returns sum of *this + c
//======================================================
Complex	  Complex::operator+	( const Complex &c ) const 
{
	Complex ret; 
	ret.real = real + c.real; 
 	ret.imag = imag + c.imag; 
 	return ret; 
}

//======================================================
// operator+
// c1 = c2 + f
// Will take the components of c2 + f and return them
// to c1.
// PARAMETERS:
// float f
// RETURN VALUE:
// returns sum of *this + f 
//======================================================
Complex	  Complex::operator+	( float f ) const
{
	Complex ret; 
	ret.real = real + f; 
	ret.imag = imag; 
	return ret; 
}

//======================================================
// operator-
// c1 = c2 - c3
// Will take the components of c2 - c3 and return them
// to c1.
// PARAMETERS:
// const reference to Complex c 
// RETURN VALUE:
// returns sum of *this - c 
//======================================================
Complex	  Complex::operator-	( const Complex &c ) const
{
	Complex ret; 
	ret.real = real - c.real; 
 	ret.imag = imag - c.imag; 
 	return ret; 
}

//======================================================
// operator-
// c1 = c2 - f
// Will take the components of c2 - f and return them
// to c1.
// PARAMETERS:
// float f
// RETURN VALUE:
// returns sum of *this - f 
//======================================================
Complex	  Complex::operator-	( float f ) const
{
	Complex ret; 
	ret.real = real - f; 
	ret.imag = imag; 
	return ret; 
}

//======================================================
// operator*
// c1 = c2 * c3
// Will take the components of c2 * c3 and return them
// to c1.
// PARAMETERS:
// const reference to Complex c 
// RETURN VALUE:
// returns product of *this * c
//======================================================
Complex	  Complex::operator*	( const Complex &c ) const
{
	Complex ret; 
	ret.real = real*c.real + imag*c.imag*-1; 
	ret.imag = real*c.imag + c.real*imag; 
	return ret; 
}

//======================================================
// operator*
// c1 = c2 * f
// Will take the components of c2 * f and return them
// to c1.
// PARAMETERS:
// float f
// RETURN VALUE:
// returns sum of *this * f 
//======================================================
Complex   Complex::operator*	( float f ) const
{
	Complex ret; 
	ret.real = real*f; 
	ret.imag = imag*f; 
	return ret; 
}

//======================================================
// operator/
// c1 = c2 / c3
// Will take the components of c2 / c3 and return them
// to c1.
// PARAMETERS:
// const reference to Complex c 
// RETURN VALUE:
// returns result of complex number division c2/c3
//======================================================
Complex	  	Complex::operator/	( const Complex &c ) const 
{
 	Complex caller, num, denom, ret; 
 	caller.real = real; caller.imag = imag; 
 	num = caller* (~c); 
 	denom = c * (~c); 
 	ret.real = num.real / denom.real; 
 	ret.imag = num.imag / denom.real; 
	return ret;  
}


//======================================================
// operator/
// c1 = c2 / f
// Will take the components of c2 / f and return them
// to c1.
// PARAMETERS:
// float f
// RETURN VALUE:
// returns result of *this / f
//======================================================
Complex	  Complex::operator/	( float f ) const
{
	Complex ret; 
	ret.real = real/f;
	ret.imag = imag/f; 
	return ret; 
}


//======================================================
// operator~
// ~c
// PARAMETERS:
// none
// RETURN VALUE:
// returns the complex conjugate of the calling complex 
// object
//======================================================
Complex	  Complex::operator~	( void ) const
{
	Complex ret; 
	ret.real = real; 
	ret.imag = -1*imag; 
	return ret; 
}

//======================================================
// operator-
// -c
// PARAMETERS:
// none
// RETURN VALUE:
// returns the negative of the calling complex object c 
//======================================================
Complex	  Complex::operator-	( void ) const
{
	Complex ret; 
	ret.real = -1*real; 
	ret.imag = -1*imag; 
	return ret; 
}

//======================================================
// operator^
// c^k
// PARAMETERS:
// integer k 
// RETURN VALUE:
// returns result of raising *this to the kth power 
//======================================================
Complex   Complex::operator^	( int k ) const
{
 	Complex ret; 
	ret.real = real; 
	ret.imag = imag; 
	if (k==0) 
	{
		ret.real = 1; 
		ret.imag = 0; 
	}
	
	else if (k<0)
	{
		k = -1*k;
		for (int i=1; i<k; i++)
		{	
			ret = ret * ret; 
		}
		Complex num; 
		num.real = 1; num.imag = 0; 
		ret = num/ret;  	
	}

	else if (k>0)
	{
		for (int i=1; i<k; i++)
		{	
			ret = ret * ret; 
		}
	}
	return ret; 
}

//======================================================
// abs
// Returns the distance from the origin 
// PARAMETERS: none
// RETURN: distance from origin as a float 
//======================================================
float		Complex::abs	( void ) const
{
	float distance; 
	distance = sqrt(pow(real,2) + pow(imag,2)); 
	return distance; 
}

//======================================================
// setReal
// Sets the real component of a complex number 
// PARAMETERS: a - a float value for the real component
// RETURN: none
//======================================================
void		Complex::setReal ( float a )
{
	real = a; 
}


//======================================================
// getReal
// Returns the real component of a complex number 
// PARAMETERS: none
// RETURN: the real component of the complex number 
//======================================================
float		Complex::getReal ( void ) const
{
	return real; 
}

//======================================================
// setImag
// Sets the imaginary component of a complex number 
// PARAMETERS: b - a float value for the imaginary component
// RETURN: none
//======================================================
void		Complex::setImag ( float b )
{
	imag = b; 
}

//======================================================
// getImag
// Returns the imaginary component of a complex number 
// PARAMETERS: none
// RETURN: the imaginary component of the complex number 
//======================================================
float		Complex::getImag ( void ) const
{
	return imag; 
}


//======================================================
// operator==
// Returns true if both real and imaginary components are the same.
// PARAMETERS:
// const reference to Complex c 
// RETURN VALUE:
// true if c and *this have same real and imag, false otherwise.
//======================================================
bool	Complex::operator==	( const Complex &c ) const
{
	return (real==c.real && imag == c.imag); 
}


//======================================================
// operator!=
// Returns false if both real and imaginary are the same.
// PARAMETERS:
// const reference to Complex c 
// RETURN VALUE:
// false if c and *this have same real and imag, true otherwise.
//======================================================
bool	Complex::operator!=	( const Complex &c ) const
{
	return !(real==c.real && imag == c.imag); 
}

//======================================================
// operator<
// Returns true of caller < parameter.
// PARAMETERS:
// const reference to Complex c 
// RETURN VALUE:
// Note that two values (*this and c) must be converted to
// abs values first.  Then return true if *this < c, otherwise
// return false. 
//======================================================
bool	Complex::operator<	( const Complex &c ) const
{
	float abs1,abs2;  
	abs1 = sqrt(pow(real,2) + pow(imag,2)); 
	abs2 = sqrt(pow(c.real,2) + pow(c.imag,2)); 
	return (abs1<abs2); 
}

//======================================================
// operator<=
// Returns true of caller <= parameter.
// PARAMETERS:
// const reference to Complex c 
// RETURN VALUE:
// Note that two values (*this and c) must be converted to
// abs values first.  Then return true if *this <= c, otherwise
// return false. 
//======================================================
bool	Complex::operator<=	( const Complex &c ) const
{
	float abs1,abs2;  
	abs1 = sqrt(pow(real,2) + pow(imag,2)); 
	abs2 = sqrt(pow(c.real,2) + pow(c.imag,2)); 
	return (abs1<=abs2); 
}

//======================================================
// operator>
// Returns true of caller > parameter.
// PARAMETERS:
// const reference to Complex c 
// RETURN VALUE:
// Note that two values (*this and c) must be converted to
// abs values first.  Then return true if *this > c, otherwise
// return false. 
//======================================================
bool	Complex::operator>	( const Complex &c ) const
{
	float abs1,abs2;  
	abs1 = sqrt(pow(real,2) + pow(imag,2)); 
	abs2 = sqrt(pow(c.real,2) + pow(c.imag,2)); 
	return (abs1>abs2); 
}

//======================================================
// operator>=
// Returns true of caller >= parameter.
// PARAMETERS:
// const reference to Complex c 
// RETURN VALUE:
// Note that two values (*this and c) must be converted to
// abs values first.  Then return true if *this >= c, otherwise
// return false. 
//======================================================
bool	Complex::operator>=	( const Complex &c ) const
{
	float abs1,abs2; 
	abs1 = sqrt(pow(real,2) + pow(imag,2)); 
	abs2 = sqrt(pow(c.real,2) + pow(c.imag,2)); 
	return (abs1>=abs2); 
} 

//=================================================
// to_string
// PARAMETERS:
// none
// RETURN VALUE:
// a string containing "a+bi" where a and b are 
// the real and complex parts of the number.  Both
// a and b will be with fixed decimal length up to 
// two places.  
//=================================================

string 	Complex::to_string ( void ) const
{
	stringstream stream; 
	stream << fixed << setprecision(3) << real;
	if ( imag >= 0 )
		stream << "+" << fixed << setprecision(3) << imag << "i";
	else
		stream << "-" << fixed << setprecision(3) << fabs(imag) << "i";
	
	return stream.str();
}

//======================================================
// cout << operator overload
// PARAMETERS:
// ostream os
// const reference to Complex c 
// A string is created with value "a+bi" from c and then
// this string is inserted into the stream os.
// RETURN VALUE:
// ostream os
// NOTES:
// if real and imag are not 0, then we print "a+bi". Note
// that  if imag is negative, we print "a-bi" instead of 
// "a+ -bi"
// if real is 0 and imag is positive, we print "bi"
// if real is positive and imag is 0, we print "a"
// if both real and imag are 0, we simply print "0"
//======================================================
ostream & operator<< ( ostream &os, Complex c ) 
{
 	if ( c.real == 0 && c.imag==0 )
 		os << "0";
	else if (c.real != 0 && c.imag == 0)   os << fixed << setprecision(3) << c.real; 
	else if (c.real == 0 && c.imag != 0)   os << fixed << setprecision(3) << c.imag << "i"; 
	else if ( c.imag !=0 && c.real != 0 )
 	{
		if (c.imag > 0)			os << fixed << setprecision(3) << c.real << "+" << fixed << setprecision(3) << c.imag << "i"; 
 		else if (c.imag < 0)	os << fixed << setprecision(3) << c.real << "" << fixed << setprecision(3) << c.imag << "i"; 
	}
	return os;
}

//======================================================
// cin >>
// Overloads the cin istream >> operator to allow
// cin >> c;
// PARAMETERS
// istream is
// reference to Complex c 
// RETURN VALUE:
// istream is
// NOTES:
// We scan is for a string of the form "a+bi", "a" or "bi".
// Supports reading: a+bi, a-bi, -a+bi, -a-bi
// Supports reading: a, -a, +a, bi, -bi, +bi
// a,b can be integers or reals with decimal points 
//======================================================
istream & operator>> ( istream &is, Complex &c )
{
	string s;
	is >> s;		//read in complex number as a string 

	//Reads in a+bi, -a+bi, +a, +bi
	int spot_plus = s.find('+');
	if(spot_plus != string::npos)
	{
		if(spot_plus == 0)
		{
			if(s[s.size()-1]=='i') 
			{
				string half1 = s.substr(1,s.size()-1);
				c.imag = stof(half1);
				c.real = 0; 
			}
			else 
			{
				string half1 = s.substr(1,s.size());
				c.real = stof(half1);
				c.imag = 0; 
			}
		}
		
		else 
		{
			string half1 = s.substr(0,spot_plus);
			string half2 = s.substr(spot_plus+1,s.size()-spot_plus-1);
			c.real = stof(half1);
			c.imag = stof(half2); 	
		}
	}
	
	//Reads in a-bi, -a-bi, a, -a, bi, -bi 
	else 
	{
		int spot_minus = s.rfind('-'); 
		if(spot_minus==string::npos) spot_minus = 0; 
		if(spot_minus==0)
		{
			if(s[s.size()-1]=='i')
			{
				string half1 = s.substr(0,s.size()-1);
				c.real = 0; 
				c.imag = stof(half1); 
			}
			else 
			{
				string half1 = s.substr(0,s.size());
				c.real = stof(half1); 
				c.imag = 0; 
			}
		}
		
		else 
		{
			string half1 = s.substr(0,spot_minus);
			string half2 = s.substr(spot_minus,s.size()-spot_minus-1);
			c.real = stof(half1); 
			c.imag = stof(half2); 
		}
	}
	return is;
}



