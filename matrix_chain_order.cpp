#include <iostream>
#include <vector>
using namespace std;

const int max=100000;

void matrix_chain_order(int* p,int length,vector<int*>& s)
{
	int n=length-1;
    vector<int*> m(n+1);
	for(int i=0;i<=n;++i)
	{
		m[i]=new int[n+1];
		s[i]=new int[n+1];
		m[i][i]=0;
	}
    for(int l=2;l<=n;++l)
	{
		for(int i=1;i<=n-l+1;++i)
		{
			int j=i+l-1;
			m[i][j]=max;
			for(int k=i;k<j;++k)
			{
				int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}

void print_optimal_parens(vector<int*>& s,int i,int j)
{
	if(i==j)
		cout<<"A"<<i;
	else
	{
		cout<<"(";
		print_optimal_parens(s,i,s[i][j]);
		print_optimal_parens(s,s[i][j]+1,j);
		cout<<")";
	}
}

int main()
{
	int p[]={30,35,15,5,10,20,25};
	int length=sizeof(p)/sizeof(*p);
	vector<int*> s(length);
	matrix_chain_order(p,length,s);
	print_optimal_parens(s,1,6);

	char c;
	cin>>c;
	return 0;
}