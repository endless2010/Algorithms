#include <iostream>
using namespace std;

void insertion_sort(int *h,const int length)
{
	for(int j=1;j<length;++j)
	{
		int key=h[j];
		int i=j-1;
		while(i>=0&&(h[i]>key))
		{
			h[i+1]=h[i];
			--i;
		}
		h[i+1]=key;
	}
}

void print_array(const int *h,const int length)
{
	for(int i=0;i<length;++i)
		cout<<h[i]<<"  ";
	cout<<endl;
}
int main()
{
	int a[]={5,10,8,4,7,9,2,3,17,6};
	
	cout<<"-----before sort-----"<<endl; print_array(a,sizeof(a)/sizeof(*a));
	insertion_sort(a,sizeof(a)/sizeof(*a));
	cout<<"-----after sort-----"<<endl; print_array(a,sizeof(a)/sizeof(*a));
	
	char c;
	cin>>c;
	return 0;
}