#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
	
	// Open the 2 files
	ifstream libFile("library.txt");
	ifstream authFile("author.txt");

	if (libFile.is_open() && authFile.is_open())
		cout << "YES" << endl;

	// Get n1 and n2;
	string line;
	int n1, n2;
	libFile >> n1;
	authFile >> n2;

	// Move the next line
	getline(libFile,line);
	getline(authFile, line);
	return 0;
}

