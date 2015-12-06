#include <iostream>
using namespace std;

struct list_node
{
	int key;
	list_node* prev;
	list_node* next;
	list_node(int k,list_node* p,list_node* n);
};

list_node::list_node(int k,list_node* p,list_node* n)
{
    key=k;
	prev=p;
	next=n;

}
class list
{
public:
	list_node* head();
	void set_head(list_node* new_head);
	void insert(int x);
	void list_delete(list_node* x);
	list_node* search(int k);
	list();
	void clear();
	void print();
private:
	list_node* list_head;
};

list_node* list::head()
{
	return list_head;
}

void list::set_head(list_node* new_head)
{
	list_head=new_head;
}

list::list()
{
	list_head=0;
}

void list::insert(int x)
{
	list_node* new_node=new list_node(x,0,0);
	new_node->next=head();
	if(head()!=0)
		head()->prev=new_node;
	set_head(new_node);
	new_node->prev=0;
}

list_node* list::search(int k)
{
	list_node* s=head();
	while(s&&s->key!=k)
		s=s->next;
	return s;
}

void list::list_delete(list_node* x)
{
	if(x->prev)
		x->prev->next=x->next; 
	else
		set_head(x->next);
	if(x->next)
		x->next->prev=x->prev;
}

void list::clear()
{
	list_node* c=head();
	while(c)
	{
		list_delete(c);
		c=c->next;
	}
}
void list::print()
{
	list_node* p=head();
	if(!p)
	{
		cout<<"null elements!"<<endl;
		return ;
	}
	while(p)
	{
		cout<<p->key<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	list alist;
	alist.insert(1);
	alist.insert(2);
    alist.insert(3);
	alist.insert(4);
	alist.print();
    cout<<alist.search(2)->key<<endl;
	alist.list_delete(alist.search(2));
	alist.print();
	alist.list_delete(alist.head());
	alist.print();
	alist.clear();
	alist.print();

	char c;
	cin>>c;
	return 0;
}
