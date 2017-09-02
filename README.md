# mVector
A C++ library for implementing Vectors and Matrices.

## What is this for?
mVector (math Vector) aims to implement vectors and matrices to C++ source code in a way that is simple for the programmer to understand and modify.

## What can I do with mVector?
There are a few functions built into the library. (These are WIP and not all of them are available yet, sorry!) 

## Functions

### mVector (aka. the Constructor)
Initializes the vector `vectorDimensions`. Note that if any input but the first is not of type double, the behavior is undefined.    
Syntax:
```cpp
mVector vect(<count of args>, <arg1>, <arg2>, <arg3>, ..., <argN>); 
```
Example:
```cpp
mVector vect(3, 45.5, 23.232, 12.2);
```
This function produces no output.

---

### giveDimensions
returns the dimensions of the given vector. Takes no arguments. (return type is `std::string`.)  

Syntax:
```cpp
vect.giveDimensions();
```
Example:
```cpp
mVector vect(2, 1.0, 2.0);
std::cout << vect.giveDimensions();
```
Output: `1, 2`

---

### addVector
addVector is a function in the library that adds two vectors together. Note that it only works with vectors of equal dimensions/size. (return type is `mVector::mVector`.)

Syntax:
```cpp
vect.addVector(vect2);
```

Example:
```cpp
mVector vect1(2, 1.0, 2.0);
mVector vect2(2, 15.0, 21.0);
mVector vect3 = vect1.addVector(vect2);

std::cout << vect3.giveDimensions() << std::endl;
```
Output: `16, 23`
