#include <iostream>

class Queue
{
public:
	Queue(int);
	~Queue();
	void Enqueue(int);
	int Dequeue();

private:
    int length;
	int* rep;
	int head;
	int tail;
};

Queue::Queue(int i)
{
	rep=new int[i];
	length=i;
	head=tail=0;
}

Queue::~Queue()
{
	if(rep)
		delete[] rep;
}

void Queue::Enqueue(int i)
{
   rep[tail]=i;
   if(tail==(length-1))
     tail=0;
	else
	++tail;
}

int Queue::Dequeue()
{
	int x=rep[head];
	if(head==(length-1))
		head=0;
	else
		++head;
	return x;
}

int main()
{
	using namespace std;
	Queue queue(3);
	queue.Enqueue(2);
	queue.Enqueue(3);
    queue.Enqueue(4);
	cout<<queue.Dequeue()<<endl;
	cout<<queue.Dequeue()<<endl;
	cout<<queue.Dequeue()<<endl;

	char c;
	cin>>c;
	return 0;
}