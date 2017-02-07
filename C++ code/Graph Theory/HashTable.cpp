#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

float N=0.0;//initialize the number of enteries in the hash table to zero
int hashfunction(int student_id,int table_size){
	return student_id%table_size;
}
		
bool IsPrime(int number)//Funtion to check weather a number is a prime or not
{
    if (number == 2 || number == 3)
        return true;
    if (number % 2 == 0 || number % 3 == 0)
        return false;
    int divisor = 6;
    while (divisor * divisor - 2 * divisor + 1 <= number)
    {
        if (number % (divisor - 1) == 0)
            return false;
        if (number % (divisor + 1) == 0)
            return false;
        divisor += 6;
    }
    return true;
}

int NextPrime(int a)//function to return the next prime number
{
    while (!IsPrime(++a)) 
    { }
    return a;
}		

int* HashTableDouble(int table_size){//function for dynamically increasing the size of an array
	int* hashtable=new int[table_size];//a new emply array is created based on the table size parameter
	for(int i=0;i<table_size;i++){
		hashtable[i]=0;//the array is initialized to zero
	}
	return hashtable;//pointer to the array is returned
}
string* HashTableDouble1(int table_size){//function for dynamically increasing the size of an array
	string* hashtable=new string[table_size];//a new emply array is created based on the table size parameter
	for(int i=0;i<table_size;i++){
		hashtable[i]="\0";//the array is initialized to zero
	}
	return hashtable;//pointer to the array is returned
}

int main(){
	string student_name[20]={"rahul","anil","mukesh","mahesh","mani"
							,"monu","sonu","prakash","nai","kajo",
							"ajay","viyay","yoan","michel","peter",
							"gorge","ferhan","mukul","mahesh","raju"};
	int student_id[20]={1234567890,1234567891,1234567892,1234567893,1234567894,
						1234567895,1234567896,1234567897,1234567898,1234567899,
						1234567900,1234567901,1234567902,1234567903,1234567904,
						1234567905,1234567906,1234567907,1234567908,1234567909};
	
	int table_size=NextPrime(10);//get the next prime number to 10
	int *hashtable=new int[table_size];//create a hash table array
	string *hashtable1=new string[table_size];////create an array to store student name
	int *tracker=new int[table_size];//create a tracker array
	for(int i=0;i<table_size;i++){
		hashtable[i]=0;//Initializer the new arrays to zero
		hashtable1[i]="\0";
		tracker[i]=0;
	}
	N++;//Increment the entry counter
	int count=0;
	while(count<20)//exit if student id is zero
	{
		cout<<"Entering Student id = "<<student_id[count]<<" & Student name = "<<student_name[count]<<"\n";
		if((N/table_size)<=0.5)//if the load factor is smaller then 0.5
		{
			
		    int index=hashfunction(student_id[count],table_size);//get the index from the hashfunction
			while(tracker[index]!=0)//if there is collision move to the next empty slot
			{
				index++;	
			}
			hashtable[index]=student_id[count];//assign the values to the hash table
			hashtable1[index]=student_name[count];			
			tracker[index]=1;
		}
	else{//else
		int index;//create index variable to track the index returned by hash table
		index=hashfunction(student_id[count],table_size);//after the new table has been set up, we call the hash function on the student id
		while(tracker[index]==1)//if there is collision move to the next empty slot
			{
			index++;
			}
		hashtable[index]=student_id[count];		//assign the values to the hash arrays
		hashtable1[index]=student_name[count];
		tracker[index]=1;
		cout<<"****Load Factor above 0.5****\n";
		cout<<"----------------------Old HashTable------------------------\n";
		for(int i=0;i<table_size;i++){		
		printf("Hashtable at %d is: %d----",i,hashtable[i]);//display the array
		cout<<hashtable1[i]<<"\n";
		}
		int oldtable_size=table_size;//track the old table size
		table_size=NextPrime(table_size*2);//assign the next prime to the double of the table size to the table size
		int *Oldhashtable=hashtable;	//copy the address of the arrays	
		string *Oldhashtable1=hashtable1;
		int *Oldtracker=tracker;
		hashtable=HashTableDouble(table_size);		//call array modifier function on the arrays
		hashtable1=HashTableDouble1(table_size);
		tracker=HashTableDouble(table_size);
		for(int i=0;i<oldtable_size;i++)//load the values in the old hash table to the new hash table according to the new table size
		{
			if(Oldtracker[i]==1)//if an entry exists
			{
				index=hashfunction(Oldhashtable[i],table_size);//call hashing function wrt the new table size
				hashtable[index]=Oldhashtable[i];//assign the values to the hash table
				hashtable1[index]=Oldhashtable1[i];
				tracker[index]=1;
			}
		}
		delete [] Oldhashtable;		//delete the old hash tables
		delete [] Oldhashtable1;
		delete [] Oldtracker;			
		cout<<"----------------------New HashTable------------------------\n";
		for(int i=0;i<table_size;i++){		
		printf("Hashtable at %d is: %d----",i,hashtable[i]);//display the array
		cout<<hashtable1[i]<<"\n";
		}
		}
		cout<<"Student record entered,Table size is "<<table_size<<"\n";
	N++;
	count++;
	}
	for(int i=0;i<table_size;i++){		
	printf("Hashtable at %d is: %d----",i,hashtable[i]);//display the array
	cout<<hashtable1[i]<<"\n";
	}
}




