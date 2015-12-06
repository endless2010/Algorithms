#include <iostream>
#include <list>

#include "graph.h"
using namespace std;

int* d;
int* p;
const int null=10000;
const int max=10000;
void initialize_single_source(graph& g,int s)
{
	int number=g.get_number(); 
	d=new int[number];
	p=new int[number];
	for(int i=0;i<number;++i)
	{
      *(d+i)=max;
	  *(p+i)=null;
	}
	*(d+s)=0;
}

void relax(graph& g,int u,int v)
{
	int du=*(d+u);
	int dv=*(d+v);
    if(dv>du+g.get(u,v))
	{
		*(d+v)=*(d+u)+g.get(u,v);
		*(p+v)=u;
	}
}

int extract_min(list<int>& Q)
{
	typedef list<int>::iterator lci;
	int min=10000;
	int index=0;
	lci min_iter;
	for(lci lici=Q.begin();lici!=Q.end();++lici)
	{
      if(*(d+(*lici))<min)
	  {
		  min=*(d+(*lici));
		  min_iter=lici;
	      index=*lici;
	  }
	}
	Q.erase(min_iter);
	return index;
}
void dijkstra(graph& g,int s)
{
  int number=g.get_number();
 initialize_single_source(g,s);
 list<int> S;
 list<int> Q;
 for(int i=0;i<number;++i)
	 Q.push_back(i);
 while(!Q.empty())
 {
	 int u=extract_min(Q);
	 S.push_back(u);
	 graph_node* temp=*(g.get_adj()+u);
	 while(temp)
	 {
       relax(g,u,temp->key);
	   temp=temp->next;
	 }
 }
}

void print_path(graph& g,int s,int v)
{
	if(v==s)
		cout<<s<<" ";
	else if(*(p+v)==max)
		cout<<s<<" ";
	else
	{
		print_path(g,s,*(p+v));
	    cout<<v<<" ";
	}
}

int main()
{
int array[]={  0,10,max,max,5,
		       max,0,1,max,2,
			   max,max,0,4,max,
			   7,max,6,0,max,
			   max,3,9,2,0 };
	graph g(array,5,5);
	dijkstra(g,0);
    for(int i=0;i<g.get_number();++i)
		cout<<*(d+i)<<" ";
	cout<<endl;
    
	cout<<"path: ";
	print_path(g,0,0);
	cout<<endl;
	print_path(g,0,1);
	cout<<endl;
	print_path(g,0,2);
	cout<<endl;
	print_path(g,0,3);
	cout<<endl;
  	print_path(g,0,4);
	char c;
	cin>>c;
	return 0;
}
