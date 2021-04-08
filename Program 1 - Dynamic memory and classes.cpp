// Brent B
// Program 1 - Dynamic memory and classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Binary.h"

using namespace std;

int main()
{
	Binary brent(1);
	Binary brent1(1);
	cout << "brent: " << brent << endl;
	cout << "brent1: " << brent1 << endl;
	bool test = (brent != brent1);
	cout << "bool test: " << test << endl;
	brent += brent1;
	cout << "brent += brent1 " << endl;
	cout << "brent: " << brent << endl;
	cout << "brent1: " << brent1 << endl;
	test = (brent == brent1);
	cout << "bool test: " << test << endl;
	//brent1.clearBit(3);
	//brent1.clearBit(3);
	//brent1.clearBit(2);
	//cout << "brent: " << brent << endl;
	//cout << "brent1: " << brent1 << endl;
	//test = (brent == brent1);
	//cout << "bool test: " << test << endl;
	//// Testing default constructor
	//Binary brentDefault;
	//cout << "Creating brentDefault..." << endl;
	//cout << "Printing brentDefault..." << endl;
	//cout << brentDefault << endl;

	//// Testing constructor
	//Binary brent(3);
	//cout << "\nPrinting 3 in binary..." << endl;
	//cout << brent << endl;

	//// Testing copy constructor
	//cout << "\nTesting Copy Constructor..." << endl;
	//Binary copy(brent);
	//cout << "Printing copy..." << endl;
	//cout << copy << endl;

	//Binary brent2(19);
	//cout << "\nPrinting 19 in binary..." << endl;
	//cout << brent2 << endl;

	////Testing = operator
	//cout << "\nCreating brent3...";
	//Binary brent3 = brent - brent2;
	//cout << "\nSubtracting brent(3) - brent2(19)...";
	//cout << "\nPrinting brent3(-16) in binary..." << endl;
	//cout << brent3 << endl;

	////Testing +=
	//cout << endl << "BEFORE brent3 += brent: " << endl;
	//cout << "brent 3 (should be -16): " << brent3 << endl;
	//cout << "brent (should be 3): " << brent << endl;
	//brent3 += brent;
	//cout << endl << "AFTER brent3(-16) += brent(3): " << endl;
	//cout << "brent 3 (should be -13): " << brent3 << endl;
	//cout << "brent (should be 3): " << brent << endl;

	////Testing -+
	//cout << "brent -= brent3 (3 -= -13)" << endl;
	//brent -= brent3;
	//cout << "brent (should be 16): " << brent << endl;

	////Testing getBit
	//cout << "\nTesting bit functions" << endl;
	//Binary bitFunctions(21);
	//cout << bitFunctions << endl; 
	//for (int i = 0; i < 5; i++) {
	//	bitFunctions.toggleBit(i);
	//}
	//cout << "\nAfter toggling..." << endl;
	//cout << bitFunctions << endl;

	//Binary ken(-15);
	//cout << "ken(-15): " << ken << endl;
	//ken.clearBit(0);
	//ken.clearBit(1);
	//ken.clearBit(2);
	//ken.clearBit(3);
	//cout << "After toggling... ken: " << ken << endl;
	//cout << endl;
	//Binary ken1(0);
	//cout << "ken: " << ken << endl;
	//cout << "ken1: " << ken1 << endl;
	//cout << "does ken == ken1?";
	//bool testy = (ken1 == ken);
	//if (testy == true) cout << " YES" << endl;
	//if (testy == false) cout << " NO" << endl;

	//Binary kenPos15(15);
	//Binary kenNeg15(-15);
	//cout << "kenPos15: " << kenPos15 << endl;
	//cout << "kenNeg15: " << kenNeg15 << endl;
	//cout << "does kenPos15 == kenNeg15?";
	//testy = (kenPos15 == kenNeg15);
	//if (testy == true) cout << " YES" << endl;
	//if (testy == false) cout << " NO" << endl << endl;

	//Binary dex(-1);
	//dex.toggleBit(0);
	//Binary dex0(0);
	//testy = (dex == dex0);
	//if (testy == true) {
	//	cout << "dex DOES = dex0";
	//}
	//if (testy == false) {
	//	cout << "dex does NOT = dex0";
	//}
	//cout << endl;

	//cout << "\nTesting 1111111: " << endl;
	//Binary test127(127);
	//cout << "test127 = " << test127 << endl;
	//test127.toggleBit(6);
	//test127.toggleBit(5);
	//test127.toggleBit(4);
	//test127.toggleBit(3);
	//test127.toggleBit(2);
	//test127.toggleBit(1);
	//cout << "\nAfter Toggling..." << endl;
	//cout << "test127 = " << test127 << endl;

	//---------------------------------Driver code from Assignment Instructions---------------------------------
	
	//Binary a, b(42), c(b), d = -13, x, y = x + 1;

	//cout << "Enter integer to be converted to binary:  ";
	//cin >> a;
	//cout << "The binary representation of this number is: " << endl;
	//cout << a << endl;
	//cout << "The 4th bit (four bits away from bit 0) is: " << endl;
	//cout << a.getBit(4) << endl << endl;

	//cout << "Compute c = a + b" << endl;
	//c = a + b;
	//cout << "c = " << c << endl;
	//cout << "Compute d = a + b - c" << endl;
	//d = a + b - c;
	//cout << "d = " << d << endl << endl;

	//cout << "Does a == c? " << endl;
	//cout << ((a == c) ? "a == c" : "a != c") << endl << endl;

	//cout << "Test assignment operators" << endl;
	//x = c = d = d;    y += a -= b += b;
	//cout << "x = " << x << "    y = " << y << endl << endl;

	//a.setBit(-1);			// handle bad input
	//a.setBit(3);			// set 3rd bit (three over from bit zero)
	//a.setBit(1000);			// set 1000th bit; handle as desired, but don't crash
	//a.clearBit(3);			// clear 3rd bit
	//a.clearBit(10000);		// clear 10000th bit
	//a.toggleBit(3);			// toggle 3rd bit

	return 0;
}