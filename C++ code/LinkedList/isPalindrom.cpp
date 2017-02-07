#include <iostream>
#include <Math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


bool isPrime(string a,int count){
	if(count<a.length())
	{
		if(a[count]!=a[a.length()-count-1])
		{
			return false;
		}
		else return isPrime(a,count+1);
	}
	else return true;
}

int main(int argc, char** argv) {
	string str="kaliilak";
	bool br=isPrime(str,0);
    cout<<"-----"<< (br ? "true" : "false");
	return 0;
}
