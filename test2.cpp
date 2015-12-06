#include <iostream>
#include <queue>
#include <stack>

using namespace std;


int main()
{
	queue<int> q;
	stack<int> s;
	for(int i=0;i<5;++i)
	{
		s.push(5-i);
		q.push(5-i);
	}
    
	for(int j=0;j<5;++j)
	{
		cout<<q.front()<<" ";
		q.pop();
	}
   
	cout<<endl;

	for(int k=0;k<5;++k)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}