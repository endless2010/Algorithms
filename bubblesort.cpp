#include <iostream>

void bubblesort(int *A,int length)
{
	for(int i=0;i<length;++i)
	{
		for(int j=length-1;j>i;--j)
		{
			if(A[j]<A[j-1])
			{
				int temp=A[j];
				A[j]=A[j-1];
				A[j-1]=temp;
			}
		}
	}
}

int main()
{
	using namespace std;
	
	int A[]={5,2,4,7,1,3,2,6};
	bubblesort(A,sizeof(A)/sizeof(*A));
    for(int i=0;i<sizeof(A)/sizeof(*A);++i)
		cout<<*(A+i)<<" ";
	cout<<endl;

	char c;
	cin>>c;
	return 0;
}