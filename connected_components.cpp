#include "disjoint_set.h"
#include "graph.h"
#include <iostream>

void connected_components(graph& g,vector<set*>& vs)
{
	for(int i=1;i<=g.get_number();++i)
		make_set(vs,i);
	for(int u=1;u<=g.get_number();++u)
	{
		for(int v=u;v<=g.get_number();++v)
		{
			if(g.get(u-1,v-1)!=0)
			{
				if(find_set(vs,u)&&find_set(vs,v))
				{
					if(find_set(vs,u)->head->key!=find_set(vs,v)->head->key)
					set_union(vs,u,v);
				}
			}
		}
	}
}

bool same_component(vector<set*> vs,int u,int v)
{
	if(find_set(vs,u)->head->key==find_set(vs,v)->head->key)
		return true;
	return false;
}

int main()
{
	int array[]={  0,1,1,0,0,0,0,0,0,0,
		           1,0,1,1,0,0,0,0,0,0,
				   1,1,0,0,0,0,0,0,0,0,
				   0,1,0,0,0,0,0,0,0,0,
	               0,0,0,0,0,1,1,0,0,0,
				   0,0,0,0,1,0,0,0,0,0,
				   0,0,0,0,1,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,1,0,
				   0,0,0,0,0,0,0,1,0,0,
				   0,0,0,0,0,0,0,0,0,0
	};
	graph g(array,10,10);
	vector<set*> vs;
	connected_components(g,vs);
	print(vs);

	char c;
	cin>>c;
	return 0;
}
