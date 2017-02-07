#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int RecMaxArray(int a[],int i,int max){		
	if(i<sizeof(a)){
	if (max<a[i])
	{
		return RecMaxArray(a,i+1,a[i]);
	}
	else return RecMaxArray(a,i+1,max);
}
	else return max;	
}

int main(int argc, char** argv) {
	int ar[]={1,2,3,4,5,16,7,8,9,10};
	int br=RecMaxArray(ar,0,0);
    cout<<"-----"<<br;
	return 0;
}
