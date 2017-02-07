#include <iostream>
#include <fstream>
#include<string>
#include <iomanip>
using namespace std;
int main()
{
	ifstream indata;
	ofstream outdata;
	outdata.open("aaron.csv", ios::app);
	outdata << "a1,b1,c1" << endl;
	outdata << "a2,b2,c2" << endl;

	indata.open("aaron.csv");
	string cell1;

	indata >> cell1;

	cout << cell1 << "\n\n";

	system("pause");
	return 0;
}
