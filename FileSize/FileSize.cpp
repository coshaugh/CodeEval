// FILE SIZE
// -------------------------------------------------------------------
// INPUT:
// The first argument is the path to the file you  check the size of.
// 
// OUTPUT SAMPLE:
// Print the size of the file in bytes.
// For example: 55
// -------------------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	ifstream inputFile;
	int byteSize;

	inputFile.open(argv[1]);	// open file stream
	inputFile.seekg(0, inputFile.end);	// advance through file
	byteSize = inputFile.tellg();	// report current position in file

	cout << byteSize << endl;	// output position to screen

	inputFile.close();	// close file

	return 0;
}