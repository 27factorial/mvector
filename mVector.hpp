// STD::VECTOR AND MVECTOR ARE DIFFERENT THINGS!
//mVector is used for mathematical vectors. (Think linear algebra / calculus.)
//std::vector is (basically) an array that can be variable in size.

#include "stdafx.h" // VS
#include <cstdarg>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>


class mVector {
private:

	std::vector <double> vectorDimensions; // Using std::vector for making mathematical vectors?!?!? It allows us to make a vector of infnite dimensions. Why? Because I can.

public:
	mVector(int, ...);

	~mVector();

	std::string giveDimensions();
};


mVector::mVector(int num, ...) { // Using va_list with std::vector, we can add a vector of infnite dimensions.
	std::va_list args;

	va_start(args, num);
	for (int x = 0; x < num; x++) {
		vectorDimensions.insert(vectorDimensions.end(), va_arg(args, double)); // How axes work: x = index 0, y = index 1, z = index 2, etc.
	}
	va_end(args);

}


mVector::~mVector() {
	// the compiler will make a destructor.
	// If you're porting this, this is just a C++ idiom. You don't need to add this most likely.
}


std::string mVector::giveDimensions() { //Messy code. I'll try to fix this up when I get a chance.
	std::stringstream output;
	for (int item = 0; item < vectorDimensions.size(); item++) {
		if (item == vectorDimensions.size() - 1) {
			output << vectorDimensions.at(item);
		}
		else {
			output << vectorDimensions.at(item) << ", ";
		}
	}
	return "[" + output.str() + "]";
}

/********************************************
* TODO:
/ Make mVector scalable to 3 dimensions. (Scales to infinite dimensions.)
* Add mathematical functions for vectors.   
* Add Matrices.
* Add math for Matrices.
* Cross compatibility.
* Get rid of the todo list.
*********************************************/
