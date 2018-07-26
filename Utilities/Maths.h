﻿#ifndef __MATHS__
#define __MATHS__


// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


// This is a header file for the mathematics utility functions
// The prototypes of any inlined functions must be placed here

#include <stdlib.h>

#include "Constants.h"
#include "RGBColor.h"
#include "Utilities/Vector3D.h"


// prototypes

double
min(double x0, double x1);

double
max(double x0, double x1);

//int
//rand_int(void);

//double
//rand_double(void);

//void
//set_rand_seed(const int seed);

//double 						// for multi-jittered sampling
//rand_double(int l, double h);

//int							// for multi-jittered sampling
//rand_int(int l, int h);

double
clamp(const double x, const double min, const double max);

int
SolveQuadric(double c[3], double s[2]);

int 
SolveCubic(double c[4], double s[3]);

int 
SolveQuartic(double c[5], double s[4]);



// inlined functions

// ----------------------------------------------------------------- min

inline double
min(double x0, double x1) {
	return ((x0 < x1) ? x0 : x1);
}


// ----------------------------------------------------------------- max

inline double
max(double x0, double x1) {
	return ((x0 > x1) ? x0 : x1);
}


//// ---------------------------------------------------- rand_int
//// a wrapper for rand()

//inline int
//rand_int(void) {
//	return(rand());
//}


//// ---------------------------------------------------- rand_double

//inline double
//rand_double(void) {
//    return((double)rand_int() * invRAND_MAX);
//}


//// ---------------------------------------------------- set_rand_seed

//inline void
//set_rand_seed(const int seed) {
//	srand(seed);
//}


//// The following two functions are only for multi-jittered sampling
//// I had trouble getting them to compile in the MultiJittered class
//// The overloading confused my compiler

//// ---------------------------------------------------- rand_double with arguments

//inline double
//rand_double(int l, double h) {
//    return (rand_double() * (h - l) + l);
//}

//// ---------------------------------------------------- rand_int with arguments

//inline int
//rand_int(int l, int h) {
//    return ((int) (rand_double(0, h - l + 1) + l));
//}


// ---------------------------------------------------- clamp

inline double
clamp(const double x, const double min, const double max) {
	return (x < min ? min : (x > max ? max : x));
}

inline Vector3D cross (const Vector3D& v1,const Vector3D& v2){
    return Vector3D(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}
#endif
