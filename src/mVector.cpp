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

	std::string getDimensions();

	mVector add(mVector); // Adding vectors to vectors

	mVector add(double); // Adding scalars to vectors

	double dotProd(mVector vect);
};


mVector::mVector(int argc, ...) { // Using va_list with std::vector, we can add a vector of infinite dimensions.
	std::va_list args;

	va_start(args, argc);
	for (int x = 0; x < argc; x++) {
		vectorDimensions.insert(vectorDimensions.end(), va_arg(args, double)); // How axes work: x = index 0, y = index 1, z = index 2, etc.
	}
	va_end(args);

}


mVector::~mVector() {
	// the compiler will make a destructor.
}


std::string mVector::getDimensions() { //Messy code. I'll try to fix this up when I get a chance.
	std::stringstream output;
	for (unsigned i = 0; i < vectorDimensions.size(); i++) {
		if (i == vectorDimensions.size() - 1) {
			output << vectorDimensions.at(i);
		}
		else {
			output << vectorDimensions.at(i) << ", ";
		}
	}
	return output.str();
}

mVector mVector::add(mVector vect) {
	if (this->vectorDimensions.size() != vect.vectorDimensions.size()) {
		std::string error = "mVectorSizeException";
		std::cerr << "Error! " << error << std::endl;
		throw error; // PLEASE don't forget to catch this exception, just put this in a try block.
		exit(-1);
	}
	else {
		for (unsigned i = 0; i < this->vectorDimensions.size(); i++) {
			this->vectorDimensions.at(i) += vect.vectorDimensions.at(i);
		}
	}
	return *this;
}

mVector mVector::add(double x) {
	for (unsigned i = 0; i < this->vectorDimensions.size(); i++) {
		this->vectorDimensions.at(i) += x;
	}
	return *this;
}

double mVector::dotProd(mVector vect) {
	if (this->vectorDimensions.size() != vect.vectorDimensions.size()) {
		std::string error = "mVectorSizeException";
		std::cerr << "Error! " << error << std::endl;
		throw error; //Again, please don't forget to catch this exception.
		exit(-2);
	}
	else {
		double num = 0;
		for (unsigned i = 0; i < this->vectorDimensions.size(); i++) {
			this->vectorDimensions.at(i) *= vect.vectorDimensions.at(i);
			num += this->vectorDimensions.at(i);
		}
		return num;
	}
}


int main() {
	mVector vect1(2, 1.0, 2.0);
	mVector vect2(2, 1.0, 2.0);
	double num = vect1.dotProd(vect2);
	std::cout << num << std::endl;
}

/* Will be completely rewriting this for the following reasons:
 * 1. The code is sloppy and not well written. I want to improve on this.
 * 2. My consistency is horrible; I want to work on making my commenting more helpful and consistent, as well as having self explanatory code.
 * 3. I can't even recall why I've done half of the things I've done. I wrote this when I was new.
 * 4. There are compiler warnings that I should have addressed long ago.
 * 5. I have nothing better to do.
 */
