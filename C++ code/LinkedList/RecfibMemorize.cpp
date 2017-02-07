#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int Recfib(int n){
	int a[n+1];
	for(int i=2;i<n+1;i++){
		a[i]=-1;
	}
	a[1]=1;
	a[0]=0;
	if(a[n]==-1){
		a[n]=Recfib(n-1)+Recfib(n-2);
		return a[n];
		}
    else return a[n];
}

int main(int argc, char** argv) {
	
	int br=Recfib(10);
    cout<<"-----"<<br;
	return 0;
}
