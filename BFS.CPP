#include "graph.h"
#include <iostream>
#include <queue>
using namespace std;

const int max=10000;

  int* color;
  int* d;
  int* p;

void BFS(graph& g,int s)
{
  int n=g.get_number();
  color=new int[n];
  d=new int[n];
  p=new int[n];
  for(int i=0;i<n;++i)
  {
	 *(color+i)=1;
     *(d+i)=max;
     *(p+i)=max;
  }
 *(color+s)=2;
 *(d+s)=0;
 queue<int> Q;
 Q.push(s);
 while(!Q.empty())
 {
	 int u=Q.front();
	 Q.pop();
	 graph_node* temp=*(g.get_adj()+u);
	 while(temp)
	 {
		 //cout<<temp->key <<endl;
		 if(*(color+temp->key)==1)
		 {
			 *(color+temp->key)=2;
			 *(d+temp->key)=*(d+u)+1;
			 *(p+temp->key)=u;
			 Q.push(temp->key);
		 }
		 temp=temp->next;
	 }
	 *(color+u)=0;
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
	int array[]={  0,1,0,0,1,
		           1,0,1,1,1,
				   0,1,0,1,0,
				   0,1,1,0,1,
				   1,1,0,1,0 };
	graph g(array,5,5);
	 int n=g.get_number();
	BFS(g,0);
	//print_path(g,0,4);
	for(int i=0;i<n;++i)
		cout<<*(color+i)<<" ";
	cout<<endl;
	for(int j=0;j<n;++j)
		cout<<*(d+j)<<" ";
	cout<<endl;
	for(int k=0;k<n;++k)
		cout<<*(p+k)<<" ";
	cout<<endl;
print_path(g,0,3);
	char c;
	cin>>c;
	return 0;
}
