#include <iostream>

void maxmin(int* A,int length,int* max,int *min)
{
	int start=0;
	if(length%2==0)
	{
		if(A[0]>A[1])
		{
			*max=A[0];
			*min=A[1];
		}
		else
		{
			*max=A[1];
			*min=A[0];
		}
		start=2;
	}
	else
	{
	   
		*max=1;
	    *min=1;
        start=1;
	}
	int temp_max=0;
	int temp_min=0;
	for(int i=start;i<length-1;i+=2)
	{
      if(A[i]>A[i+1])
	  {
		  temp_max=A[i];
		  temp_min=A[i+1];
	  }
	  else
	  {
		  temp_max=A[i+1];
		  temp_min=A[i];
	  }

	  if(*max<temp_max)
		  *max=temp_max;
	  if(*min>temp_min)
		  *min=temp_min;
	}
}

int main()
{
	using namespace std;
	int A[]={2,3,4,1,3,0,4,5};
	int max;
	int min;
     maxmin(A,sizeof(A)/sizeof(*A),&max,&min);
	cout<<"Max: "<<max<<endl;
	cout<<"Min: "<<min<<endl;
	
    return 0;
}