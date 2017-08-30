// I've literally just started this library, don't judge me too hard.
#include "stdafx.h"
#include <iostream>
#include <string>

class mVector { // Vector is already taken by std::vector, so I used mVector for "math Vector".
private: // Variables set by the constructor
	double vectorX;
	double vectorY;
public:
	mVector(double, double);

	~mVector();

	double giveX() {
		return vectorX;
	}

	double giveY() {
		return vectorY;
	}
};

mVector::mVector(double x = 0, double y = 0) {
	vectorX = x;
	vectorY = y;
}

mVector::~mVector() {
}

/********************************************
* TODO:					    *
* Make mVector scalable to 3 dimensions.    *
* Add mathematical functions for vectors.   *
* Add Matrices.                             *
* Add math for Matrices.                    *
* Cross compatibility.			    *
* Get rid of the todo list.                 *
*********************************************/
