#include <iostream>
#include <string>
using namespace std;

class error
{
public:
	error(string err)
	{
		error_string=err;
	}
	string what()
	{
		return error_string;
	}
private:
	string error_string;
};

struct tree_node
{
	int key;
	tree_node* parent;
	tree_node* left;
	tree_node* right;
	tree_node();
	void set(int k,tree_node* p=0,tree_node* l=0,tree_node* r=0);
};

tree_node::tree_node()
{
	parent=0;
	left=0;
	right=0;
}

void tree_node::set(int k,tree_node* p,tree_node* l,tree_node* r)
{
	key=k;
	parent=p;
	left=l;
	right=r;
}
void Inorder_tree_walk(tree_node* x)
{
	if(x!=0)
	{
		Inorder_tree_walk(x->left);
        cout<<x->key<<" ";
		Inorder_tree_walk(x->right);
	}
}

tree_node* tree_search(tree_node* x,int k)
{
	while(x!=0&&k!=x->key)
	{
		if(k<x->key)
		    x=x->left;
		else
			x=x->right;
	}
	if(x!=0)
	return x;
	else
	{
		throw error("cannot find ");
		return 0;
	}
}

tree_node* tree_maximum(tree_node* x)
{
  while(x->right!=0)
	  x=x->right;
  return x;
}

tree_node* tree_minimum(tree_node* x)
{
	while(x->left!=0)
		x=x->left;
	return x;
}

tree_node* tree_successor(tree_node* x)
{
	if(x->right!=0)
		return tree_minimum(x->right);
       tree_node* y;
	   if(x->key!=tree_maximum(x)->key)
		    y=x->parent;
	   else
	   {
		   throw error("no successor!");
		   return 0;
	   }
	   while(y!=0&&x==y->right)
	   {
		   x=y;
		   y=x->parent;
	   }
	   return y;
}

void tree_insert(tree_node* root,tree_node* z)
{
   tree_node* y=0;
   tree_node* x=root;
   while(x!=0)
   {
	   y=x;
	   if(x->key<z->key)
		   x=x->right;
		else x=x->left;
   }
   z->parent=y;
   if(y==0)
	   root=z;
   else if(z->key<y->key)
	   y->left=z;
   else y->right=z;
}

tree_node* tree_delete(tree_node* root,tree_node* z)
{
	tree_node* y;
	if(z->left==0||z->right==0)
		y=z;
	else y=tree_successor(z);
    tree_node* x;
	if(y->left!=0)
		 x=y->left;
	else x=y->right;

	if(x!=0)
		x->parent=y->parent;
	if(y->parent==0)
		root=x;
    else if(y->key==y->parent->left->key)
		y->parent->left=x;
	else y->parent->right=x;
	if(y->key !=z->key )
		z->key =y->key;
	return y;
}

int main()
{
  tree_node node1,node2,node3,node4,node5,node6;
  node1.set(5,0,&node2,&node3);
  node2.set(3,&node1,&node4,&node5);
  node3.set(7,&node1,0,&node6);
  node4.set(2,&node2,0,0);
  node5.set(5,&node2,0,0);
  node6.set(8,&node3,0,0);
  Inorder_tree_walk(&node1);
  try{
	  tree_node* result=tree_search(&node1,5);
      cout<<endl<<"search 5:"<<result->key<<endl;

  tree_node* max=tree_maximum(&node1);
  cout<<"max:"<<max->key<<endl;
  tree_node* min=tree_minimum(&node1);
  cout<<"min:"<<min->key<<endl;
  cout<<tree_successor(max)->key<<endl;
  }
  catch(error& err)
  {
	  cout<<err.what()<<endl;
  }
  tree_node new_node;
  new_node.set(6,0,0,0);
  tree_insert(&node1,&new_node);
  Inorder_tree_walk(&node1);
  tree_node* deleted=tree_delete(&node1,&node3);
  cout<<endl<<"the deleted one:"<<deleted->key<<endl;
  char c;
  cin>>c;
  return 0;
}

