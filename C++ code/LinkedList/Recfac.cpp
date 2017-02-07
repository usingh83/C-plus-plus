#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int Recfac(int n){
	if (n==1)
	{
		return 1;
	}
	else return n*Recfac(n-1);	
}

int main(int argc, char** argv) {
	int br=Recfac(6);
    cout<<"-----"<<br;
	return 0;
}
