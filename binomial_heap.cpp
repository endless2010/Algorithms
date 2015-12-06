#include <iostream>
#include <list>
using namespace std;

template <class T>
struct binomial_tree_node
{
	binomial_tree_node<T>* parent;
    T key;
	int degree;
	binomial_tree_node<T>* child;
	binomial_tree_node<T>* sibling;
	binomial_tree_node(T the_key,int the_degree=0,binomial_tree_node<T>* p=NULL);
};

template <class T>
binomial_tree_node<T>::binomial_tree_node(T the_key,int the_degree,binomial_tree_node<T>* p)
{
	key=the_key;
	parent=p;
	child=NULL;
	sibling=NULL;
	degree=the_degree;
}

template <class T>
void _show(binomial_tree_node<T>* H)
{
	list<binomial_tree_node<T>* >lst;
	lst.push_back(H);
	while(lst.size())
	{
		binomial_tree_node<T>* temp=lst.front();
        cout<<temp->key<<" ";
		if(temp->degree)
		{
			binomial_tree_node<T>* pc=temp->child;
			lst.push_back(pc);
		    for(int i=0;i<temp->degree-1;++i)
			{
				lst.push_back(pc->sibling);
				pc=pc->sibling;
			}
		}
		lst.pop_front();
	}
	cout<<endl;
}

template <class T>
void show(binomial_tree_node<T>* H)
{
	while(H)
	{
		_show(H);
		H=H->sibling;
	}
	cout<<endl;
}

template <class T>
binomial_tree_node<T>* binomial_heap_minimum(binomial_tree_node<T>* H)
{
	binomial_tree_node<T>* y=NULL;
	binomial_tree_node<T>* x=H;
	T min=10000;
	while(x!=NULL)
	{
		if(x->key<min)
		{
			min=x->key;
			y=x;
		}
		x=x->sibling;
	}
	return y;
}

template <class T>
void binomial_link(binomial_tree_node<T>* y,binomial_tree_node<T>* z)
{
	y->parent=z;
	y->sibling=z->child;
	z->child=y;
	z->degree++;
}

template <class T>
binomial_tree_node<T>* binomial_heap_merge(binomial_tree_node<T>* H1,binomial_tree_node<T>* H2)
{
	binomial_tree_node<T>* H=NULL;
	binomial_tree_node<T>* pH=NULL;
	if(H1->degree<=H2->degree)
	{
		H=H1;
		H1=H1->sibling;
	}
	else
	{
		H=H2;
		H2=H2->sibling;
	}
	pH=H;
	while(H1&&H2)
	{
		if(H1->degree<=H2->degree)
		{
			pH->sibling=H1;
			pH=H1;
			H1=H1->sibling;
		}
		else
		{
			pH->sibling=H2;
			pH=H2;
			H2=H2->sibling;
		}
	}
	if(H1)
		pH->sibling=H1;
	else
		pH->sibling=H2;
	return H;
}

template <class T>
binomial_tree_node<T>* binomial_heap_union(binomial_tree_node<T>* H1,binomial_tree_node<T>* H2)
{
	binomial_tree_node<T>* H=binomial_heap_merge(H1,H2);
	H1=NULL;
	H2=NULL;
	if(!H)
		return H;
	binomial_tree_node<T>* prev=NULL;
    binomial_tree_node<T>* x=H;
	binomial_tree_node<T>* next=x->sibling;
	while(next)
	{
		if((x->degree!=next->degree)||((next->sibling!=NULL)&&(next->sibling->degree==x->degree)))
		{
			prev=x;
			x=next;
		}
		else if(x->key<=next->key)
		{
			x->sibling=next->sibling;
			binomial_link(next,x); 
		}
		else if(prev==NULL)
			H=next;
		else 
		{
			prev->sibling=next;
			binomial_link(x,next);
			x=next;
		}
		next=x->sibling;
	}
   return H;
}

template <class T>
void binomial_heap_insert(binomial_tree_node<T>* &H,T x)
{
	binomial_tree_node<T>* node=new binomial_tree_node<T>(x);
	H=binomial_heap_union(H,node);
}

template <class T>
void binomial_heap_extract_min(binomial_tree_node<T>* &H)
{
   binomial_tree_node<T>* x=binomial_heap_minimum(H);
   binomial_tree_node<T>* temp=H;
   while(temp&&temp->sibling&&(temp->sibling->key!=x->key))
	   temp=temp->sibling;
   temp->sibling=temp->sibling->sibling;
 
   if(!x)
		return;
    binomial_tree_node<T>* H1=x->child;
	binomial_tree_node<T>* p=H1;
	binomial_tree_node<T>* q=p->sibling;
	while(q)
	{
		p->sibling=q->sibling;
		q->sibling=H1;
		H1=q;
		q=p->sibling;
	}
	H=binomial_heap_union(H,H1);
}

template <class T>
void binomial_decrease_key(binomial_tree_node<T>* H,binomial_tree_node<T>* x,T key)
{
	if(key>x->key)
		return;
	x->key=key;
	binomial_tree_node<T>* y=x;
	binomial_tree_node<T>* z=y->parent;
	while(z&&y->key<z->key)
	{
		T temp=y->key;
		y->key=z->key;
		z->key=temp;
		y=z;
		z=y->parent;
	}
}

template <class T>
void binomial_heap_delete(binomial_tree_node<T>* &H,binomial_tree_node<T>* x)
{
	 binomial_decrease_key(H,x,-100);
	 show(H);
	 binomial_heap_extract_min(H);
}

int main()
{
	typedef  binomial_tree_node<int> node;
	node node12(12);
	node node7(7,1),node25(25,0,&node7);
	node node15(15,2),node28(28,1,&node15),node33(33,0,&node15),node41(41,0,&node28);
	node12.sibling=&node7;node7.sibling=&node15;node28.sibling=&node33;
	node7.child=&node25;node15.child=&node28;node28.child=&node41;
	node* H1=&node12;
	/*
	show(H1);
	node* min=binomial_heap_minimum(H1);
	cout<<"H1 min:"<<min->key<<endl;
	cout<<endl;
	*/
	node node18(18);
	node node3(3,1),node37(37,0,&node3);
	node18.sibling=&node3,node3.child=&node37;
	node node6(6,4);
	node node8(8,3,&node6),node29(29,2,&node6),node10(10,1,&node6),node44(44,0,&node6);
	node node30(30,2,&node8),node23(23,1,&node8),node22(22,0,&node8);
	node node48(48,1,&node29),node31(31,0,&node29),node17(17,0,&node10);
	node node45(45,1,&node30),node32(32,0,&node30),node24(24,0,&node23),node50(50,0,&node48);
	node node55(55,0,&node45);
	node3.child=&node37;node6.child=&node8;node8.child=&node30;node30.child=&node45;
	node45.child=&node55;node29.child=&node48;node48.child=&node50;node23.child=&node24;
	node10.child=&node17;
	node3.sibling=&node6;
	node8.sibling=&node29;node29.sibling=&node10;node10.sibling=&node44;
	node30.sibling=&node23;node23.sibling=&node22;node45.sibling=&node32;
	node48.sibling=&node31;
	node* H2=&node18;
	/*
	show(H2);
	min=binomial_heap_minimum(H2);
	cout<<"H2 min:"<<min->key<<endl;
	cout<<endl;
	*/
    node* H=binomial_heap_union(H1,H2);
	show(H);
    //binomial_heap_insert(H,20);
	//show(H2);
    //binomial_heap_extract_min(H);
	//show(H);
	//binomial_decrease_key(H,&node33,2);
    //binomial_heap_delete(H,&node37);
	//show(H);
	return 0;
}
