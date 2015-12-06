#include <iostream>
using namespace std;

//union by size and height
template <class T>
class set4
{
public:
	set4(int n);
	~set4();
	void unionset(const T& k1,const T& k2);
	void show();
	void path_compression();
private:
	int get_root();
   T* elems;
   int num;
};

template <class T>
set4<T>::set4(int n)
{
	num=n;
	elems=new T[n];
	for(int i=0;i<n;++i)
    elems[i]=-1;
}

template <class T>
set4<T>::~set4()
{
	if(elems)
		delete[] elems;
}

//union by size
template <class T>
void set4<T>::unionset(const T& k1,const T& k2)
{
	   elems[k1]+=elems[k2];
       elems[k2]=k1;


}

template <class T>
void set4<T>::show()
{
	for(int i=1;i<num;++i)
		cout<<elems[i]<<"  ";
	cout<<endl;
}

template <class T>
int set4<T>::get_root()
{
	for(int i=0;i<num;++i)
	{
		if(elems[i]<-1)
			return i;
	}
	return -1;
}
template <class T>
void set4<T>::path_compression()
{
  for(int i=0;i<num;++i)
  {
	  if(elems[i]>=0)
	  {
		  int parent=elems[i];
		  if(elems[parent]>=0)
          elems[parent]=get_root();
	  }
  }
}
int main()
{
	set4<int> s2(12);
	s2.unionset(4,5);
	s2.unionset(4,6);
	s2.unionset(2,4);
	s2.unionset(2,3);
	s2.unionset(7,2);
	s2.unionset(7,8);
	s2.unionset(9,7);
	s2.unionset(9,1);
	s2.unionset(10,9);
	s2.unionset(10,11);

	s2.show();
    s2.path_compression();
	s2.show();

	return 0;
}
