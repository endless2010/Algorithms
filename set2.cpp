#include <iostream>
using namespace std;

//uptrees
template <class T>
class set2
{
public:
	set2(int n);
	~set2();
	void unionset(const T& k1,const T& k2);
	T findset(const T& k);
	void show();
private:
   T* elems;
   int num;
};

template <class T>
set2<T>::set2(int n)
{
	num=n;
	elems=new T[n];
	for(int i=0;i<n;++i)
    elems[i]=-1;
}

template <class T>
set2<T>::~set2()
{
	if(elems)
		delete[] elems;
}

template <class T>
void set2<T>::unionset(const T& k1,const T& k2)
{
   elems[k2]=k1;
}

template <class T>
T set2<T>::findset(const T& k)
{
  if(elems[k]<0) return k;
  else
	  return findset(elems[k]);
}

template <class T>
void set2<T>::show()
{
	for(int i=0;i<num;++i)
		cout<<elems[i]<<"  ";
	cout<<endl;
}
/*
int main()
{
	set2<int> s2(4);
	s2.unionset(0,1);
	s2.show();
	s2.unionset(2,3);
	s2.show();
	for(int i=0;i<4;++i)
		cout<<s2.findset(i)<<" ";
	cout<<endl;
    s2.unionset(s2.findset(1),s2.findset(3));
	s2.show();
	return 0;
}
*/