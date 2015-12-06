#include <iostream>
using namespace std;

class Stack
{
public:
	Stack(int);
	~Stack();
	bool empty();
	int top();
	bool push(int);
	int pop();
	void clear();
	
private:
	int max;
	int top_element;
	int* rep;
};

Stack::Stack(int i)
{
	rep=new int[i];
	max=i;
	top_element=-1;
}

Stack::~Stack()
{
	if(rep)
		delete[] rep;
}

inline bool Stack::empty()
{
	return top_element==-1;
}

inline int Stack::top()
{
		return top_element;
}

inline bool Stack::push(int i)
{
  if((top_element+1)==max)
	 return false;
  ++top_element;
  rep[top_element]=i;
  
  return true;
}

inline int Stack::pop()
{
	if(top_element==-1)
		return -1;
	--top_element;
	return rep[top_element];
}

inline void Stack::clear()
{
top_element=-1;
}
int main()
{
	Stack stack(7);
	stack.push(15);
	stack.push(6);
	stack.push(2);
	stack.push(9);
	cout<<"top :"<<stack.top()<<endl;
	stack.pop();
	cout<<"top: "<<stack.pop()<<endl;
	stack.pop();
	stack.pop();
	cout<<boolalpha<<stack.empty()<<endl;

	char c;
	cin>>c;
	return 0;
}