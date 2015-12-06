#include <iostream>
using namespace std;

template <class T>
struct AVLTree_node
{
		T data;
		int height;
   		AVLTree_node<T>* left;
        AVLTree_node<T>* right;
		AVLTree_node(T d,int h=0,AVLTree_node* l=NULL,AVLTree_node* r=NULL)
		{
			data=d;
			height=h;
			left=l;
			right=r; 
		}
}
;

template <class T>
void preorder(AVLTree_node<T>* root)
{
	if(root!=NULL)
	{
	   cout<<root->data<<"  ";
	   preorder(root->left);
	   preorder(root->right);
	}
}

template <class T>
void left_rotate(AVLTree_node<T>* &root)
{
   AVLTree_node<T>* y=root->right;
   root->right=y->left;
   y->left=root;
   root=y;
}

template <class T>
void right_rotate(AVLTree_node<T>* &root)
{
   AVLTree_node<T>* y=root->left;
   root->left=y->right;
   y->right=root;
   root=y;
}

template <class T>
int height(AVLTree_node<T>* root)
{
	if(root==NULL)
		return 0;
	else
	{
	int hl=height(root->left);
	int hr=height(root->right);
    return (hl>hr)?(hl+1):(hr+1);
	}
}

template <class T>
void insert(AVLTree_node<T>* &t,const T& x)
{
	if(t==NULL)
		t=new AVLTree_node<T>(x);
	else if(x<t->data)
	{
		insert(t->left,x);
		int balance=height(t->right)-height(t->left);
		int left_balance=height(t->left->right)-height(t->left->left);
		if(balance==-2)
			if(left_balance==-1)
				right_rotate(t);
			else
			{
				left_rotate(t->left);
				right_rotate(t);
			}
	}
	else if(x>t->data)
	{
		insert(t->right,x);
		int balance=height(t->right)-height(t->left);
		int right_balance=height(t->right->right)-height(t->right->left);
		if(balance==2)
			if(right_balance==1)
				left_rotate(t);
			else
			{
				right_rotate(t->right);
				left_rotate(t);
			}
	}
	int hl=height(t->left);
	int hr=height(t->right);
	t->height=(hl>hr)?(hl+1):(hr+1);
}

int main()
{
  /*
  AVLTree_node<int>* na=NULL;
  insert(na,50);
  insert(na,30);
  insert(na,80);
  insert(na,20);
  insert(na,40);
  insert(na,60);
  insert(na,90);
  insert(na,60);
  insert(na,85);
  insert(na,99);
  insert(na,95);
  */
  AVLTree_node<int>* na=NULL;
  insert(na,70);
  insert(na,40);
  insert(na,80);
  insert(na,20);
  insert(na,50);
  insert(na,60);
  //preorder(na);
  //cout<<endl;
  //right_rotate(na);
  preorder(na);
  cout<<endl;
  return 0;
}

