#include <iostream>
#include "graph.h"

using namespace std;

const int null=10000;
const int max=10000;
int time=0;
int* color;
int* pi;
int* d;
int* f;

void print_path(graph& g,int s,int v)
{
	if(v==s)
		cout<<s<<" ";
	else if(*(pi+v)==null)
		cout<<s<<" ";
	else
	{
		print_path(g,s,*(pi+v));
	    cout<<v<<" ";
	}
}

void DFS_VISIT(graph& g,int u)
{
	*(color+u)=2;
	++time;
	*(d+u)=time;
	graph_node* temp=*(g.get_adj()+u);
	while(temp)
	{
		if(*(color+temp->key)==1)
		{
			*(pi+temp->key)=u;
		    DFS_VISIT(g,temp->key);
		}
		temp=temp->next;
	}
	*(color+u)=0;
	*(f+u)=++time;
}
void DFS(graph& g)
{
	int number=g.get_number();
    color=new int[number];
    pi=new int[number];
    d=new int[number];
	f=new int[number];

	for(int i=0;i<number;++i)
	{
		*(pi+i)=null;
		*(color+i)=1;
	}
	for(int u=0;u<number;++u)
	{
		if(*(color+u)==1)
			DFS_VISIT(g,u);
	}
 
}

int main()
{
	int array[]={  0,1,0,1,0,0,
		           0,0,0,0,1,0,
				   0,0,0,0,1,1,
				   0,1,0,0,0,0,
				   0,0,0,1,0,0,
				   0,0,0,0,0,1
	};
	graph g(array,6,6);
	DFS(g);
    for(int i=0;i<g.get_number();++i)
		cout<<*(d+i)<<" "<<*(f+i)<<" "<<*(color+i)<<endl;
	char c;
	cin>>c;
	return 0;
}
