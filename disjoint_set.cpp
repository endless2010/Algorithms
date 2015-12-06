#include <iostream>
#include <algorithm>
#include "disjoint_set.h"
//using namespace std;

set_node::set_node(int c,set_node* f,set_node* n)
{
	key=c;
	flag=f;
	next=n;
}


set::set(set_node* h,set_node* t, int s)
{
	head=h;
	tail=t;
	size=s;
}

set* make_set(vector<set*>& vs,int c)
{
    set* new_set=new set(0,0,1);
	set_node* new_node=new set_node(c,0,0);
	new_node->flag=new_node;
	new_set->head=new_node;
	new_set->tail=new_node;
	vs.push_back(new_set);
	return new_set;
}

set* find_set(vector<set*>& vs,int c)
{
  set_node* temp;
 for(int i=0;i<vs.size();++i)
 {
	 temp=vs[i]->head;
     while(temp)
	 {
		 if(temp->key==c)
		     return vs[i];
		temp=temp->next;
	 } 

 }
 return 0;
}

void set_union(vector<set*>& vs,int c1,int c2)
{
  set* sc1=find_set(vs,c1);
  set* sc2=find_set(vs,c2);
  sc1->tail->next=sc2->head;
  for(int i=0;i<sc2->size;++i)
  {
	  sc2->head->flag=sc1->head;
	  sc2->head=sc2->head->next;
  }
  sc1->size+=sc2->size; 
  sc1->tail=sc1->tail->next;
  vs.erase(find(vs.begin(),vs.end(),sc2),find(vs.begin(),vs.end(),sc2)+1);
}

void print(vector<set*>& vs)
{
	typedef vector<set*>::const_iterator vsci;
	int count=1;
    for(vsci vci=vs.begin();vci!=vs.end();++vci)
	{
		cout<<"set"<<count++<<" "<<(*vci)->size<<" elements: ";
     set_node* temp=(*vci)->head; 
	 while(temp)
	 {
		 cout<<temp->key<<" ";
         temp=temp->next;
	 }
	 cout<<endl;
	}

}

/*
int main()
{
	    vector<set*> vs;
		set* s1=make_set(vs,0);
		set* s2=make_set(vs,1);
		set* s3=make_set(vs,2);
        set* s4=make_set(vs,3);
	    set* s5=make_set(vs,4);
		set_union(vs,0,1);
		set_union(vs,2,3);
		print(vs);
		cout<<find_set(vs,0)->head->key<<endl;
		cout<<find_set(vs,1)->head->key<<endl;
		cout<<find_set(vs,2)->head->key<<endl;
		cout<<find_set(vs,3)->head->key<<endl;
		cout<<find_set(vs,4)->head->key<<endl;
	return 0;
}
*/