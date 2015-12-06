#include <iostream>

void counting_sort(int* A,int* B,int k)
{
   int* C=new int[k];
   *B=*A;
   for(int i=0;i<k;++i)
	   *(C+i)=0;

   for(int j=1;j<=A[0];++j)
       ++C[A[j]];

   for(int t=1;t<k;++t)
	   C[t]=C[t]+C[t-1];


   for(i=A[0];i>0;--i)
   {
	   B[C[A[i]]]=A[i];
	   --C[A[i]];
   }

}

int main()
{
	using namespace std;
	int A[]={8,2,5,3,0,2,3,0,3};
	int B[9];
	counting_sort(A,B,6);
	for(int i=1;i<=B[0];++i)
		cout<<B[i]<<" ";
	cout<<endl;
    
	char c;
	cin>>c;
	return 0;
}