#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int *RevArray(int a[],int i,int j){
	int l=sizeof(a);
	int temp;	
	if (i-1<j-1)
	{
		temp=a[i-1];
		a[i-1]=a[j-1];
		a[j-1]=temp;
		return RevArray(a,i+1,j-1);
	}
	else return a;
}

int main(int argc, char** argv) {
	int ar[]={1,2,3,4,5,6,7,8,9,10};
	int *br=RevArray(ar,3, 8);
    for(int i=0;i<=sizeof(br);i++)
    {
    	cout<<"-----"<<br[i];
	}
	return 0;
}
