#include <iostream>
#include "matrix.h"
using namespace std;

Matrix::Matrix(int r,int c,int initial)
{
	row=r;
	col=c;
    v.resize(r);
	for(int i=0;i<v.size();++i)
		v[i]=new int[c];
	for(i=0;i<v.size();++i)
		for(int j=0;j<c;++j)
			v[i][j]=initial; 
}

inline Matrix::get(int i,int j)
{
	return v[i-1][j-1];
}

void Matrix::show()
{
	for(int i=0;i<v.size();++i)
	{
		for(int j=0;j<col;++j)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
}

inline void Matrix::set(int i,int j,int val)
{
	v[i-1][j-1]=val;
}
int main()
{
    Matrix m(2,4,3);
	m.set(1,2,1);
	m.show();
	return 0;
}