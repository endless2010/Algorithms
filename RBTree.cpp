#include <iostream>
#include <list>
using namespace std;

const bool RED=true;
const bool BLACK=false;

template <class T>
struct RBTree_node
{
	RBTree_node* parent;
	RBTree_node* left;
	RBTree_node* right;
	bool color;        //red: true; black: false.
	T key;
    RBTree_node(T k,RBTree_node* l=NULL,RBTree_node* r=NULL,bool c=BLACK);
};

template <class T>
RBTree_node<T>::RBTree_node(T k,RBTree_node* l,RBTree_node* r,bool c)
{
	key=k;
	color=c;
	parent=NULL;
	left=l;
	right=r;
}

template <class T>                  // level-order travel
void show(RBTree_node<T>* root)
{
	list<RBTree_node<T>* >lst;
	lst.push_back(root);
	RBTree_node<T>* right_most=root;
	while(lst.size())
	{
		RBTree_node<T>* temp=lst.front();
        cout<<temp->key<<"-";
		if(temp->color)
			cout<<"red"<<" ";
		else
			cout<<"black"<<" ";
		if(right_most==temp)
		{
			cout<<endl;
			right_most=right_most->right;
		}
		if(temp->left)
			lst.push_back(temp->left);
		if(temp->right)
			lst.push_back(temp->right);
		lst.pop_front();
	}
	cout<<endl<<endl;
}

template <class T>
void left_rotate(RBTree_node<T>* root,RBTree_node<T>* x)
{
	RBTree_node<T>* y=x->right;
	x->right=y->left;
	if(y->left)
		y->left->parent=x;
	y->parent=x->parent;
	if(x->parent==NULL)
		root=y;
	else if(x==x->parent->left)
		x->parent->left=y;
	else 
		x->parent->right=y;
	y->left=x;
	x->parent=y;
}

template <class T>
void right_rotate(RBTree_node<T>* &root, RBTree_node<T>* x)
{
	RBTree_node<T>* y=x->left;
	x->left=y->right;
	if(y->right)
		y->right->parent=x;
	y->parent=x->parent;
	if(x->parent==NULL)
		root=y;
	else if(x==x->parent->left)
		x->parent->left=y;
	else 
		x->parent->right=y;
	y->right=x;
	x->parent=y;
}

template <class T>
void RB_insert_fixup(RBTree_node<T>* &root,RBTree_node<T>* z)
{
	RBTree_node<T>* y=NULL;
	while(z->parent->color==RED)
	{
		if(z->parent==z->parent->parent->left)
		{
			y=z->parent->parent->right;
			if(y->color==RED)
			{
				z->parent->color=BLACK;
				y->color=BLACK;
				z->parent->parent->color=RED;
				z=z->parent->parent;
			}
			else 
			{
				if(z=z->parent->right)
				{
					z=z->parent;
					left_rotate(root,z);
				}
				z->parent->color=BLACK;
				z->parent->parent->color=RED;
				right_rotate(root,z->parent->parent);
			}
		}
		else
		{
			y=z->parent->parent->left;
			if(y->color==RED)
			{
				z->parent->color=BLACK;
				y->color=BLACK;
				z->parent->parent->color=RED;
				z=z->parent->parent;
			}
			else 
			{
				if(z=z->parent->left)
				{
					z=z->parent;
					right_rotate(root,z);
				}
				z->parent->color=BLACK;
				z->parent->parent->color=RED;
				left_rotate(root,z->parent->parent);
			}
		}
	}
	root->color=BLACK;
}

template <class T>
void RB_insert(RBTree_node<T>* &root,RBTree_node<T>* z)
{
	RBTree_node<T>* y=NULL;
	RBTree_node<T>* x=root;
	while(x)
	{
		y=x;
		if(z->key<x->key)
			x=x->left;
		else
			x=x->right;
	}
	z->parent=y;
	if(y==NULL)
		root=z;
	else if(z->key<y->key)
		y->left=z;
	else
		y->right=z;
	z->color=true;
	RB_insert_fixup(root,z);
}

template <class T> 
RBTree_node<T>* tree_maximum(RBTree_node<T>* x)
{
  while(x->right!=0)
	  x=x->right;
  return x;
}

template <class T>
RBTree_node<T>* tree_minimum(RBTree_node<T>* x)
{
	while(x->left!=0)
		x=x->left;
	return x;
}

template <class T>
RBTree_node<T>* Tree_successor(RBTree_node<T>* x)
{
		if(x->right!=0)
		return tree_minimum(x->right);
		RBTree_node<T>* y=x->parent;
	   while(y!=0&&x==y->right)
	   {
		   x=y;
		   y=x->parent;
	   }
	   return y;
}

template <class T>
void RB_delete_fixup(RBTree_node<T>* root,RBTree_node<T>* x)
{
	RBTree_node<T>* w;
	while(x!=root&&x->color==BLACK)
	{
		if(x==x->parent->left)
		{
			w=x->parent->right;
			if(w->color==RED)
			{
				w->color=BLACK;
				x->parent->color=RED;
				left_rotate(root,x->parent);
				w=x->parent->right;
			}
			if((w->left->color==BLACK)&&(w->right->color=BLACK))
			{
				w->color=RED;
				x=x->parent;
			}
			else 
			{
				if(w->right->color==BLACK)
				{
					w->left->color=BLACK;
					w->color=RED;
					right_rotate(root,w);
					w=x->parent->right;
				}
				w->color=x->parent->color;
				x->parent->color=BLACK;
				w->right->color=BLACK;
				left_rotate(root,x->parent);
				x=root;
			}
		}
		else
		{
			w=x->parent->left;
			if(w->color==RED)
			{
				w->color=BLACK;
				x->parent->color=RED;
				right_rotate(root,x->parent);
				w=x->parent->left;
			}
			if((w->left->color==BLACK)&&(w->right->color=BLACK))
			{
				w->color=RED;
				x=x->parent;
			}
			else 
			{
				if(w->left->color==BLACK)
				{
					w->right->color=BLACK;
					w->color=RED;
					left_rotate(root,w);
					w=x->parent->left;
				}
				w->color=x->parent->color;
				x->parent->color=BLACK;
				w->left->color=BLACK;
				right_rotate(root,x->parent);
				x=root;
			}
		}
	}
	x->color=BLACK;
}

template <class T>
void RB_delete(RBTree_node<T>* &root,RBTree_node<T>* z)
{
	RBTree_node<T>* x;
	RBTree_node<T>* y;
	if(z->left==NULL||z->right==NULL)
		y=z;
	else
		y=Tree_successor(z);
	if(y->left)
		x=y->left;
	else
		x=y->right;
	if(x)
	x->parent=y->parent;
	if(y->parent==NULL)
		root=x;
	else if(y==y->parent->left)
		y->parent->left=x;
	else
		y->parent->right=x;
	if(y!=z)
		z->key=y->key;
	if(y->color==BLACK)
		RB_delete_fixup(root,x);
}

int main()
{
	typedef RBTree_node<int> node;
/*
	node* root1;
	RBTree_node<int> node2(2),node3(3,&node2),node6(6),node4(4,&node3,&node6);
	RBTree_node<int> node12(12),node17(17),node14(14,&node12,&node17),node20(20);
	RBTree_node<int> node22(22,&node20),node19(19,NULL,&node22),node18(18,&node14,&node19);
	RBTree_node<int> node9(9),node11(11,&node9,&node18),node7(7,&node4,&node11);
	node2.parent=&node3;node3.parent=&node4;node4.parent=&node7;node6.parent=&node4;
	node12.parent=&node14;node17.parent=&node14;node14.parent=&node18,node9.parent=&node18;
	node11.parent=&node7,node20.parent=&node22;node22.parent=&node19,node19.parent=&node18;
	node18.parent=&node11;
	root1=&root7;
*/
//	show(&node7);
//	right_rotate(&node7,&node4);
//	show(&node7);
	node new_node(4);
//	RB_insert(&node7,&new_node);
//	show(&node7);
	node node1(1,NULL,NULL,BLACK),node5(5,NULL,NULL,RED);
	node node8(8,NULL,NULL,RED),node7(7,&node5,&node8,BLACK),node2(2,&node1,&node7,RED);
	node node15(15,NULL,NULL,RED),node14(14,NULL,&node15,BLACK),node11(11,&node2,&node14,BLACK);
	node1.parent=&node2;node5.parent=&node7;node8.parent=&node7;
	node7.parent=&node2;node15.parent=&node14;node2.parent=&node11;node14.parent=&node11;
	node* root2=&node11;
	//show(root2);
	//right_rotate(root2,&node11);
	//show(root2);
	RB_insert(root2,&new_node);
	show(root2);
	RB_delete(root2,&node11);
	show(root2);
	return 0;
}


