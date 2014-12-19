// NICE ANGLES
// -------------------------------------------------------------------
// Write a program that outputs the value of angle, reducing its 
// fractional part to minutes and seconds.

// INPUT SAMPLE:
// The first argument is a path to a file that contains the values of 
// angles with their decimal fractions:

// For example:	330.39991833
// 				0.001
// 				14.64530319
// 				0.25
// 				254.16991217

// OUTPUT SAMPLE:
// Print to stdout values of angles with their fractional parts 
// reduced to minutes and seconds.
// The whole and fractional parts are separated by period, minutes are
// separated by apostrophe, seconds by double quotes. The values of 
// minutes and seconds are shown as two numbers (with leading zeros 
// if needed).
// For example:	330.23'59"
// 				0.00'03"
// 				14.38'43"
// 				0.15'00"
// 				254.10'11"
// -------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <deque>
#include <string>
using namespace std;

// method prototypes
int multiply(deque<int>&);
void assignTime(int, string&, deque<int>&);

int main(int argc, char* argv[]) {
	// following variables deal with file i/o
	ifstream inputFile;
	string lineBuffer;
	inputFile.open(argv[1]);

	while(!inputFile.eof()) {
		// following variables hold coordinate information
		string degree;
		string minute = "";
		string second = "";

		// get line up to '.'
		getline(inputFile, degree, '.');

		// get rest of line and put into vector in integer form
		getline(inputFile, lineBuffer);
		deque<int> intBuffer;
		for(int i = 0; i < lineBuffer.length(); i++) {
			intBuffer.push_back(lineBuffer[i]-48);
		}

		// method calls for conversion to find minute value
		int digitsShifted = multiply(intBuffer);
		assignTime(digitsShifted, minute, intBuffer);

		// method calls for conversion to find second value
		digitsShifted = multiply(intBuffer);
		assignTime(digitsShifted, second, intBuffer);

		printf("%s.%s\'%s\"\n", degree.c_str(), minute.c_str(), 
			second.c_str());
	}
	return 0;
}

// multiplies deque by 60, and returns the integer value signifying
// the number of digits in front of the decimal
int multiply(deque<int>& list) {
	// perform multiplication on number stored in deque
	int carryDigit = 0;
	for(int i = list.size()-1; i >= 0; i--) {	// moves right to left
		list[i] *= 6;
		list[i] += carryDigit;
		carryDigit = list[i]/10;
		list[i] %= 10;
	}
	// appending zero aka multiplication by ten
	list.push_back(0);

	// if carry on leftmost value, that carry + shift from x10 == 2
	if(carryDigit != 0) {
		list.insert(list.begin(), carryDigit);
		return 2;
	}
	else	// otherwise only shift from x10 == 1
		return 1;
}

// assigns minutes or seconds the appropriate value based on number of
// digits in front of decimal returned by multiply function.
void assignTime(int displacement, string& t, deque<int>& list) {
	if(displacement == 2) {
		t.append(to_string(list.front()));
		list.pop_front();
		t.append(to_string(list.front()));
		list.pop_front();
	}
	else {
		t.append("0");
		t.append(to_string(list.front()));
		list.pop_front();
	}	
}