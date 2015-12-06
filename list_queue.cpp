#include <iostream>
using namespace std;

template <class T>
class queue
{
public:
	queue();
	void enqueue(T new_data);
	T dequeue();
	void print();
private:
	struct queue_node
	{
		T data;
		queue_node* next;
		queue_node(T new_data,queue_node* n):data(new_data),next(n){}
	};
	queue_node* entry;
	queue_node* exit;
	int size;
};

template <class T>
queue<T>::queue()
{
	entry=NULL;
	exit=NULL;
	size=0;
}

template <class T>
void queue<T>::enqueue(T new_data)
{
	queue_node* new_node=new queue_node(new_data,NULL);
	
	if(entry!=NULL)
		entry->next=new_node;
	else
		entry=new_node;
	entry=new_node;
	if(exit==NULL)
		exit=new_node;
	size++;
}

template <class T>
T queue<T>::dequeue()
{
	queue_node* temp=exit;
	if(temp!=NULL)
	   {
		exit=exit->next;
		return temp->data;
	}
	return 0;
}

template <class T>
void queue<T>::print()
{
	queue_node* temp=exit;
	while(temp!=NULL)
	{
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	queue<int> qi;
	for(int i=1;i<6;++i)
		qi.enqueue(i);
	qi.print();
	qi.dequeue();
	qi.dequeue();
	qi.print();
	return 0;
}
