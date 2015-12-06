#include <iostream>
using namespace std;

//union by size and height
template <class T>
class set3
{
public:
	set3(int n);
	~set3();
	void unionset(const T& k1,const T& k2);
	void unionset_by_size(const T& k1,const T& k2);
	void unionset_by_height(const T& k1,const T& k2);
	T findset(const T& k);
	void show();
private:
   T* elems;
   int num;
};

template <class T>
set3<T>::set3(int n)
{
	num=n;
	elems=new T[n];
	for(int i=0;i<n;++i)
    elems[i]=-1;
}

template <class T>
set3<T>::~set3()
{
	if(elems)
		delete[] elems;
}

//union by size
template <class T>
void set3<T>::unionset(const T& k1,const T& k2)
{
	   elems[k1]+=elems[k2];
       elems[k2]=k1;


}

template <class T>
void set3<T>::unionset_by_size(const T& k1,const T& k2)
{
     if(elems[k1]>elems[k2])
		  unionset(k2,k1);
	 else
		 unionset(k1,k2);
}

template <class T>
T set3<T>::findset(const T& k)
{
  if(elems[k]<0) return k;
  else
	  return findset(elems[k]);
}

template <class T>
void set3<T>::show()
{
	for(int i=0;i<num;++i)
		cout<<elems[i]<<"  ";
	cout<<endl;
}

int main()
{
	set3<int> s2(12);
	s2.unionset(6,0);
	s2.unionset(6,1);
	s2.unionset(6,2);
	s2.unionset(8,3);
	s2.unionset(7,6);
	s2.unionset(7,8);
	s2.unionset(7,9);
	s2.unionset(5,11);
	s2.unionset(10,5);
	s2.unionset(4,10);

	s2.show();
    //s2.unionset_by_size(7,4);
	s2.unionset_by_size(4,7);
	s2.show();
	return 0;
}
