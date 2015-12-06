#include<iostream>
#include<vector>
using namespace std;

void FASTEST_WAY(vector<int*>& a,vector<int*>& t,int* e,int* x,int n,vector<int*>& L,int& f_star,int& l_star)
{
	vector<int*> f(2);
	f[0]=new int[n+1]();
	f[1]=new int[n+1]();
	L[0]=new int[n+1]();
	L[1]=new int[n+1]();

	f[0][1]=*e+a[0][1];
	f[1][1]=*(e+1)+a[1][1];
	for(int j=2;j<=n;++j)
	{
		if(f[0][j-1]<=(f[1][j-1]+t[1][j-1]))
		{
			f[0][j]=f[0][j-1]+a[0][j];
			L[0][j]=1; 
		}
		else
		{
			f[0][j]=f[1][j-1]+t[1][j-1]+a[0][j];
			L[0][j]=2; 
		}
		if(f[1][j-1]<=(f[0][j-1]+t[0][j-1])) 
		{
			f[1][j]=f[1][j-1]+a[1][j];
			L[1][j]=2;
		}
		else
		{
			f[1][j]=f[0][j-1]+t[0][j-1]+a[1][j];
			L[1][j]=1;
		}
	}
	int x1=(*x);
	int x2=(*(x+1));
	if((f[0][n]+x1)<=(f[1][n]+x2))
	{
		f_star=f[0][n]+x1;
		l_star=1;
	}
	else
	{
		f_star=f[1][n]+x2;
		l_star=2;
	}
}

void print_station(vector<int*>& L,int l_star,int n)
{
	int i=l_star;
	cout<<"line "<<i<<" ,station "<<n<<endl;
	for(int j=n;j>1;--j)
	{
		i=L[i-1][j];
		cout<<"line "<<i<<" ,station "<<j-1<<endl;
	}
}

int main()
{
	vector<int*> a(2);
	vector<int*> t(2);
     int a0[]={0,7,9,3,4,8,4};
	 int a1[]={0,8,5,6,4,5,7};
	 a[0]=a0;
	 a[1]=a1;
     int t0[]={0,2,3,1,3,4};
	 int t1[]={0,2,1,2,2,1};
	 t[0]=t0;
	 t[1]=t1;
	 int e[]={2,4};
	 int x[]={3,2};
	 int n=6;
	 vector<int*> L(2);
	 int f_star;
	 int l_star;

     FASTEST_WAY(a,t,e,x,n,L,f_star,l_star);
     print_station(L,l_star,n);
    // for(int i=0;i<7;++i)
	//	 cout<<L[0][i]<<" "<<L[1][i]<<endl;
	 char c;
	cin>>c;
	return 0;
}