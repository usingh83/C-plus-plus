#include <iostream>

#include <stdexcept>
#include <exception>

using namespace std;
class err : runtime_error
{
public:
    err() : runtime_error("") { }
//        ^^^^^^^^^^^^^^^^^^^^^^^^
};

template <typename E>
class ArrayStack{
	enum{
		DEF_CAPACITY=500
	};
	public:
	ArrayStack(int cap=DEF_CAPACITY);
	int size() const; 
	bool empty() const;
	void push(const E& e);
	const E& top() const ;
	void pop() ;
	private:
		E* S;
		int capacity;
		int t;			
};
template <typename E> ArrayStack<E>::ArrayStack(int cap){ S=(new E[cap]);
 capacity=(cap); t=(-1); } // constructor from capacity
template <typename E> int ArrayStack<E>::size() const
{ return (t + 1); } 
template <typename E> // push element onto the stack
void ArrayStack<E>::push(const E& e)  { if (size() == capacity){try{
err x;
throw x;
}
catch (err x){
	cout<<"full";
}
}
S[++t] = e;
}
template <typename E> bool ArrayStack<E>::empty() const
{ return (t < 0); } // is the stack empty?
template <typename E>
const E& ArrayStack<E>::top() const  { if (empty()) ;
return S[t];
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
B.push("Eve");
B.push("Eve");
B.push("Eve");
B.push("Eve");
B.push("Eve");
B.push("Eve");
B.push("Eve");
B.push("Eve");
B.push("Eve");
B.push("Eve");
B.push("Eve");
B.push("Eve");	
 }
