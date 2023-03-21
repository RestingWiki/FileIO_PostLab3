#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countElement(string& line);
void storeData(string* arr,string& line);
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

	/////////////////////////////////////////////////
	// Create an array to store library.txt data   //
	/////////////////////////////////////////////////
	string** libArr = new string * [n1];
	for (int i = 0; i < n1; i++)
	{
		libArr[i] = new string[6];
		for (int j = 0; j < 6; j++)
		{
			libFile >> libArr[i][j];
			cout << libArr[i][j] << " ";
		}

		cout << endl;
		
	}






	//////////////////////////////////////////
	// Create an array to store author data //
	//////////////////////////////////////////
	string** authArr = new string * [n2];
	for (int i = 0; i < n2; i++)
	{
		getline(authFile, line);
		authArr[i] = new string[countElement(line) +1];
		authArr[i][0] = to_string(countElement(line));
		storeData(authArr[i], line);

		for (int j = 0; j < countElement(line) +1; j++)
		{
			cout << authArr[i][j] << " ";
		}
		cout << endl;
	}
	




	string lib = "LA";
	string a = "David";
	bool flag1 = false, flag2 = false;
	int row1, row2;

	for (int i = 0; i < n1;i++)
	{
		if (lib == libArr[i][0])
		{
			flag1 = true;
			row1 = i;

			break;
		}
	}


	for (int i = 0; i < n2; i++)
	{

		if (a == authArr[i][1])
		{
			flag2 = true;
			row2 = i;
			break;
		}
	}


	if (flag2 && flag1)
	{
		bool flag3 = false;
		for (int i = 1; i < 6; i++)
		{

			{ 
				for (int j = 2; j <= stoi(authArr[row2][0]);j++)
				{
					int val1 = stoi(libArr[row1][i]);
					int val2 = stoi(authArr[row2][j]);
					cout << "libArr[row1][i] = " << val1 << endl;
					cout << "authArr[row2][j] = " << val2 << endl;
					cout << val1 - val2 << endl;
					if (val1 - val2 == 0)
					{
						cout << "Equal" << endl;
						flag3 = true;
						break;
					}
				}
			}

			if (flag3)
				break;
		}

		if (flag3)
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}
	else
		cout << "False";




	// Release memory
	for (int i = 0; i < n1; i++)
	{
		delete[] libArr[i];
	}
	delete[] libArr;

	for (int i = 0; i < n2; i++)
	{
		delete[] authArr[i];
	}
	delete[] authArr;


	return 0;
}

int countElement(string& line) {
	int count = 0;
	string::size_type wStart = 0, wEnd = 0;

	
	wStart = line.find_first_not_of(" ", 0);
	wEnd = line.find_first_of(" ", wStart);
	count++;
	while (wStart != string::npos)
	{
		wStart = line.find_first_not_of(" ", wEnd);
		wEnd = line.find_first_of(" ", wStart);
		if (wStart > 9999)
			break;
		count++;
	}

	return count;
}
void storeData(string* arr,string& line) {
	int i = 1;
	string::size_type wStart, wEnd;
	wStart = line.find_first_not_of(" ");

	while (wStart != string::npos)
	{
		wEnd = line.find_first_of(" ",wStart);
		arr[i] = line.substr(wStart, wEnd - wStart);
		wStart = line.find_first_not_of(" ", wEnd);
		i++;
	}
}
