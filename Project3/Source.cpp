#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// Price array
	int pArr[100][2];
	int bArr[2][200];


	// Open the 2 file
	ifstream pfile("price.txt");
	ifstream bfile("buy.txt");

	if (pfile.is_open() && bfile.is_open())
		cout << "YES" << endl;

	// Get the total line in each file
	int n1, n2;
	string line;


	pfile >> n1;

	
	// Move the content from the price.txt file to the array
	for (int i = 0; i < n1; i++)
	{
		pfile >> pArr[i][0];
		cout << pArr[i][0] << " ";
		pfile >> pArr[i][1];
		cout << pArr[i][1] << endl;
	}
	


	bfile >> n2;
	// Move the next  line in the file, the line will be emtpy
	getline(bfile, line);


	
	return 0;
}