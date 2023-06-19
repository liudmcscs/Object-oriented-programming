#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "vector3.h"

class matrix33
{
public:
	/* data members */
	vector3 x, y, z;

	//****************************************************//
	//  You need to implement the following functions !!  //
	//****************************************************//

public:
	/* constructors */
	// default constructor -- don't do anything with it
	matrix33() {};

	// constructor with initializing float values
	matrix33(vector3 inX, vector3 inY, vector3 inZ);

	// constructor with initializing vector3
	matrix33(const matrix33 &m);

public:
	/* Operators */

	// access element
	vector3                 &operator [] (unsigned int index);
	const vector3           &operator [] (unsigned int index) const;

	matrix33               &operator =  (const matrix33 &m);
	matrix33               &operator += (const matrix33 &m);
	matrix33               &operator -= (const matrix33 &m);
	matrix33               &operator *= (float f);
	matrix33               &operator /= (float f);
	friend bool           operator == (const matrix33 &m, const matrix33 &n);
	friend bool           operator != (const matrix33 &m, const matrix33 &n);
	friend matrix33        operator - (const matrix33 &m);
	friend matrix33        operator + (const matrix33 &m, const matrix33 &n);
	friend matrix33        operator - (const matrix33 &m, const matrix33 &n);
	friend matrix33        operator * (const matrix33 &m, float f);
	friend matrix33        operator * (float f, const matrix33 &m);
	friend matrix33        operator / (const matrix33 &m, float f);
	friend matrix33        operator * (const matrix33 &m, const matrix33 &n);

 public:
	/* Methods */

	// set values (e.g. x = xIn, ...)
    void set(vector3 xIn, vector3 yIn, vector3 zIn);

	// calculate length
    float length() const;

	// print matrix using std::cout
	void printMatrix() const;
	matrix33 invert();
	void identity();
	float determinant();
};
#endif
