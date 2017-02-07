#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int RecSum(int a[],int i){
	int sum;	
	if (i-1==0)
	{
		return a[0];
	}
	else return a[i-1]+RecSum(a,i-1);	
}

int main(int argc, char** argv) {
	int ar[]={1,2,3,4,5,6,7,8,9,10};
	int br=RecSum(ar,3);
    cout<<"-----"<<br;
	return 0;
}
