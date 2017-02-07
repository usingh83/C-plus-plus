#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int tertiarySearch(int* a,int f, int l,int num){
	int diff=(l-f)/3;//divide the list into 3 parts
	if(l==f && a[l]!=num){
		return -1;
	}
	else
	{
	if(a[f+diff]>num)//check if the number is in the 1st partition
	{
		return tertiarySearch(a,f,f+diff-1,num);//recusively calls the tertiarySearch funtion on the 1st partition
	}
	else if(a[f+diff]<num && a[f+diff*2]>num)//check if the number is in the 2nd partition
	{		
		return tertiarySearch(a,f+diff+1,f+diff*2-1,num);//recusively calls the tertiarySearch funtion on the 2nd partition
	}
	else if(num>a[f+diff*2]) //check if the number is in the 3rd partition
	{		
		return tertiarySearch(a,f+diff*2+1,l,num);//recusively calls the tertiarySearch funtion on the 3rd partition
	}
	else //else if not inside the partition
	{
	    if(a[f+diff]==num)//check if the value is the boundary of 1st partition and 2nd partition
	    {
		return f+diff;//if found then return the index
 	    } 
		else if(a[f+diff*2]==num)//check if the value is the boundary of 2nd partition and 3rd partition
		{
			return f+diff*2;//if found then return the index
		}
		else return -1;//else return -1
	}
}
}
int main(int argc, char** argv) {
	int a[]={1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39};//a array of at least 10 numbers
	int num;//declare a number that you want to search in the list
	cout<<"Enter the number to search\n";//direction for the user
	cin>>num;//prompt the user for unput
	int index=tertiarySearch(a,0,sizeof(a)/sizeof(a[0]),num);//stores the index returned by the function call
	if(index>-1)//if index is found
	{
    cout<<"Number "<<num<<" found at Index "<<index<<"\n"; //returns the index
    }
    else cout<<"Number not found";//else prints the massege, number not found
	return 0;
}
