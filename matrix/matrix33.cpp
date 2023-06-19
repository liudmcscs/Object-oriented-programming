#include "matrix33.h"
#include "vector3.h"
#include<iostream>
#include <cmath>
using namespace std;
void matrix33::printMatrix() const
{
    cout <<x.x <<" "<< y.x <<" "<<z.x<<"\n"<<x.y<<" "<<y.y<<" "<<z.y<<"\n"<<x.z<<" "<<y.z<<" "<<z.z<<endl;
}

matrix33::matrix33(vector3 inX, vector3 inY, vector3 inZ)
{
    x=inX;
    y=inY;
    z=inZ;
}

matrix33::matrix33(const matrix33 &m)
{
    x=m.x;
    y=m.y;
    z=m.z;
}

vector3& matrix33::operator [] (unsigned int index)
{
    if (index==0)
    {
        return x;

    }
    else if(index==1)
    {
        return y;
    }
    else
    {
        return z;
    }
}
const vector3& matrix33::operator [] (unsigned int index) const
{
    if (index==0)
    {
        return x;

    }
    else if(index==1)
    {
        return y;

    }
    else
    {
        return z;
    }
}

 matrix33& matrix33::operator = (const matrix33 &m)
{
    x=m.x;
    y=m.y;
    z=m.z;
    return *this;
}


matrix33 matrix33::  invert()
{
    matrix33 m;
    float d = determinant();
    m[0][0]=(y.y*z.z-y.z*z.y)/d;
    m[0][1]=(z.y*x.z-x.y*z.z)/d;
    m[0][2]=(x.y*y.z-y.y*x.z)/d;
    m[1][0]=(z.x*y.z-y.x*z.z)/d;
    m[1][1]=(x.x*z.z-x.z*z.x)/d;
    m[1][2]=(y.x*x.z-x.x*y.z)/d;
    m[2][0]=(y.x*z.y-z.x*y.y)/d;
    m[2][1]=(z.x*x.y-x.x*z.y)/d;
    m[2][2]=(x.x*y.y-y.x*x.y)/d;
    return m;
}

matrix33 operator * (const matrix33 &m, const matrix33 &n)
{
    vector3 veca;
    vector3 vecb;
    vector3 vecc;
    veca.x=m.x.x*n.x.x+m.y.x*n.x.y+m.z.x*n.x.z;
    vecb.x=m.x.x*n.y.x+m.y.x*n.y.y+m.z.x*n.y.z;
    vecc.x=m.x.x*n.z.x+m.y.x*n.z.y+m.z.x*n.z.z;
    veca.y=m.x.y*n.x.x+m.y.y*n.x.y+m.z.y*n.x.z;
    vecb.y=m.x.y*n.y.x+m.y.y*n.y.y+m.z.y*n.y.z;
    vecc.y=m.x.y*n.z.x+m.y.y*n.z.y+m.z.y*n.z.z;
    veca.z=m.x.z*n.x.x+m.y.z*n.x.y+m.z.z*n.x.z;
    vecb.z=m.x.z*n.y.x+m.y.z*n.z.y+m.z.z*n.y.z;
    vecc.z=m.x.z*n.z.x+m.y.z*n.z.y+m.z.z*n.z.z;
    return matrix33(veca,vecb,vecc);
}

matrix33 operator * (const matrix33 &m, float f)
{
    return matrix33(m.x*f,m.y*f,m.z*f);
}

matrix33 operator * (float f, const matrix33 &m)
{
    return matrix33(m.x*f,m.y*f,m.z*f);
}

matrix33&matrix33::operator *= (float f)
{
    x=x*f;
    y=y*f;
    z=z*f;
    return *this;
}

matrix33 operator + (const matrix33 &m, const matrix33 &n)
{
    return matrix33(m.x+n.x,m.y+n.y,m.z+n.z);
}

bool operator != (const matrix33 &m, const matrix33 &n)
{
    if (m.x.x==n.x.x && m.x.y==n.x.y && m.x.z==n.x.z && m.y.x==n.y.x && m.y.y==n.y.y && m.y.z==n.y.z && m.z.x==n.z.x && m.z.y==n.z.y && m.z.z==n.z.z)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

float matrix33::determinant()
{
    return (x.x*y.y*z.z+x.y*y.z*z.x+y.x*z.y*x.z-z.x*y.y*x.z-z.y*y.z*x.x-y.x*x.y*z.z);
}

void matrix33::identity()
{
    x.x=1;
    x.y=0;
    x.z=0;
    y.x=0;
    y.y=1;
    y.z=0;
    z.x=0;
    z.y=0;
    z.z=1;
}
