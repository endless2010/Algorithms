#include <iostream>

inline int left(int i)
{
  return i+i;
}

inline int right(int i)
{
	return i+i+1;
}

inline int parent(int i)
{
	return i/2;
}

void max_heapify(int* A,int i)
{
  int l=left(i);
  int r=right(i);
  int largest=i;
  if(l<=A[0]&&A[l]>A[i])
	  largest=l;
  if(r<=A[0]&&A[r]>A[largest])
	  largest=r;
  if(largest!=i)
  {
	  int temp=A[i];
	  A[i]=A[largest];
	  A[largest]=temp;
	  max_heapify(A,largest);
  }
}


int main()
{
	using namespace std;
    int A[]={10,16,4,10,14,7,9,3,2,8,1};
	cout<<"before max_heapify(A,2) :";
	for(int i=1;i<sizeof(A)/sizeof(*A);++i)
	    cout<<A[i]<<" ";
	cout<<endl;
	max_heapify(A,2);
	cout<<"after max_heapify(A,2) :";
	for(i=1;i<sizeof(A)/sizeof(*A);++i)
		cout<<A[i]<<" ";
	cout<<endl;
	char c;
	cin>>c;
	return 0;
}





