#include <iostream>

using namespace std;

int peakFinder(int a[],int h,int l){
    int mid=(h+l)/2;
	cout<<"\n----"<<mid; 
	   
    if( a[mid]<a[mid-1] )
	return peakFinder(a,mid-1,0);

	else if(a[mid]<a[mid+1])
	return peakFinder(a,h,mid+1);
	
	else return a[mid];    
}
int main(){
	int s[]={2,0,2,1,3,1,1,2,3,2,1,6,7};
	int h=sizeof(s)/sizeof(s[0]);
	cout<<h;
    int peak=peakFinder(s,h,0);
    cout<<"\n////"<<peak;
} 
