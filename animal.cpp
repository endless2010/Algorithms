#include <string>
#include <list>
#include <iostream>

using namespace std;

struct animal
{
  string name;
  string food;
  bool big;
  animal(string n="tom",string f="apple",bool b=true)
  {
	  name=n;
	  food=f;
	  big=b;
  }
};

class print_if_big
{
public:
	void operator()(animal a)
	{
		if(a.big)
			cout<<a.name<<endl;
	}

};

template <class iter,class formator>
void print(iter first,iter second,formator f)
{
	while(first!=second)
	{
		f(*first);
		first++;
	}
}

/* 
int main()
{
 list<animal> la;
 animal a;
 animal b("kate");
 animal c("jack","banana",false);
 la.push_back(a);
 la.push_back(b);
 la.push_back(c);

 for(list<animal>::iterator iter=la.begin();iter!=la.end();++iter)
	 cout<<"name:"<<(*iter).name<<"  food:"<<iter->food<<"  big:"<<boolalpha<<iter->big<<endl;

 print_if_big pib;
 pib(a);

 print(la.begin(),la.end(),pib);
 return 0;
}
*/ 
