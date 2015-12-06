#include <iostream>
using namespace std;

template<class T>
class queue
{
public:
  queue();
  ~queue();
  T dequeue();
  bool empty(); 
  void enqueue(T data); 
  void print();
private:
  int capacity;
  int size;
  T* items;
  int front;
  int end; 

};

template<class T>
queue<T>::queue()
{
	capacity=4;
	items=new T[capacity];
	size=0;
	front=0;
	end=0;
}

template <class T>
queue<T>::~queue()
{
	delete[] items;
}

template <class T>
void queue<T>::enqueue(T data)
{
	if(size>=capacity)
	{
		capacity=2*capacity;
		T* new_area=new T[capacity];
		for(int i=0;i<size;++i)
		{
			new_area[i]=items[front];
			front=(front+1)%capacity;
		}
		delete[] items;
		items=new_area;
		front=0;
		end=size;
	}
	 	items[end]=data;
		size++;
		end=(end+1)%capacity;
		int k=0;
}

template <class T>
T queue<T>::dequeue()
{
	if(size>0)
	{
		T temp=items[front];
		front++;
		size--;
		return temp;
	}
	else
	{
		cout<<"empty stack";
        return 0; 
	}
}

template <class T>
void queue<T>::print()
{
 for(int i=front;i<end;i=(i+1)%capacity)
 {
	 cout<<items[i]<<"  ";
 }
 cout<<endl;

}

template <class T>
bool queue<T>::empty()
{
	return size>0;
} 

int main()
{
	queue<int> si;
    for(int i=1;i<6;++i)
		si.enqueue(i);
	si.print();
	si.dequeue();
	si.dequeue();
	si.enqueue(7);
	si.print();
	return 0;
}
