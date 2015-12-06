#include <iostream>
#include <string>
using namespace std;

class student
{
public:
	string name;
	bool printed;
	int t;
	void f()
	{
		cout<<"student"<<endl;
	}
};

class stu:public student
{
public:
	void f()
	{
		cout<<"stu"<<endl;
	}
};

template <class T>
void swap1(T& a,T& b)
{
	T temp=a;
	a=b;
	b=temp;
}
int main()
{
  student a1;
  string n=a1.name;
  stu b1;
  student* p;
  p=&b1;
  p->f();
  int a=1;
  int b=2;
  char c='a';
  char d='b';
  swap1(a,b);
  swap1(c,d);
  cout<<a<<" "<<b<<endl;
  cout<<c<<" "<<d<<endl;
  return 0;
}
