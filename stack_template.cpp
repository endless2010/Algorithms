#include <iostream>
using namespace std;

template<class T>
class stack
{
public:
  stack();
  ~stack();
  T top();
  void pop();
  bool empty(); 
  void push(T data); 
private:
  int capacity;
  int size;
  T* items;

};

template<class T>
stack<T>::stack()
{
	capacity=8;
	items=new T[capacity];
	size=0;
}

template <class T>
stack<T>::~stack()
{
	delete[] items;
}

template <class T>
void stack<T>::push(T data)
{
	if(size<capacity)
	{
		items[size]=data;
	    size++; 
	}
	else
	{
		cout<<"array out of bound"<<endl; 
	}
}

template <class T>
T stack<T>::top()
{
	if(size>0)
     return items[size-1];
	else
	{
		cout<<"empty stack";
        return -1; 
	}
}

template <class T>
void stack<T>::pop()
{
	if(size>0)
		size--;
}

template <class T>
bool stack<T>::empty()
{
	return size>0;
}
int main()
{
	stack<int> si;
	si.push(4);
	si.push(5);
	si.push(6);
    cout<<si.top()<<endl;
	si.pop();
	cout<<si.top()<<endl;
	cout<<boolalpha<<si.empty()<<endl;
	return 0;
}
  