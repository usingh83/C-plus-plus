#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node{//a structure node to represent a node of a linked list
	int Value;//value of the node
	Node* next;//a pointer that points to the next structure of the type Node
};

int Largest(Node* head) {
int largest;
if (head->next==NULL){
return head->Value; 
}
largest=Largest(head->next);
if(head->Value>largest)
	{		
		return head->Value;		
	}
	else
	return largest;
}

int count_d(Node* head)
{
	int index;//Creates an index variable
	if(head->next==NULL)//base case, checks if it's the last node or not
	{
		
		if(head->Value==5)//checks if the last node is 5 or not
		{
		return index+1;//if the last node is 5, then increment the value of index by 1
		}
		else return index;//else return index
	}
	else //if it's not the last node
	{
		if(head->Value==5)//and the value of the node is equal to 5
		{		
		index=1+count_d(head->next);//then recursively call count_d function and adding 1 to represent 1 count
		return index;//return the index variable, which has added the value of each subsequent recursion call
		}
		else return count_d(head->next);//if the value is not 5, recursively call count_d function without incrementing the index variable
	}
}
int add_list(Node* head)
{
	if(head->next==NULL)//the base case, checks if head has reached the end of the list
	{
		return head->Value;//then returns the value of the node
	}
	else 
	{
		return head->Value+add_list(head->next);//else recursively call the add_list function for the next node subsequently, 
		                                        //adding the returning value with the respective head value
	}
}
void addfirst(Node* &head,int num){//call by referance to make the changes in the function apply to the main
	Node * node=new Node;//Creates a new node
    node->Value=num;//assign the value of int num being passed to the function to the new node
	node->next=NULL;//assign null to the node to signify the end of the linked list
	head=node;//assign the value of head to the node
	}		

void addafterPos(Node* head,int num,int p){
	Node * node=new Node;//Creates a new node
	node->Value=num;//assign the value of int num being passed to the function to the new node
	while(--p>=1) {//decrement the value of the position being passed to the function, 
	               //moving head by 1 each time till head reaches the position after which insert is required
		if(head->next==NULL){//If head has reached the end of the list, then break out of the loop
		break;	
		}
		else head=head->next;//else move the head to the next position
	}
	node->next=	head->next;//Link the new node to point to the value head was previously pointing
	head->next=node;////links head to the new node
	}		
	

void insertaltFive(Node* head){
	Node* n=new Node;//Creates a new node
	int i=-1;//initialize the position where the new node is to be inserted from -1
	i+=2;//Increments the position by 2, to insert 5 at the alternate position, at every recursive call
	n->Value=5;//Assign the value 5 to the new node
	if(head->next!=NULL)//checks if the head pointer has reached the last node or not
	{
		addafterPos(head,5,i);//adds 5 after each subsiquent value of i, which is being incremented by 2 starting at -1;
		insertaltFive(head->next->next);// recursively calls the insertaltFive function to move the head 2 places forward,
		                                // 1 place for the previous head and 1 for the newly inserted node with value of 5
	
	}
	else addafterPos(head,5,i+1);	//adds a 5 after the last node
}
int display(Node* head){
	cout<<"<----------------------------------------------------------------------->\n";//Seperates each set of display calls
	while(head){//traverse throught the list till the end Node
		cout<<head->Value<<" ";//Prints the value of each node
		head=head->next;//Moves to the next node
	}
	cout<<"\n";//Move to next line after the loop has completed
}

int main(int argc, char** argv) {
	Node* head=new Node;//a new Node head
	int s[]={2,0,2,1,3,1,9,6,7,3};//a array of the digits in my student id
	
	for(int i=0;i<10;i++){//loops through the array of digits, entering the digits sequencially in a Linked List
		if (i==0){
		addfirst(head, s[i]);//Condition to create the first Node of the linked list	
		}
		else addafterPos(head,s[i],i);//Condition to add the links to the List 
	}
	
	insertaltFive(head);// this function will insert 5 at alternate positions in the linked list
	display(head); //displays the linked list with the digits of the student id	
	cout<<count_d(head)<<"\n"; //counts the occurance of 5 in the linked list	
	cout<<add_list(head)<<"\n"; //add the digits in the list and returns the sum
	cout<<Largest(head)<<"\n";
	return 0;
}

