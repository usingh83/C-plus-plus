#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int Recfib(int n){
	
	if (n==1)
	{
		return 1;
	}
	else if (n==0) return 0;
	else return (Recfib(n-1)+Recfib(n-2));	
}

int main(int argc, char** argv) {
	int br=Recfib(4);
    cout<<"-----"<<br;
	return 0;
}
