#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void myFunction( int counter)
{
if ( counter > 0 )
       {
       cout<<"hello"<<counter<<endl;
       myFunction(--counter);
       cout<<counter<<endl;
       }
else(counter == 0);
    
} 
int main(int argc, char** argv) {
	myFunction(-8);
}



