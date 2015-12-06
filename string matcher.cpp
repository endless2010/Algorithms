#include <iostream>
#include <string>
using namespace std;

inline bool same(string& str1,string& str2)
{
	return str1==str2;
}

void naive_string_matcher(string& T,string& P)
{
	int n=T.length();
	int m=P.length();
	for(int s=0;s<=n-m;++s)
	{
		if(same(P,T.substr(s,m)))
			cout<<"pattern occured with shift :"<<s<<endl;
	}
}
int main()
{
	string T="acaabcaab";
	string P="aab";
	naive_string_matcher(T,P);

	char c;
	cin>>c;
	return 0;
}
