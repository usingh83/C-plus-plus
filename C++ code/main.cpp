#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int hpr, hr;
	cin>>hpr>>hr;
	if(hr>50)
    {
		cout<<hpr*50;
	}
	else cout<<hpr*hr;
	return 0;
}

