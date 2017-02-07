#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int RecPow(int x,int n){
	if (n==1)
	{
		return x;
	}
	else return x*RecPow(x,n-1);	
}

int main(int argc, char** argv) {
	int br=RecPow(2,30);
    cout<<"-----"<<br;
	return 0;
}
