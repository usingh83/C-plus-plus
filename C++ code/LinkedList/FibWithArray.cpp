#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int Recfib(int n){
	int ar[n+1];
	ar[0]=0;
	ar[1]=1;
	for(int i=2;i<=n;i++){	
	 ar[i]=ar[i-1]+ar[i-2]; 
}
return ar[n];
}
int main(int argc, char** argv) {
	int br=Recfib(4);
    cout<<"-----"<<br;
	return 0;
}
