#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void getSize(int& size, string& line);
void moveData(string* arr, string line, int size);
int main() {
	// Price array
	int pArr[20][2];

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

	// Create a pointer that points to an array with the size of n2
	string* infoArr = new string[n2];




	// Move to the next line.
	getline(bfile, line);
	for (int i = 0; i < n2; i++)
	{
		int size = 0;
		string line;
		getline(bfile, line);
		cout << line << endl;


		// Get the number of word in the line
		getSize(size, line);
		cout << "size: " << size << endl;

		// Create an array with the size of (size)
		string* data = new string[size];
		
		// Move the data from  the txt file to the array
		moveData(data, line,size);

		// The name of the customer
		infoArr[i] = data[0];

		// Total fee
		int total = 0;
		for (int j = 1; j < size ; j += 2)
		{
			cout << data[j] << endl;
			cout << data[j + 1] << endl;
			int code   = stoi(data[j])-1;
			int amount = stoi(data[j + 1]);

			total += pArr[code][1] * amount;
				
			cout << "END" << endl;
		}

		cout << "Total = " << total << endl;


		// Release the memory
		delete[] data;
		cout << infoArr[i] << " " << total << endl;
	}


	// Print result
	
	
	// Realse memory

	delete[] infoArr;
	return 0;
}

void getSize(int& size, string& line) {
	//  Count the element in the tokenized array;
	string::size_type wStart = 0, wEnd = 0;


	wStart = line.find_first_not_of(" ", 0);
	wEnd = line.find_first_of(" ", wStart);
	while (wStart != string::npos)
	{
		wStart = line.find_first_not_of(" ", wEnd);
		wEnd = line.find_first_of(" ", wStart);
		size++;
	}
}

void moveData(string* arr, string line,int size) {
	int i = 0;
	string::size_type wStart = 0, wEnd = 0;

	while (wStart != string::npos && i < size)
	{
		
		wStart = line.find_first_not_of(" ", wEnd);
		wEnd = line.find_first_of(" ", wStart);
		arr[i] = line.substr(wStart, wEnd - wStart);

		i++;
		
	}
}