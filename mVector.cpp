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

	mVector add(mVector); // Adding vectors to vectors

	mVector add(double); // Adding scalars to vectors
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


std::string mVector::giveDimensions() { //Messy code. I'll try to fix this up when I get a chance.
	std::stringstream output;
	for (unsigned item = 0; item < vectorDimensions.size(); item++) {
		if (item == vectorDimensions.size() - 1) {
			output << vectorDimensions.at(item);
		}
		else {
			output << vectorDimensions.at(item) << ", ";
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


int main() {
	mVector vect1(2, 1.0, 2.0);
	mVector vect2(2, 1.0, 2.0);
	vect2 = vect1.add(vect2);
	std::cout << vect2.giveDimensions() << std::endl;
	vect2 = vect2.add(1);
	std::cout << vect2.giveDimensions() << std::endl;
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

/* Reference code.

mVector mVector::addVector(mVector vect) {
	if (vect.vectorDimensions.size() > this->vectorDimensions.size() || vect.vectorDimensions.size() < this->vectorDimensions.size()) { // LOL WHY
		std::string error = "mVectorSizeException";
		std::cerr << "Error! " << error << std::endl;
		throw error; // PLEASE don't forget to catch this exception, just put this in a try block.
		exit(-1);
	}
	else {
		for (int i = 0; i < vect.vectorDimensions.size(); i++) {
			vect.vectorDimensions.at(i) += this->vectorDimensions.at(i);
		}
	return vect;
	}
}

mVector mVector::addScalar(mVector vect, double x) {
	for (int i = 0; i < vect.vectorDimensions.size(); i++) {
		vect.vectorDimensions.at(i) += x;
	}
return vect;
}
*/