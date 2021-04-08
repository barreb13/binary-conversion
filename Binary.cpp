//---------------------------------------------------------------------------
// Binary.cpp
// Author: Brent Barrese
// Function definitions
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

#include "Binary.h"
#include <cassert>


//---------------------- Default constructor  -------------------------------
// Default constructor for class Binary
// Preconditions:	Enough memory for object
// Postconditions:	Ptr points to an array of size 1. Ptr[0] has a value of false.
Binary::Binary() {
	sizeOfArray = 1;
	sign = true;
	ptr = new bool[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++) {
		ptr[i] = false;
	}
}


//------------------------- Constructor -------------------------------------
// Constructor for class Binary that takes an integer as a parameter
// Preconditions:	Enough memory for object
// Postconditions:	Ptr points to an array of size exactly big enough to hold binary
//					number. Sign variable is changed based on positive or negative number
Binary::Binary(int num) {
	// handle case where 0 is declared
	if (num == 0) {
		sizeOfArray = 1;
		sign = true;
		ptr = new bool[sizeOfArray];
		for (int i = 0; i < sizeOfArray; i++) {
			ptr[i] = false;
		}
	}
	// Number is something other than 0
	else {
		sizeOfArray = 0;
		num < 0 ? sign = false : sign = true;
		int temp = abs(num);
		int positiveNum = abs(num);

		while (temp >= 1) {
			sizeOfArray++;
			temp = temp / 2;
		}

		ptr = new bool[sizeOfArray];

		int remainder;
		for (int i = 0; i < sizeOfArray; i++) {
			remainder = positiveNum % 2;
			remainder == 1 ? ptr[i] = true : ptr[i] = false;
			positiveNum /= 2;
		}
	}
}


//----------------------- Copy constructor  ----------------------------------
// Copy constructor for class Binary
// Preconditions:	fromBinary.ptr points to an array with a valid sizeOfArray variable.
//					fromBinary sign is correct.
// Postconditions:	fromBinary is copied into *this.
Binary::Binary(const Binary& fromBinary) {
	// build array for this to match fromBinary
	sizeOfArray = fromBinary.sizeOfArray;
	ptr = new bool[sizeOfArray];
	this->sign = fromBinary.sign;

	//Start going through array and copying
	for (int i = 0; i < sizeOfArray; i++) {
		ptr[i] = fromBinary.ptr[i];
	}
}


//-------------------------- Destructor -------------------------------------
// Destructor for class Binary
// Preconditions:	ptr is valid and points to an array that was dynamically allocated
// Postconditions:	Dynamically allocated array is deallocated. Memory is freed.
Binary::~Binary() {
	delete[] ptr;
}


//-----------------------------  +  -----------------------------------------
// Adds 2 binary objects
// Preconditions:	rightBinary is a valid object
// Postconditions:	temp is created and is returned to calling object
Binary Binary::operator+(const Binary& rightBinary) const {
	Binary temp(this->binaryToInteger() + rightBinary.binaryToInteger());
	return temp;
}


//-----------------------------  -  -----------------------------------------
// Subtracts 2 binary objects
// Preconditions:	rightBinary is a valid object
// Postconditions:	temp is created and is returned to calling object
Binary Binary::operator-(const Binary& rightBinary) const {
	Binary temp(this->binaryToInteger() - rightBinary.binaryToInteger());
	return temp;
}


//-----------------------------  =  -----------------------------------------
// Overloaded assignment operator to assign binary objects
// Preconditions:	fromBinary is a valid object. fromBinary.ptr points to an array.
// Postconditions:	new array is created that matches fromBinary and *this
//					is assigned to it.
Binary& Binary::operator=(const Binary& fromBinary) {
	if (&fromBinary != this) {							// If they are not the same address
		delete[] ptr;									// Delete this array
		sizeOfArray = fromBinary.sizeOfArray;			// Make array share the same size
		if (sizeOfArray == 0) {							// Handle case of 0
			sizeOfArray = 1;
			this->sign = true;
			ptr = new bool[sizeOfArray];
			for (int i = 0; i < sizeOfArray; i++) {
				ptr[i] = false;
			}
		}
		else {
			this->sign = fromBinary.sign;
			ptr = new bool[sizeOfArray];				// Create new array

			for (int i = 0; i < sizeOfArray; i++) {		// Walk through array and copy
				ptr[i] = fromBinary.ptr[i];
			}
		}
	}
	return *this;
}


//-----------------------------  +=  -----------------------------------------
// Adds to the current binary object
// Preconditions:	rightBinary is a valid object. *this points to a valid binary
//					object. 
// Postconditions:	*this is modified. *this has the value of rightBinary added
//					to it.
Binary& Binary::operator+=(const Binary& rightBinary) {
	Binary temp(this->binaryToInteger() + rightBinary.binaryToInteger());
	*this = temp;
	return *this;
}


//-----------------------------  -=  -----------------------------------------
// Subtracts from the current binary object
// Preconditions:	rightBinary is a valid object. *this points to a valid binary
//					object.
// Postconditions:	*this is modified. *this has the value of rightBinary sutracted
//					from it.
Binary& Binary::operator-=(const Binary& rightBinary)
{
	Binary temp(this->binaryToInteger() - rightBinary.binaryToInteger());
	*this = temp;
	return *this;
}


//-----------------------------  ==  -----------------------------------------
// Checks for equality between 2 binary objects
// Preconditions:	*this and binary are valid binary objects. 
// Postconditions:	bool value is returned and can be true or false depending
//					on condition found. True is returned if both objects = 0
//					or if objects = same binary number and signs are the same 
//					value. Returns false otherwise (binary numbers are not
//					the same).
bool Binary::operator==(const Binary& binary) const {
	bool result = true;
	// Handle case of -0 and +0
	if (this->checkIfZero() && binary.checkIfZero()) {
		return true;
	}
	// Handle case of different signs
	else if (binary.sign != this->sign) {
			return false;
		}
	// Can assume signs are the same, so compare binaries
	else {
		// Create bypass ints to bypass leading 0s in toggle cases
		int thisBypass = this->sizeOfArray - 1;
		while (this->ptr[thisBypass] == 0 && thisBypass > 0) {
			thisBypass--;
		}
		int binaryBypass = binary.sizeOfArray - 1;
		while (binary.ptr[binaryBypass] == 0 && binaryBypass > 0) {
			binaryBypass--;
		}
		// if bypass variables != then significant digit is in different place
		if (thisBypass != binaryBypass) {
			return false;
		}
		// significant digit is at the same spot, so start comparing values
		int i = 0;
		while (i < thisBypass && i < binaryBypass) {
			if (ptr[i] != binary.ptr[i]) {
				return false;
			}
			i++;
		}		
	}
	return result;
}


//-----------------------------  !=  -----------------------------------------
// Checks for non-equality between 2 binary objects
// Preconditions:	*this and binary are valid binary objects.
// Postconditions:	bool value is returned. Returns false if *this and binary
//					are the same. Returns true otherwise.
bool Binary::operator!=(const Binary& binary) const {
	return !(*this == binary);
}


//----------------------------  getBit  -----------------------------------------
// Gets the bit value at a specific value in a binary object
// Preconditions:	num is a valid integer >= 0. Calling object is a valid binary
//					object.
// Postconditions:	bool value is returned. If num is valid, bool value returned
//					is the value at ptr[num] in array.
bool Binary::getBit(int num) const {
	if (num >= 0 && num < sizeOfArray) {
		return ptr[num];
	}
	return false;
}


//----------------------------  setBit  -----------------------------------------
// Sets a bit (turns to true) at a specific value in a binary object
// Preconditions:	num is a valid integer >= 0. Calling object is a valid binary 
//					object
// Postconditions:	No value is returned. array value at index of num is changed
//					to true.
void Binary::setBit(int num) {
	if (num >= 0 && num < sizeOfArray) {
		ptr[num] = true;
		return;
	}
}


//----------------------------  clearBit  --------------------------------------
// Clears a bit (turns to false) at a specific value in a binary object
// Preconditions:	num is a valid integer >= 0. Calling object is a valid binary 
//					object
// Postconditions:	No value is returned. array value at index of num is changed
//					to false.
void Binary::clearBit(int num) {
	if (num >= 0 && num < sizeOfArray) {
		ptr[num] = false;
		return;
	}
}


//----------------------------  toggleBit  ---------------------------------------
// Toggles a bit (turns the opposite value of current value) at a specific value
// in a binary object
// Preconditions:	num is a valid integer >= 0. Calling object is a valid binary 
//					object
// Postconditions:	No value is returned. Array value at index of num is "toggled".
//					If current value is false, the value is changed to true. If 
//					current value is true, the value is change to false.
void Binary::toggleBit(int num) {
	if (num >= 0 && num < sizeOfArray) {
		if (ptr[num] == true) {
			ptr[num] = false;
		}
		else {
			//Assume ptr must have been false
			ptr[num] = true;
		}
		return;
	}
}


//----------------------------  binaryToInteger  ----------------------------------
// Converts a binary number to an integer decimal number
// Preconditions:	Calling object is valid binary object. *this points to a valid
//					array.
// Postconditions:	Integer is returned. The value of the binary is converted to 
//					integer / decimal and returned. Object is not changed.
int Binary::binaryToInteger() const {
	// Initialize base to 1 
	int base = 1;
	int returnNum = 0;
	int start = 1;

	for (int i = 0; i < sizeOfArray; i++) {
		if (ptr[i] == true) {
			returnNum += start * base;
		}
		//Update base like a power of 2
		base = base * 2;			
	}
	// Handle negative number
	if (sign == false) {
		return -returnNum;
	}
	return returnNum;
}


//----------------------------  checkIfZero  ----------------------------------
// Checks if the current binary is equal to zero
// Preconditions:	ptr points to a valid Binary object array. Calling object is
//					valid.
// Postconditions:	bool value is returned. True is returned if binary object is 
//					checked and equals 0. False is returned otherwise.
bool Binary::checkIfZero() const {
	bool returnValue = true;
	// Exit as soon as something is true which means != 0
	for (int i = 0; i < sizeOfArray; i++) {
		if (ptr[i] == true) {
			return false;
		}
	}
	return returnValue;
}


//----------------------------  <<  -----------------------------------------
// Overloaded output operator for class Binary
// Preconditions:	Binary object is valid. *this points to valid array.
// Postconditions:	The array that *this points to is read starting from the 
//					last index in order to replicate binary number. Greatest
//					significant digit is read first. All values are sent
//					to ostream.
ostream& operator<<(ostream& outStream, const Binary& binary)
{
	if (binary.sign == false) {
		outStream << "-";
	}

	//Create bypass variable to skip any leading 0 in array
	if (binary.sizeOfArray > 1) {
		int bypass = binary.sizeOfArray - 1;
		while (binary.ptr[bypass] == 0 && bypass > 0) {	
			bypass--;
		}

		for (int i = bypass; i >= 0; i--) {
			outStream << binary.ptr[i];
		}
	}
	else {
		for (int i = binary.sizeOfArray - 1; i >= 0; i--) {
			outStream << binary.ptr[i];
		}
	}
	return outStream;
}


//----------------------------  >>  -----------------------------------------
// Overloaded input operator for class Binary
// Takes integer given by operator and creates binary object
// Preconditions:	Calling object must be valid binary object. Must be an 
//					integer that is being sent to istream.
// Postconditions:	Local variable num is populated with integer from istream.
//					binary is changed to be the binary value of the integer value
//					that was input into istream.
istream& operator>>(istream& inStream, Binary& binary)
{
	int num;
	inStream >> num;
	Binary temp(num);
	binary = temp;
	return inStream;
}
