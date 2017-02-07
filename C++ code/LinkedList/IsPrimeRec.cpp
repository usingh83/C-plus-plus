#include <iostream>
#include <Math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


bool isPrime(int num,int count){
	if(count<sqrt(num))
	{
		if(num%count==0){
			return false;
		}
		else return isPrime(num,count+1);
	}
	else return true;
}

int main(int argc, char** argv) {
	bool br=isPrime(2,2);
    cout<<"-----"<< (br ? "true" : "false");
	return 0;
}
