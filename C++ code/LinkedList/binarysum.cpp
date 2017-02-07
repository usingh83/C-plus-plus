#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int RecSum(int a[],int i, int n){
	int sum;	
	if (n==1)
	{
		return a[i];
	}
	else return RecSum(a,i,n/2)+RecSum(a,i+n/2,(n+1)/2);
}

int main(int argc, char** argv) {
	int ar[]={1,2,3,4,5,6,7,8,9,10};
	int br=RecSum(ar,0,10);
    cout<<"-----"<<br;
	return 0;
}
