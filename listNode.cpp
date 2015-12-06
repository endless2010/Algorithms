#include <iostream>
using namespace std;

template <class T>
struct listNode
{
T data;
listNode* next;
listNode(T newData)
{
  data=newData;
  next=NULL;
}
};

template <class T>
void insert_front(listNode<T>* &curr,T newData)
{
  listNode<T>* temp=new listNode<T>(newData);
  temp->next=curr;
  curr=temp;

}

template <class T>
void print(listNode<T>* head)
{
 while(head) 
 {
	 cout<<head->data<<"   ";
	 head=head->next;
 }
 cout<<endl;

}

template <class T>
void print_reverse(listNode<T>* head)
{
	 if(head)
	 {
		 print_reverse(head->next);
		 cout<<head->data<<"   ";
	 }
}

template <class T> 
listNode<T>* find_kth_position(listNode<T>* head,int k)
{
	for(int i=1;i<k;++i)
    head=head->next;
	return head; 
}

template <class T>
void insert_kth_position_back(listNode<T>* p,int k,T newData)
{
	listNode<T>* temp=find_kth_position(p,k);
	listNode<T>* ln=new listNode<T>(newData);
	ln->next=temp->next;
	temp->next=ln; 
}

template <class T>
void insert_kth_position_front(listNode<T>* p,int k,T newData)
{
	listNode<T>* prior=find_kth_position(p,k-1);
	listNode<T>* newNode=new listNode<T>(newData);
	newNode->next=prior->next;
	prior->next=newNode;
}

/
int main()
{
	listNode<int>* ln=new listNode<int>(4);
	ln->next=new listNode<int>(8);
	insert_front<int>(ln,7);
	insert_front<int>(ln,9);
    
	//cout<<find_kth_position(ln,1)->data<<endl;
	print(ln);
    insert_kth_position_back(ln,3,6);
	print(ln);
	insert_kth_position_front(ln,4,1);
	print(ln);
	//print_reverse(ln);
	return 0;
}

 