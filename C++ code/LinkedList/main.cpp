#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node{
	int Value;
	Node* next;
};

int count_d(Node* head)
{
	int index;
	if(head->next==NULL)
	{
		
		if(head->Value==5)
		{
		return index+1;
		}
		else return index;
	}
	else 
	{
		if(head->Value==5)
		{		
		index=1+count_d(head->next);
		return index;
		}
		else return count_d(head->next);
	}
}
int add_list(Node* head)
{
	int sum=0;
	if(head->next==NULL)
	{
		return head->Value;
	}
	else 
	{
		return head->Value+add_list(head->next);
	}
}
void addfirst(Node* &head,int num){
	Node * node=new Node;
    node->Value=num;
	node->next=NULL;
	head=node;
	}		

void addafterPos(Node* head,int num,int p){
	Node * node=new Node;
	node->Value=num;
	while(--p>=1) {
		if(head->next==NULL){
		break;	
		}
		else head=head->next;
	}
	node->next=	head->next;
	head->next=node;
	}		
	
void addAfterNode(Node* node1,Node* node2)
{
	node2->next=node1->next;
	node1->next=node2;	
}

void insertaltFive(Node* head){
	Node* n=new Node;
	int i=-1;
	i+=2;
	n->Value=5;
	if(head->next!=NULL)
	{
		addafterPos(head,5,i);
		insertaltFive(head->next->next);		
	
	}
	else addafterPos(head,5,i+1);	
}
int display(Node* head){
	cout<<"<----------------------------------------------------------------------->\n";
	while(head){
		cout<<head->Value<<" ";
		head=head->next;
	}
	cout<<"\n";
}
int getMiddleforOdd(Node* head){
	Node* middle=head;
	Node* end=head;
	
	int i=0;
	while(end->next!=NULL)
	{
			middle=middle->next;
			end=end->next->next;		
	}
	return middle->Value;
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
	
	display(head);//displays the linked list with the digits of the student id
	cout<<count_d(head)<<"\n";//counts the occurance of 5 in the linked list
	cout<<add_list(head)<<"\n";//add the digits in the list and returns the sum
	insertaltFive(head);// this function will insert 5 at alternate positions in the linked list
	display(head); //displays the linked list with the digits of the student id
	cout<<count_d(head)<<"\n"; //counts the occurance of 5 in the linked list
	cout<<add_list(head); //add the digits in the list and returns the sum
	return 0;
}

