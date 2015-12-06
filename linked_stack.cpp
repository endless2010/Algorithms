#include <iostream>
using namespace std;

template <class T>
class stack
{
	public:
	stack();
	// ~stack();
	void push(T newData);
	void pop();
	T top(); 
	bool empty() const;
	int size() const;
	void print();
	private:
		struct stack_node
		{
			T data;
			stack_node* next;
			stack_node(T newData,stack_node* n):data(newData),next(n){}
		};
		int the_size;
	stack_node* the_top;
};

template <class T>
void stack<T>::pop()
{
	the_top=the_top->next;
	the_size--;
}

template <class T>
int stack<T>::size() const
{
	return the_size;
}

template <class T>
bool stack<T>::empty() const
{
	return the_size==0;
}

template<class T>
stack<T>::stack()
{
	the_size=0;
	the_top=NULL;
}

template <class T>
void stack<T>::push(T newData)
{
	stack_node* new_node=new stack_node(newData,NULL);
	new_node->next=the_top;
	the_top=new_node;
	the_size++;
}

template <class T>
T stack<T>::top()
{
  	if(the_top!=NULL)
     return the_top->data; 	
	else return -1;
}

template <class T>
void stack<T>::print()
{
	stack_node* temp=the_top;
 while(temp!=NULL)
 {
	 cout<<temp->data<<"  ";
	 temp=temp->next;
 }
 cout<<endl;
}

int main()
{
	stack<int> si;
	si.push(4);
	si.push(6);
	si.push(8);
	si.print();
	si.pop();
    si.pop();
	si.print();
	return 0;
}
