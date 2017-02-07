#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node{//a structure node to represent a node of a linked list
	int key;//value of the node
	int height;//height of the node
	Node* leftChild;//a pointer that points to the leftChild structure of the type Node
	Node* rightChild;//a pointer that points to the rightChild structure of the type Node
	Node* parent;//a pointer that points to the next structure of the type Node
};
Node* rotate(Node* node){//rotates the node with respect to the child and grandchild
	Node* child;//creates a child pointer
	Node* grandchild;//creates a grandchild pointer
	if((node->leftChild==NULL ? 0 :node->leftChild->height+1)>(node->rightChild==NULL? 0 :node->rightChild->height+1)){//checks if the left subtree is greater
		child=node->leftChild;//if so then go the assign leftchild of the node to child
		if(child->leftChild!=NULL){//if the leftchild of child is not null, then all the parent and childrens are in a same line
			grandchild=child->leftChild;//and we can assign the leftchild of child to grandchild
		}
		else{ //else we have a zigzag and we have to rotate the child and grandchild to get them in line
			grandchild=child->rightChild;//assign grandchild to rightchild of child
			node->leftChild=grandchild;//point node's leftchild to grandchild
			grandchild->parent=node;//point grandchild parent to node
			child->parent=grandchild;//assign child parent to grandchild
			child->rightChild=NULL;//make child rightchild NULL
			grandchild->leftChild=child;//point grandchild leftchild to child
			grandchild=child;//assign child to grandchild
			child=node->leftChild;//assign child to node's leftchild
			child->height++;//increament hieght of the child after rotation
			grandchild->height--;//decrement hieght of the child after rotation
		}		
		if(node->parent==NULL){//if node is root
			child->parent=NULL;//assign childs parent to NULL
			node->parent=child;//point node's parent to child
			if(child->rightChild!=NULL){//if child rightchild is not null
				node->leftChild=child->rightChild;//then make child's right child to node's leftchild
				child->rightChild->parent=node;//and point childs rightchilds parent to node
			} else node->leftChild=NULL;//else just point node's leftchild to NULL
			child->rightChild=node;//point child's rightchild to node
			node->height=node->height-2;//decrement node's hieght by 2
			node=child;//point node to child
			return node;//return node
		}		
		else{//else
			child->parent=node->parent;//assign childs parent to node's parent
			node->parent->leftChild=child;//point node's parent's leftchild to child		
			if(child->rightChild!=NULL){//if child rightchild is not null
				node->leftChild=child->rightChild;//then make child's right child to node's leftchild
				child->rightChild->parent=node;//and point childs rightchilds parent to node
			} else node->leftChild=NULL;//else just point node's leftchild to NULL
			node->parent=child;//point node's parent to child
			child->rightChild=node;	//point child's rightchild to node
			node->height=node->height-2;//decrement node's hieght by 2
			node=child;//point node to child
			while(node->parent!=NULL){//decreament all the node's hieghts above node by one till the root
				node->parent->height--;//decrements hieght of the node's parent
				node=node->parent;//and moves to the parent of the node
			}
			return node;//return node
		}	
		
	}
	
	if((node->leftChild==NULL ? 0 :node->leftChild->height+1)<(node->rightChild==NULL? 0 :node->rightChild->height+1)){//checks if the righ subtree is greater
		child=node->rightChild;//if so then go the assign rightchild of the node to child
		if(child->rightChild!=NULL){ //if the rightchild of child is not null, then all the parent and childrens are in a same line
			grandchild=child->rightChild;//and we can assign the leftchild of child to grandchild
		}
		else{ //else we have a zigzag and we have to rotate the child and grandchild to get them in line
			grandchild=child->leftChild;//assign grandchild to leftchild of child
			node->rightChild=grandchild;//point node's rightchild to grandchild
			grandchild->parent=node;//point grandchild parent to node
			child->parent=grandchild;//assign child parent to grandchild
			child->leftChild=NULL;//make child leftchild NULL
			grandchild->rightChild=child;//point grandchild rightchild to child
			grandchild=child;//assign child to grandchild
			child=node->rightChild;//assign child to node's rightchild
			child->height++;//increament hieght of the child after rotation
			grandchild->height--;//decrement hieght of the child after rotation
		}		
		if(node->parent==NULL){//if node is root
			child->parent=NULL;//assign childs parent to NULL
			node->parent=child;//point node's parent to child
			if(child->leftChild!=NULL){//if child leftchild is not null
				node->rightChild=child->leftChild;//then make child's leftchild to node's rightchild
				child->leftChild->parent=node;//and point childs leftchilds parent to node
			} else node->rightChild=NULL;//else just point node's righchild to NULL
			child->leftChild=node;//point child's leftchild to node			
			node->height=node->height-2;//decrement node's hieght by 2
			node=child;//point node to child
			return node;//return node
		}	
		else{//else
			child->parent=node->parent;//assign childs parent to node's parent
			node->parent->rightChild=child;//point node's parent's rightchild to child			
			if(child->leftChild!=NULL){//if child leftchild is not null
				node->rightChild=child->leftChild;//then make child's leftchild to node's rightchild
				child->leftChild->parent=node;//and point childs leftchilds parent to node
			} else node->rightChild=NULL;//else just point node's righchild to NULL
			node->parent=child;//point node's parent to child
			child->leftChild=node;//point child's leftchild to node			
			node->height=node->height-2;//decrement node's hieght by 2
			node=child;//point node to child
			while(node->parent!=NULL){//decreament all the node's hieghts above node by one till the root
				node->parent->height--;//decrements hieght of the node's parent
				node=node->parent;//and moves to the parent of the node
			}
			return node;//return node			
		}	
	}
}

Node* avlBalance(Node* node){//takes the newly inserted node as argument and checks if the magnitude of the difference of the hieghts of left subtree of the node 
                             //and right subtree of the node is greater then 1, if so then calls for rotate function on the node, else recurcively calls
                             //avlBalance() on the parent of the node
	    int diff=(node->leftChild==NULL ? 0 :node->leftChild->height+1)-(node->rightChild==NULL? 0 :node->rightChild->height+1);//checks if 
		                                                                    //left subtree and right subtrees exists, and takes the differece of there hieghts
		if(diff>1 || diff<-1){//checks if magnitude of difference is greater then 1
	    	node=rotate(node);//if so then calls the rotate method on node;
		}
		else {
		if(node->parent!=NULL) avlBalance(node->parent);//else if, while node's parent is not equal to NULL, recuscively call avlBalance() on the parent node
		else return node;// else return the node
	}
}

Node* insertNode(Node* root,Node* node){//inserts a new node to the binary search tree and calls for AVL balance to balance the tree
	if(node->key>=root->key){//if value of node is greater then equal to root, then insert the number in the right subtree
		if(root->rightChild==NULL){//if rightchild is NULL, then insert the node here and increament the height of the parent
			root->rightChild=node;//assign new node to the right child of parent
			node->parent=root;//and make parent the parent of node
			root->height++;// increment height of parent
			return avlBalance(node);//call for Avl balance to balance the tree, passing the new node as starting point
		} else	{if(root->height-root->rightChild->height<=1) root->height++;// if parent hieght is more then 1, then the insertion is happening in the smaller subtree,
		                                                                    // and so don't increase the hieght of the root,else increase parent hieght by 1
		insertNode(root->rightChild,node);//recusively call insertNode funtion with right child as root, till parent's right child is null
	}
	}
	else {//else insert the number in the left subtree
		if(root->leftChild==NULL){//if leftchild is NULL, then insert the node here and increament the height of the parent
			root->leftChild=node;//assign new node to the left child of parent
			node->parent=root;//and make parent the parent of node
			root->height++;// increment height of parent
			return avlBalance(node);//call for Avl balance to balance the tree, passing the new node as starting point
		} else {if(root->height-root->leftChild->height<=1) root->height++;// if parent hieght is more then 1, then the insertion is happening in the smaller subtree,
		                                                                    // and so don't increase the hieght of the root,else increase parent hieght by 1
		insertNode(root->leftChild,node);//recusively call insertNode funtion with right child as root, till parent's right child is null
	}
	}
}
void inorder(Node* root){//does an inorder tranversal of the binary AVL search tree and displays the Node's Key and node's height
	if(root->leftChild!=NULL) //if root's leftchild is not NULL
	inorder(root->leftChild);//recursively calls inorder function with the roots leftchild
	cout<<"Node's Value = "<<root->key<<"   "<<"Node's Height = "<<root->height<<"\n";//and dispays the value of the node from the function stack
	if(root->rightChild!=NULL)//if root's rightchild is not NULL
	   inorder(root->rightChild);//recursively calls inorder function with the roots rightchild
}

Node* NodeMaker(int value){//this function takes the value of the node of a tree and returns a node of the tree with that value
	Node* node=new Node;//create a new node
	node->key=value;//assign the node the value
	node->height=0;//initialize the height to 0
	node->leftChild=NULL;//initialize the leftChild to NULL
	node->parent=NULL;//initialize the parent to NULL
	node->rightChild=NULL;//initialize the rightChild to NULL
	return node; //return node
}

int main(int argc, char** argv) {
	Node* root; // the root node
	cout<<"-----------------After Inserting 7----------------\n";// separater to the insertions
	root=NodeMaker(7);//initializing the root node
	inorder(root);//does an inorder traversal of the binary tree
	cout<<"-----------------After Inserting 9----------------\n";// separater to the insertions
	root=insertNode(root,NodeMaker(9));//initializing a new node and passes it to the insertNode function, 
	                                   //which inserts the new node in the binary tree and then balances the tree and return the new root
	inorder(root);	//does an inorder traversal of the binary tree
	cout<<"-----------------After Inserting 13----------------\n";// separater to the insertions
	root=insertNode(root,NodeMaker(13));//initializing a new node and passes it to the insertNode function, 
	                                   //which inserts the new node in the binary tree and then balances the tree and return the new root	
	inorder(root);   //does an inorder traversal of the binary tree
	cout<<"-----------------After Inserting 21----------------\n";// separater to the insertions	
	root=insertNode(root,NodeMaker(21));//initializing a new node and passes it to the insertNode function, 
	                                   //which inserts the new node in the binary tree and then balances the tree and return the new root	
	inorder(root);   //does an inorder traversal of the binary tree
	cout<<"-----------------After Inserting 34----------------\n";// separater to the insertions
	root=insertNode(root,NodeMaker(34));//initializing a new node and passes it to the insertNode function, 
	                                   //which inserts the new node in the binary tree and then balances the tree and return the new root
	inorder(root);   //does an inorder traversal of the binary tree
	cout<<"-----------------After Inserting 36----------------\n";// separater to the insertions
	root=insertNode(root,NodeMaker(36));//initializing a new node and passes it to the insertNode function, 
	                                   //which inserts the new node in the binary tree and then balances the tree and return the new root
	inorder(root);//does an inorder traversal of the binary tree
	cout<<"-----------------After Inserting 45----------------\n";// separater to the insertions
	root=insertNode(root,NodeMaker(45));//initializing a new node and passes it to the insertNode function, 
	                                   //which inserts the new node in the binary tree and then balances the tree and return the new root
	inorder(root);//does an inorder traversal of the binary tree
	cout<<"-----------------After Inserting 54----------------\n";// separater to the insertions
	root=insertNode(root,NodeMaker(54));//initializing a new node and passes it to the insertNode function, 
	                                   //which inserts the new node in the binary tree and then balances the tree and return the new root	
	inorder(root);//does an inorder traversal of the binary tree
	cout<<"-----------------After Inserting 65----------------\n";// separater to the insertions
	root=insertNode(root,NodeMaker(65));//initializing a new node and passes it to the insertNode function, 
	                                   //which inserts the new node in the binary tree and then balances the tree and return the new root	
	inorder(root);//does an inorder traversal of the binary tree
	cout<<"-----------------After Inserting 87----------------\n";// separater to the insertions
	root=insertNode(root,NodeMaker(87));//initializing a new node and passes it to the insertNode function, 
	                                   //which inserts the new node in the binary tree and then balances the tree and return the new root
	inorder(root);//does an inorder traversal of the binary tree
}

