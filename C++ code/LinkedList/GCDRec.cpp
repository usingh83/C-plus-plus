#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int gcd(int x,int y){
	if (y==0)
	{
		return x;
	}
	else return gcd(y,(x%y));
}

int main(int argc, char** argv) {
	int br=gcd(6,3);
    cout<<"-----"<<br;
	return 0;
}
