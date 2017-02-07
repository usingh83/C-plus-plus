#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <bits/stdc++.h>

using namespace std;
# define INF 0x3f3f3f3f//logic for infinite number

 /*Global Variables*/
const int Ver = 10;//Number of vertices
const int Edge = 20;//Number of edges
int dist[Ver];//to track the shortest distance of the node from the starting node
int child[Ver][2];//a  2-d array to track the child of the index and it's weight
bool visited[Ver]={false};//a Boolean array to track visited nodes
// A structure to represent an adjacency list node
struct Node
{
    int Index;//The name of the node, we will identify the node with it's index
    int weight;//this feild tracks the weight of the edge comming into the node
    struct Node* next;//pointer to the next node of the adjacency list    
};
 class myComparator{//class for custom sorting, to be passed to priority queue
    public: int operator() (const Node& p1, const Node& p2)
    {
        return p1.weight > p2.weight;//logic for getting the min of 2 nodes
    }
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
void add_edge(int v1,int v2,int weight){
	Node* Node_v2=new Node;//create a new node and create a pointer to it
	Node_v2->Index=v2;//initialize the new node with the value v2
	Node_v2->weight=weight;//initialize the new node with the value weight
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
	Node_v1->weight=weight;//initialize the new node with the value weight
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
	Node* temp1;
	for(int i=0;i<G->V;i++){//iterate through the array of pointers to the adjacency list
		temp=G->array[i];//create a new node pointer and point it to the adjacency list of the index i
		temp1=G->array[i];//create a new node pointer and point it to the adjacency list of the index i
		cout<<"Adjecenty List for Node "<<i<<"-->>> ";//display i
		while(temp!=NULL){//traverse through the adjacency list
			cout<<"    "<<temp->Index<<"-->>> ";//display the Index of each node
			temp=temp->next;
		}
		cout<<":   ";
		while(temp1!=NULL){//traverse through the adjacency list
			cout<<"    "<<temp1->weight<<", ";//display the weight of each node
			temp1=temp1->next;
		}
		cout<<"\n-------------***********************--------------"<<"\n";
		cout<<"-------------***********************--------------"<<"\n";
	}
}

void DijkstraShortestPath(int index)
{
	priority_queue<Node, vector<Node>, myComparator > q;//initialize a queue datastructure
	Node* temp1=new Node; //create a new node
	temp1->Index=index;//initialize it for index value index
	temp1->next=NULL;//initialize it to point to null as next node
	temp1->weight=0;//initialize it for weight 0
	dist[index]=0;//initialize the dist array for starting node to 0
	Node v=*temp1;//create a node v, and intitalize it to the newly created node above
	q.push(v);//push the node into the queue
	visited[index]=true;//update visited array for the index of the node as true
	while(!q.empty())//loop till the queue is empty
	{
		v=q.top();//store the least of the queue in integer v
		q.pop();//remove the least value of the queue
		Node* temp=G->array[v.Index];//create a new node pointer and point it to the adjacency list of the index v
		while(temp!=NULL){//traverse through the adjacency list
			if(visited[temp->Index]==false && dist[temp->Index]>dist[v.Index]+temp->weight )//if the child node is not visited & dist array for index has a value 
			{//Greater then parents dist + the weight of the edge, connecting the parent and child
			dist[temp->Index]=dist[v.Index]+temp->weight;//then update the child dist with the value of parent dist+weight of edge
			child[temp->Index][0]=v.Index;//assign parents Index to the [][0]'th index of the 2-d array
			child[temp->Index][1]=temp->weight;//assign the edge weight to the [][1]'th index of the 2-d array
			Node u=*temp;//create a Node variable to hold the node
			q.push(u);//push the node into the queue
			visited[temp->Index]==true;//update visited array for the index as true
			}
		temp=temp->next;//move to the next node of the adjacency list
		} 
	}
	for(int i=0;i<G->V;i++)
	G->array[i]=NULL;//reset the adjacency list to NULL
	for(int i=0;i<G->V;i++){				
		if(i!=index){
		add_edge(i,child[i][0],child[i][1]);//create new edges for the spanning tree, passing the parents index, childs index and the childs weight		
		}
	}
}
int main()
{
    adjList(Ver,Edge);//initialize the graph data structure
    add_edge(0,9,8);//call the add_edge() to introduce an edge between 2 nodes
    add_edge(0,6,2);
    add_edge(1,9,3);
    add_edge(1,7,5); 
	add_edge(1,2,8);
    add_edge(1,8,11);    
    add_edge(2,8,23); 
	add_edge(2,3,1);
    add_edge(2,4,15);     
	add_edge(3,8,8);
    add_edge(3,4,7);    
    add_edge(4,5,6);     
	add_edge(4,8,5);
    add_edge(4,7,4);         
	add_edge(5,6,3);
    add_edge(5,7,17);             
	add_edge(6,9,9);
    add_edge(6,7,21);             
	add_edge(7,8,16);	             
	add_edge(7,9,11);	
	cout<<"----------------------------------------------------Graph-------------------------------------------------\n";
    print_graph();//print graph before the shortest path algorithm is run
	cout<<"\n";
	for(int i=0;i<G->V;i++){
		dist[i]=INF;//assign dist to infinity
	}
	cout<<"---------------------------------Dijkstra's Shortest Path Spanning Tree------------------------------------\n";
	DijkstraShortestPath(0);	//calling the funtion
    print_graph();//displaying the graph
	return 0;
}
