#include <iostream>
using namespace std;

template <class T>
class set1
{
public:
	set1(int n);
	~set1();
	void makeset(const T& k);
	void unionset(const T& k1,const T& k2);
	T findset(const T& k);
private:
   T* elems;
   int num;
};

template <class T>
set1<T>::set1(int n)
{
	num=n;
	elems=new T[n];
	for(int i=0;i<n;++i)
    elems[i]=-i;
}

template <class T>
set1<T>::~set1()
{
	if(elems)
		delete[] elems;
}

template <class T>
void set1<T>::makeset(const T& k)
{
	elems[k]=k;
}

template <class T>
void set1<T>::unionset(const T& k1,const T& k2)
{
	T s1=findset(k1);
	T s2=findset(k2);
	if(s1!=s2)
	{
		for(int i=0;i<num;++i)
		{
			if(elems[i]==s2)
			elems[i]=s1;
		}
	}
}

template <class T>
T set1<T>::findset(const T& k)
{
  return elems[k];
}

/*
int main()
{
 set1<int> s1(8);
 s1.makeset(0);
 s1.makeset(2);
 s1.makeset(3);
 s1.unionset(0,1);
 s1.unionset(0,4);
 s1.unionset(2,7);
 s1.unionset(3,5);
 s1.unionset(3,6);
// s1.unionset(4,2);

 for(int i=0;i<8;++i)
	 cout<<s1.findset(i)<<"  ";
 cout<<endl;

 return 0;
}
*/
