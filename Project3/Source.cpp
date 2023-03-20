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
	return 0;
}

