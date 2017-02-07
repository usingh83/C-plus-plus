#include <iostream>

using namespace std;


template <typename E>
class ArrayStack { 
enum { 
DEF_CAPACITY = 100 
}; // default stack capacity
public:
ArrayStack(int cap = DEF_CAPACITY); // constructor from capacity
int size() const; // number of items in the stack
bool empty() const; // is the stack empty?
const E& top() const ; // get the top element
void push(const E& e) ; // push element onto stack
void pop() ; // pop the stack
// . . .housekeeping functions omitted
private: // member data
E* S; // array of stack elements
int capacity; // stack capacity
int t; // index of the top of the stack
};
template <typename E> ArrayStack<E>::ArrayStack(int cap)
: S(new E[cap]), capacity(cap), t(-1) { } // constructor from capacity
template <typename E> int ArrayStack<E>::size() const
{ return (t + 1); } // number of items in the stack
template <typename E> bool ArrayStack<E>::empty() const
{ return (t < 0); } // is the stack empty?
template <typename E> // return top of stack
const E& ArrayStack<E>::top() const  { if (empty()) ;
return S[t];
}
template <typename E> // push element onto the stack
void ArrayStack<E>::push(const E& e)  { if (size() == capacity) ;
S[++t] = e;
}
template <typename E> // pop the stack
void ArrayStack<E>::pop()  { if (empty()) ;
--t;
}

int main()
{
	ArrayStack<int> A; // A = [ ], size = 0
A.push(7); // A = [7*], size = 1
A.push(13); // A = [7, 13*], size = 2
cout << A.top() << endl; A.pop(); // A = [7*], outputs: 13
A.push(9); // A = [7, 9*], size = 2
cout << A.top() << endl; // A = [7, 9*], outputs: 9
cout << A.top() << endl; A.pop(); // A = [7*], outputs: 9
ArrayStack<string> B(10); // B = [ ], size = 0
B.push("Bob"); // B = [Bob*], size = 1
B.push("Alice"); // B = [Bob, Alice*], size = 2
cout << B.top() << endl; B.pop(); // B = [Bob*], outputs: Alice
B.push("Eve");
	
 } 
