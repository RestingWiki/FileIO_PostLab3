#include <iostream>
#include <fstream>
using namespace std;

int main() {

	ifstream istr("student.txt");

	if (istr.is_open())
		cout << "YES" << endl;
	int n;
	istr >> n;
	cout << n << endl;

	int a = 0, b = 0, c = 0, d = 0;
	double arr[4];
	double avg;
	for (int i = 0; i < n; i++)
	{
		avg = 0;
		bool fail = false;
		for (int j = 0; j < 4; j++)
		{
			
			istr >> arr[j];
			avg += arr[j];
			if (arr[j] < 5)
				fail = true;
			
		}

		// Assign the grade
		if (fail)
		{
			d++;
			continue;
		}
		else
		{
			avg = avg / 4;
			if (avg >= 8)
				a++;
			else if (avg >= 6.5)
				b++;
			else if (avg >= 5)
				c++;
		}
	}

	
	cout << "A " << a << endl;
	cout << "B " << b << endl;
	cout << "C " << c << endl;
	cout << "D " << d << endl;

	return 0;
}