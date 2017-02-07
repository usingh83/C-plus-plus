// A C Program to demonstrate adjacency list representation of graphs and does a Depth first

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;
 /*Global Variables*/
const int Ver = 10;//Number of vertices
const int Edge = 20;//Number of edges
bool discovered[Ver];//Boolean array to track the visited nodes for DFS and BFS
// A structure to represent an adjacency list node
struct Node
{
    int Index;
    struct Node* next;
};
 
// A structure to represent a graph. 
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;//Number of vertices
    int E;//Number of edges
    struct Node* array[Ver];//A graph is an array of adjacency lists.
};

Graph* G;//Pointer to the graph
/*This function helps initialize the data structure for graph*/
void adjList(int Ver,int Edge){
	G=new Graph;//initialize the graph structure
	G->V=Ver;//initialize the number of vertices
	G->E=Edge;//initialize the number of edges
	for(int i=0;i<G->V;i++){
		G->array[i]=NULL;//intialize each block in the array of pointers array[] to null
	}	
}


 /* function add_edge(v1,v2) creates an edge between 2 vertives v1 and v2*/
void add_edge(int v1,int v2){
	Node* Node_v2=new Node;//create a new node and create a pointer to it
	Node_v2->Index=v2;//initialize the new node with the value V2
	Node_v2->next=NULL;//initialize the next poiter to null
	Node* temp=G->array[v1];//create a new node pointer and point it to the adjacency list of the index v1
	if(temp==NULL){//if the list is empty
		G->array[v1]=Node_v2;//assign the new node as the first node of the list
	}
	else{//else
	while(temp->next!=NULL){//traverse to the end of the adjacency list
		temp=temp->next;
	}
	temp->next=Node_v2;//assign the new node to the end of the Adjacency list
	}
	//For the undirected graph we need to make an entry of v1 in v2's adjacency list as well, so we repeat what we did above
	Node* Node_v1=new Node;//create a new node and create a pointer to it
	Node_v1->Index=v1;//initialize the new node with the value V2
	Node_v1->next=NULL;//initialize the next poiter to null
	temp=G->array[v2];//create a new node pointer and point it to the adjacency list of the index v2
	if(temp==NULL){//if the list is empty
		G->array[v2]=Node_v1;//assign the new node as the first node of the list
	}
	else{//else
	while(temp->next!=NULL){//traverse to the end of the adjacency list
		temp=temp->next;
	}	
	temp->next=Node_v1;//assign the new node to the end of the Adjacency list
	}
}
/*this function prints the adjacency list for the graph*/
void print_graph(){
	Node* temp;//create a pointer to a node
	for(int i=0;i<G->V;i++){//iterate through the array of pointers to the adjacency list
		temp=G->array[i];//create a new node pointer and point it to the adjacency list of the index i
		cout<<"Adjecenty List for Node "<<i<<" \n";//display i
		while(temp!=NULL){//traverse through the adjacency list
			cout<<"    "<<temp->Index<<"-->>> ";//display the Index of each node
			temp=temp->next;
		}
		cout<<"\n-------------***********************--------------"<<"\n";
		cout<<"-------------***********************--------------"<<"\n";
	}
}
/*This function does a depth first search on the graph stating at node index*/
void DFS(int index){
	discovered[index]=true;//change the discovered boolean to true for the index
	cout<<"DFS: Visiting Node "<<index<<"\n";//display index
	Node* temp=G->array[index];//create a new node pointer and point it to the adjacency list of the index i
	while(temp!=NULL)//traverse through the adjacency list
	{
		if(discovered[temp->Index]==false)//if the node is not visited
		{
		DFS(temp->Index);//then recursively call DFS on the node
		}
		temp=temp->next;
	} 
}
/*This function does a breadth first search on the graph stating at node index*/
void BFS(int index){
	queue<int> q;//initialize a queue datastructure
	q.push(index);//push the node into the queue	
	discovered[index]=true;//change the discovered boolean to true for the index
	while(q.size()!=0)//loop till the queue is empty
	{
		int v=q.front();//store the front of the queue in integer v
		q.pop();//pop out the front of the queue
		cout<<"BFS: Visiting Node "<<v<<"\n";//display index
		Node* temp=G->array[v];//create a new node pointer and point it to the adjacency list of the index v
		while(temp!=NULL){//traverse through the adjacency list
		if(discovered[temp->Index]==false)//if the node is not visited
		{
		q.push(temp->Index);//push all the elements into the queue
		discovered[temp->Index]=true;//and set discovered boolean true
		}
		temp=temp->next;
	} 
}
}
int main()
{
    adjList(Ver,Edge);//initialize the graph data structure
    add_edge(0,9);//call the add_edge() to introduce an edge between 2 nodes
    add_edge(0,6);
    add_edge(1,9);
    add_edge(1,7); 
	add_edge(1,2);
    add_edge(1,8);    
    add_edge(2,8); 
	add_edge(2,3);
    add_edge(2,4);     
	add_edge(3,8);
    add_edge(3,4);    
    add_edge(4,5);     
	add_edge(4,8);
    add_edge(4,7);         
	add_edge(5,6);
    add_edge(5,7);             
	add_edge(6,9);
    add_edge(6,7);             
	add_edge(7,8);	             
	add_edge(7,9);
    print_graph();
	cout<<"\n";
	cout<<"\n<<<_______________Depth_First_Search_______________>>>\n\n";
    for(int i=0;i<G->V;i++){
    	discovered[i]=false;//initialize the discovered boolean to false for all the index
	}
	DFS(0);//calling Depth First Search, starting at 0
	cout<<"\n";
	cout<<"\n<<<______________Breadth_First_Search_______________>>>\n\n";
    for(int i=0;i<G->V;i++){
    	discovered[i]=false;//initialize the discovered boolean to false for all the index
	}
	BFS(0);//calling Depth First Search, stating at 0
	return 0;
}
