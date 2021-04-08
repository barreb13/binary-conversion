//---------------------------------------------------------------------------
// Binary.h
// Author: Brent Barrese
// Class declarations
//---------------------------------------------------------------------------
// Binary class:Takes an integer and converts to binary using dynamic
//				array or bool values
//   -- allows copying binary objects
//   -- allows assignment of binary object
//   -- allows addition and subtraction
//   -- allows for comparison of binary objects
//   -- allows setbit to turn specific bits true
//   -- allows clearbit to turn specific bits false
//   -- allows togglebit to flip specific bits to the opposite value
//   -- allows printing of binary in correct order
//
// Assumptions:
//   -- default constructor sets binary number to 0
//   -- user must enter valid integers when using >>
//   -- in <<, binary number is printed in correct order
//   -- integer made will not exceed INT_MIN or INT_MAX
//---------------------------------------------------------------------------

#pragma once
#include <iostream>

using namespace std;

class Binary {
	//----------------------------  <<  -----------------------------------------
	// Overloaded output operator for class Binary
	// Preconditions:	Binary object is valid. *this points to valid array.
	// Postconditions:	The array that *this points to is read starting from the 
	//					last index in order to replicate binary number. Greatest
	//					significant digit is read first. All values are sent
	//					to ostream.
	friend ostream& operator <<(ostream& outStream, const Binary& binary);

	//----------------------------  >>  -----------------------------------------
	// Overloaded input operator for class Binary
	// Takes integer given by operator and creates binary object
	// Preconditions:	Calling object must be valid binary object. Must be an 
	//					integer that is being sent to istream.
	// Postconditions:	Local variable num is populated with integer from istream.
	//					binary is changed to be the binary value of the integer value
	//					that was input into istream.
	friend istream& operator >>(istream& inStream, Binary& binary);

public:
	//---------------------- Default constructor  -------------------------------
	// Default constructor for class Binary
	// Preconditions:	Enough memory for object
	// Postconditions:	Ptr points to an array of size 1. Ptr[0] has a value of false.
	Binary();

	//------------------------- Constructor -------------------------------------
	// Constructor for class Binary that takes an integer as a parameter
	// Preconditions:	Enough memory for object
	// Postconditions:	Ptr points to an array of size exactly big enough to hold binary
	//					number. Sign variable is changed based on positive or negative number
	Binary(int num);

	//----------------------- Copy constructor  ----------------------------------
	// Copy constructor for class Binary
	// Preconditions:	fromBinary.ptr points to an array with a valid sizeOfArray variable.
	//					fromBinary sign is correct.
	// Postconditions:	fromBinary is copied into *this.
	Binary(const Binary& fromBinary);

	//-------------------------- Destructor -------------------------------------
	// Destructor for class Binary
	// Preconditions:	ptr is valid and points to an array that was dynamically allocated
	// Postconditions:	Dynamically allocated array is deallocated. Memory is freed.
	~Binary();

	//-----------------------------  +  -----------------------------------------
	// Adds 2 binary objects
	// Preconditions:	rightBinary is a valid object
	// Postconditions:	temp is created and is returned to calling object
	Binary operator+(const Binary& rightBinary) const;

	//-----------------------------  -  -----------------------------------------
	// Subtracts 2 binary objects
	// Preconditions:	rightBinary is a valid object
	// Postconditions:	temp is created and is returned to calling object
	Binary operator-(const Binary& rightBinary) const;

	//-----------------------------  =  -----------------------------------------
	// Overloaded assignment operator to assign binary objects
	// Preconditions:	fromBinary is a valid object. fromBinary.ptr points to an array.
	// Postconditions:	new array is created that matches fromBinary and *this
	//					is assigned to it.
	Binary& operator=(const Binary& fromBinary);

	//-----------------------------  +=  -----------------------------------------
	// Adds to the current binary object
	// Preconditions:	rightBinary is a valid object. *this points to a valid binary
	//					object. 
	// Postconditions:	*this is modified. *this has the value of rightBinary added
	//					to it.
	Binary& operator+=(const Binary& rightBinary);

	//-----------------------------  -=  -----------------------------------------
	// Subtracts from the current binary object
	// Preconditions:	rightBinary is a valid object. *this points to a valid binary
	//					object.
	// Postconditions:	*this is modified. *this has the value of rightBinary sutracted
	//					from it.
	Binary& operator-=(const Binary& rightBinary);

	//-----------------------------  ==  -----------------------------------------
	// Checks for equality between 2 binary objects
	// Preconditions:	*this and binary are valid binary objects. 
	// Postconditions:	bool value is returned and can be true or false depending
	//					on condition found. True is returned if both objects = 0
	//					or if objects = same binary number and signs are the same 
	//					value. Returns false otherwise (binary numbers are not
	//					the same).
	bool operator==(const Binary& binary) const;

	//-----------------------------  !=  -----------------------------------------
	// Checks for non-equality between 2 binary objects
	// Preconditions:	*this and binary are valid binary objects.
	// Postconditions:	bool value is returned. Returns false if *this and binary
	//					are the same. Returns true otherwise.
	bool operator!=(const Binary& binary) const;


	//----------------------------  getBit  -----------------------------------------
	// Gets the bit value at a specific value in a binary object
	// Preconditions:	num is a valid integer >= 0. Calling object is a valid binary
	//					object.
	// Postconditions:	bool value is returned. If num is valid, bool value returned
	//					is the value at ptr[num] in array.
	bool getBit(int num) const;

	//----------------------------  setBit  -----------------------------------------
	// Sets a bit (turns to true) at a specific value in a binary object
	// Preconditions:	num is a valid integer >= 0. Calling object is a valid binary 
	//					object
	// Postconditions:	No value is returned. array value at index of num is changed
	//					to true.
	void setBit(int num);

	//----------------------------  clearBit  -----------------------------------------
	// Clears a bit (turns to false) at a specific value in a binary object
	// Preconditions:	num is a valid integer >= 0. Calling object is a valid binary 
	//					object
	// Postconditions:	No value is returned. array value at index of num is changed
	//					to false.
	void clearBit(int num);

	//----------------------------  toggleBit  -----------------------------------------
	// Toggles a bit (turns the opposite value of current value) at a specific value
	// in a binary object
	// Preconditions:	num is a valid integer >= 0. Calling object is a valid binary 
	//					object
	// Postconditions:	No value is returned. Array value at index of num is "toggled".
	//					If current value is false, the value is changed to true. If 
	//					current value is true, the value is change to false.
	void toggleBit(int num);

	//----------------------------  binaryToInteger  ------------------------------------
	// Converts a binary number to an integer decimal number
	// Preconditions:	Calling object is valid binary object. *this points to a valid
	//					array.
	// Postconditions:	Integer is returned. The value of the binary is converted to 
	//					integer / decimal and returned. Object is not changed.
	int binaryToInteger() const;


	// Checks if the current binary is equal to zero
	// Preconditions:	ptr points to a valid Binary object array. Calling object is
	//					valid.
	// Postconditions:	bool value is returned. True is returned if binary object is 
	//					checked and equals 0. False is returned otherwise.
	bool checkIfZero() const;

private:
	int sizeOfArray;		// Size of array
	bool* ptr;				// pointer to first element of array
	bool sign;				// sign of number	
};
