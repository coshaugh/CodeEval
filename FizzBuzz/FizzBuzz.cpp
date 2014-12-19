// FIZZ BUZZ
// -----------------------------------------------------------------------------
// The first player says the number “1”, and each player says next number in 
// turn. However, any number divisible by X (for example, three) is replaced by 
// the word fizz, and any divisible by Y (for example, five) by the word buzz. 
// Numbers divisible by both become fizz buzz. A player who hesitates, or makes 
// a mistake is eliminated from the game.
// 
// Write a program that prints out the final series of numbers where those 
// divisible by X, Y and both are replaced by “F” for fizz, “B” for buzz and 
// “FB” for fizz buzz.
// 
// INPUT SAMPLE:
// Program should accept a file as its first argument. Each line contains 3
// numbers that are space delimited: first divider (X), second divider (Y), and 
// the third number is how far you should count (N). Assume that the input file 
// is formatted correctly and the numbers are valid positive integers.
// For example: 2 7 15
// 
// OUTPUT SAMPLE:
// Print out the series 1 through N replacing numbers divisible by X with “F”, 
// numbers divisible by Y with “B” and numbers divisible by both with “FB”. 
// Since the input file contains multiple sets of values, your output should 
// print out one line per set. Ensure that there are no trailing empty spaces in
// each line you print.
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	ifstream inputFile;
	string lineBuffer;

	inputFile.open(argv[1]);	// open file for reading
	while(!inputFile.eof()) {
		getline(inputFile, lineBuffer);
		// if assuming corrupted input, do stuff here. skipped for now
		int X, Y, N;
		string delimiter = " ";
		
		// PARSING INPUT
		X = atoi(lineBuffer.substr(0, lineBuffer.find(delimiter)).c_str());
		
		lineBuffer.erase(0, lineBuffer.find(delimiter)+1);
		Y = atoi(lineBuffer.substr(0, lineBuffer.find(delimiter)).c_str());
		
		lineBuffer.erase(0, lineBuffer.find(delimiter)+1);
		N = atoi(lineBuffer.substr(0, lineBuffer.find(delimiter)).c_str());
		
		// GAME PLAY
		for(int i = 1; i <= N; i++) {
			if (i%X == 0) {
				cout << " F";
				if (i%Y == 0)
					cout << "B";
			}
			else if (i%Y == 0)
				cout << " B";

			else
				cout << " " << i;
		}
		cout << endl;
	}

	inputFile.close();	// close file

	return 0;
}