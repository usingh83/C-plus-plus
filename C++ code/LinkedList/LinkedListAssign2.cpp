#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node{//a structure node to represent a node of a linked list
	int Value;//value of the node
	Node* next;//a pointer that points to the next structure of the type Node
};	
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
int display(Node* head){
	cout<<"<----------------------------------------------------------------------->\n";//Seperates each set of display calls
	while(head){//traverse throught the list till the end Node
		cout<<head->Value<<" ";//Prints the value of each node
		head=head->next;//Moves to the next node
	}
	cout<<"\n";//Move to next line after the loop has completed
}
Node* selectionsort(Node* head)
{
	Node* current;//pointer to iterate through the partition
	Node* partition=head;	//Pointer to the start of partition, which is initially the head of the linkedlist 
	Node* prev_part=NULL;   //pointer to the node just before the partition, initialized to null when partition is at the head node
	Node* swap;  //Pointer to help in swaping the pointers
	Node* prev_min=NULL;//pointer to the node before the minimum node, to
	Node* min;//Pointer to the minimum node
	while(partition->next!=NULL)//condition to check if the partition is a the last node, as the last node is any ways sorted, we wish to come out of the loop then
	{   current=partition;//points the current pointer to the beginnig of the partition after successive interation
	    min=partition;//Assumes the first node of the partition as the minimum element
	    //this block will return the pointer to the minimum node and the node before it
		while(current->next!=NULL)//traverses through the linked list, starting at partition
		{
			if(prev_part==NULL)//checks if the list has any sorted node or not, this condition prevents the code from terminating due to null pointer comparison
			{
			if(current->next->Value<min->Value)//compare the value at minimum node with the value of the node next to the current node
			   {
					prev_min=current;//if a smaller value then the current minimum is found, the prev_min will point to the current node, i.e the node before the minimum node
					min=prev_min->next;//and min node will point to the node with the new minimum.
			   }
		    }
			else
			{
				if(current->next->Value<prev_min->next->Value)//compare the value at minimum node with the value of the node next to the current node
				{
					prev_min=current;//if a smaller value then the current minimum is found, the prev_min will point to the current node, i.e the node before the minimum node
					min=prev_min->next;//and min node will point to the node with the new minimum.
				}
			}
			current=current->next;//moves the pointer forward
		}//Logic to sort the links of the partition node and the minimum node
		if(min->Value!=partition->Value)//if the value of the minimun node and the partition node is equal, then don't swap
		{
		    if(prev_part==NULL)
		    {//checks if partition is the head node of the list
			    if(prev_min==partition) // checks if the nodes to be sorted are consecutive nodes 
			    {
				    partition->next=min->next;// point the next of partition to next of the minimum node
				    min->next=partition;//point the next of minimum node to partition node
			    }
			    else//else if the nodes are node consecutive
			    {
			        swap=min->next;//store the value of min next in a temporary swap variable
			        min->next=partition->next;//point minimun nodes next to partition nodes next
			        partition->next=swap;//and then assign the value of swap pointer to partitions next
			        prev_min->next=partition;//now make the node before minimun node to point to partition
			    }
			    partition=min;//adjust the pointes partition to the position it was before the swap
			    head=min;//adjust the head node to the begining of the list
		    }
		    else// partition is not the head node of the list
		    {
			    if(prev_min==partition)//// checks if the nodes to be sorted are consecutive nodes 
			    {  
				    partition->next=min->next; // point the next of partition to next of the minimum node
				    min->next=partition;//point the next of minimum node to partition node
				    prev_part->next=min;//link the link before the partition node to the minimum node
			    }
			    else//else if the nodes are node consecutive
			    {
			        swap=min->next;//store the value of min next in a temporary swap variable
			        min->next=partition->next;//point minimun nodes next to partition nodes next
			        partition->next=swap;//and then assign the value of swap pointer to partitions next
			        prev_min->next=partition;//now make the node before minimun node to point to partition
			        prev_part->next=min;//link the link before the partition node to the minimum node
		        }
			    partition=min;//adjust the pointes partition to the position it was before the swap
		   }
	    }
		prev_part=partition;//stores the value of previous partition before incrementing it to the next node
		prev_min=partition;//makes the previous minimum pointer point to the node before the new partition, as the new partition will be assigned to the new minimum in the next iteration
	    partition=partition->next;//increments the partition pointer to point at the next node
   }    
	return head;//return the new head of the linked list.
}
int main(int argc, char** argv) {
	Node* head=new Node;//a new Node head
	int s[]={2,0,2,82,15,1,9,6,7,3,16,44,23,67};//a array of at least 10 numbers
	
	for(int i=0;i<14;i++){//loops through the array of numbers, entering the digits sequencially in a Linked List
		if (i==0){
		addfirst(head, s[i]);//Condition to create the first Node of the linked list	
		}
		else addafterPos(head,s[i],i);//Condition to add the links to the List 
	}
	
	display(head); //displays the linked list of the inserted numbers	
	head=selectionsort(head);//selectionsort function which sorts the linkedList and returns the new head node
	display(head);//displays the linked list of the inserted numbers
	return 0;
}

