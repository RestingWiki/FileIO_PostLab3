#include <iostream>
#include <fstream>
using namespace std;

int main() {

	// Open the 2 file
	ifstream pfile("price.txt");
	ifstream bfile("buy.txt");

	if (pfile.is_open() && bfile.is_open())
		cout << "YES" << endl;
	return 0;
}