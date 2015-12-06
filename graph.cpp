#include <iostream>
#include <string>
#include "graph.h"
using namespace std;

graph_node::graph_node(int k,graph_node* n)
{
	key=k;
	next=n;
}

class error
{
public:
	error(string s)
	{
		err=s;
	}
	string what()
	{
		return err;
	}
	string err;
};


int graph::get(int i,int j)
{
	return *(matrix+i*number+j);
}
void graph::build_adj()
{
   adj=new graph_node*[number];
   graph_node* tail;
   for(int i=0;i<number;++i)
   {
	   tail=0;
	   for(int j=0;j<number;++j)
	   {
	      if(get(i,j)!=0)
		  {
		    graph_node* new_node=new graph_node(j);
		    if(!tail)
			{
			  *(adj+i)=new_node;
			  tail=new_node;
			}
		    else
			{
		    tail->next=new_node;
			tail=new_node;
			}
		  }
	   }
   }
}

graph::graph(int n)
{
 number=n;
 directed=false;
 matrix=new int[n*n];
 for(int i=0;i<n*n;++i)
	 *(matrix+i)=0;
 build_adj();
}

graph::graph(int* array,int row,int col)
{
	if(row!=col)
		error("row and col must be the same value");
	number=row;
	directed=false;
    matrix=array;
	build_adj();
}

graph::~graph()
{
	if(matrix)
		delete[] matrix;
}

void graph::print(bool show_matrix)
{
  if(show_matrix)
  {
  if(!matrix)
	  return;
  for(int i=0;i<number*number;++i)
  { 
    cout<<*(matrix+i)<<" ";
	if((i+1)%number==0)
		cout<<endl;
  }
  cout<<endl;
  }
  else
  {
	  for(int i=0;i<number;++i)
	  {
		  graph_node* temp=*(adj+i);
		  while(temp)
		  {
			  cout<<temp->key<<" ";
			  temp=temp->next;
		  }
		  cout<<endl;
	  }
	  cout<<endl;
  }
}


int main()
{
	int array[]={  0,1,0,0,5,
		           1,0,4,1,1,
				   0,4,0,1,0,
				   0,1,1,0,1,
				   5,1,0,1,0 };
	graph g(array,5,5);
	g.print();
	g.print(false);

	char c;
	cin>>c;
	return 0;
}
