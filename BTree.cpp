#include <iostream>
using namespace std;

template <class T>
struct BTree_node
{
	BTree_node(int m,bool is_leaf=false);
	~BTree_node();
	BTree_node** child;
	T* key;
	int numkeys;
	bool leaf;
};

template <class T>
BTree_node<T>::BTree_node(int m,bool is_leaf)
{
	numkeys=m;
	key=new T[m];
	if(!is_leaf)
	child=new BTree_node*[m+1];
	else
	child=NULL;
    leaf=is_leaf;
}

template <class T>
BTree_node<T>::~BTree_node()
{
	if(key)
		delete key;
	if(child)
		delete child;
}

template <class T>
bool search(BTree_node<T>& x,T key)
{
	int i=0;
	while((i<x.numkeys)&&(key>x.key[i]))
	{
		cout<<x.key[i]<<endl;
		i++;
	}
    if(x.leaf==true)
		return false;
	else
	{
		BTree_node<T>* b=x.child[i];
		return search<T>(*b,key);
	}
}

int main()
{
	BTree_node<int> n1(1);n1.key[0]=17;
    BTree_node<int> n2(2);n2.key[0]=3;n2.key[1]=8;
	BTree_node<int> n3(2);n3.key[0]=28;n3.key[1]=48;
	BTree_node<int> n4(2,true);n4.key[0]=1;n4.key[1]=2;
	BTree_node<int> n5(2,true);n5.key[0]=6;n5.key[1]=7;
    BTree_node<int> n6(3,true);n6.key[0]=12;n6.key[2]=14;n6.key[2]=16;
	BTree_node<int> n7(2,true);n7.key[0]=25;n7.key[1]=26;
	BTree_node<int> n8(2,true);n8.key[0]=29;n8.key[1]=45;
	BTree_node<int> n9(4,true);n9.key[0]=52;n9.key[1]=53;n9.key[2]=55;n9.key[3]=68;
	n1.child[0]=&n2;	n1.child[1]=&n3;
	n2.child[0]=&n4;	n2.child[1]=&n5;	n2.child[2]=&n6;
	n3.child[0]=&n7;	n3.child[1]=&n8;	n3.child[2]=&n9;
	search<int>(n1,55);
	return 0;
}