#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int RecPow(int x,int n){
	if (n==1)
	{
		return x;
	}
	else if(n%2==0) return RecPow(x,n/2)*RecPow(x,n/2);	
	else return x*RecPow(x,(n-1)/2)*RecPow(x,(n-1)/2);
}

int main(int argc, char** argv) {
	int br=RecPow(2,30);
    cout<<"-----"<<br;
	return 0;
}
