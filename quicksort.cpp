#include <iostream>

int partition(int* A,int p,int r)
{
	int x=A[r];
	int i=p-1;
	for(int j=p;j<r;++j)
	{
		if(A[j]<=x)
		{
			++i;
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	int temp=A[i+1];
	A[i+1]=A[r];
	A[r]=temp;

	return i+1;
}

void quicksort(int* A,int p,int r)
{
	if(p<r)
	{
		int q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}

int main()
{
	using namespace std;
	int A[]={2,8,7,1,3,6,5,4,9,0};
	quicksort(A,0,sizeof(A)/sizeof(*A)-1);
    for(int i=0;i<sizeof(A)/sizeof(*A);++i)
		cout<<A[i]<<" ";
	cout<<endl;

	char c;
	cin>>c;
	return 0;
}