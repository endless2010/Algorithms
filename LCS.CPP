#include <iostream>
#include <string>
#include <vector>
using namespace std;

void lcs_length(string& x,string& y,vector<int*>& b)
{
	int m=x.length();
	int n=y.length();
	vector<int*> C(m+1);
    for(int i=0;i<C.size();++i)
		C[i]=new int[n+1];
	for(i=0;i<=m;++i)
		C[i][0]=0;

	for(int j=0;j<=n;++j)
		C[0][j]=0;
	for(j=0;j<=m;j++)
		b[j]=new int[n+1];
	for(j=0;j<b.size();++j)
		for(int i=0;i<=n;++i)
			b[j][i]=0;
	for(i=1;i<=m;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(x.at(i-1)==y.at(j-1))
			{
				b[i][j]=1;
				C[i][j]=C[i-1][j-1]+1;
			}
			else if(C[i-1][j]>=C[i][j-1])
			{
				C[i][j]=C[i-1][j];
				b[i][j]=2;
			}
			else
			{
				C[i][j]=C[i][j-1];
				b[i][j]=3;
			}
		}
	}

}

void print_lcs(vector<int*>& b,string& x,int i,int j)
{
	if(i==0||j==0)
		return;
	if(b[i][j]==1)
	{
		print_lcs(b,x,i-1,j-1);
		cout<<x.at(i-1)<<" ";
	}
	else if(b[i][j]==2)
		print_lcs(b,x,i-1,j);
	else
	print_lcs(b,x,i,j-1);
}
int main()
{
	string X="ABCBDAB";
	string Y="BDCABA";
	vector<int*> b(X.length()+1);
	lcs_length(X,Y,b);
	print_lcs(b,X,7,6);

	char c;
	cin>>c;
	return 0;
}