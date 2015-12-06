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
  void print();
private:
  int capacity;
  int size;
  T* items;

};

template<class T>
stack<T>::stack()
{
	capacity=4;
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
     if(size>=capacity)
	    {
		 T* new_area=new T[2*capacity];
		for(int i=0;i<size;++i)
			new_area[i]=items[i];
	    delete[] items;
		items=new_area;
	}
	 	items[size]=data;
		size++;
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
void stack<T>::print()
{
 for(int i=0;i<size;++i)
 {
	 cout<<items[i]<<"  ";
 }
 cout<<endl;

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
	si.push(7);
    si.print();
	si.push(8);
	si.print();
	si.pop();
    si.print();
	return 0;
}
