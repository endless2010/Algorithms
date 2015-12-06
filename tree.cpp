#include <iostream>
#include <queue> 
#include <string>
using namespace std;

template <class T>
struct tree_node
{
		T data;
   		tree_node* left;
    	tree_node* right;
		tree_node(T d,tree_node* l=NULL,tree_node* r=NULL)
		{
			data=d;
			left=l;
			right=r; 
		}
}
;

template <class T>
void preorder(tree_node<T>* root)
{
	if(root!=NULL)
	{
       cout<<root->data<<"  ";
	   preorder(root->left);
	   preorder(root->right);
	}
}

template <class T>
void inorder(tree_node<T>* root)
{
	if(root!=NULL)
	{
	   inorder(root->left);
       cout<<root->data<<"  ";
	   inorder(root->right);
	}
}
 
template <class T>
void postorder(tree_node<T>* root)
{
	if(root!=NULL)
	{
	   postorder(root->left);
	   postorder(root->right);
	   cout<<root->data<<"  ";
	}
}

template <class T>
tree_node<T>* copy(tree_node<T>* root)
{
	tree_node<T>* result=NULL;
	if(root!=NULL)
	{
      result=new tree_node<T>(root->data);
	  result->left=copy(root->left);
	  result->right=copy(root->right);
	}
	return result;
}

template <class T>
void clear(tree_node<T>* root)
{
	if(root!=NULL)
	{
		clear(root->left);
		clear(root->right);
		delete root;
		root=NULL;
	}
}

template <class T>
void level_order(tree_node<T>* root)
{
  queue<tree_node<T>*> q;
  q.push(root);
  while(!q.empty())
  {
	  tree_node<T>* t=q.front();
	  q.pop();
	   if(t!=NULL)
	  {
		  cout<<t->data<<"  ";
		  q.push(t->left);
		  q.push(t->right);
	  }
  }
}

template <class K,class V>
struct bstree_node
{
	K key;
	V value;
	bstree_node* left;
	bstree_node* right;
	bstree_node* parent;
	bstree_node(K k,V v,bstree_node<K,V>* l=NULL,bstree_node<K,V>* r=NULL,bstree_node<K,V>* p=NULL)
	{
		key=k;
		value=v;
		parent=p;
		left=l;
		right=r;
	}
};

template <class T,class V>
void inorder1(bstree_node<T,V>* root)
{
	if(root!=NULL)
	{
	   inorder1(root->left);
       cout<<root->value<<"  ";
	   inorder1(root->right);
	}
}

template <class K,class V>
V find(bstree_node<K,V>* root,const K& key)
{
	if(root==NULL)
		return 0;
	if(root->key==key)
     return root->value;
	else if(root->key>key)
	return find(root->left,key);
	else return find(root->right,key);
 
}

template <class K,class V>
void insert(bstree_node<K,V>* &root,const K& key,const V& value)
{
	if(root==NULL)
	{
		root=new bstree_node<K,V>(key,value); 
		return;
	}
	if(root->key==key)
		return;
	else if(root->key<key)
		insert(root->right,key,value);
	else
		insert(root->left,key,value);
}

template <class K,class V>
void no_child_remove(bstree_node<K,V>* &root,bstree_node<K,V>* &parent)
{
	if(parent->left==root)
	parent->left=NULL;
	else
	parent->right=NULL;

	delete root;
	root=NULL;
}

template <class K,class V>
void one_child_remove(bstree_node<K,V>* &root,bstree_node<K,V>* &parent)
{
     bstree_node<K,V>* temp=root;
    if(temp->left!=NULL)
		temp=temp->left;
	else
		temp=temp->right;
    if(parent->left==root)
     parent->left=temp;
	else
     parent->right=temp;
     delete root;
}

template <class K,class V>
void two_child_remove(bstree_node<K,V>* &root)
{
	bstree_node<K,V>* lmax=root->left;
	if(lmax==NULL)
		lmax=root;
	else while(lmax->right!=NULL)
		lmax=lmax->right;
	cout<<lmax->key<<endl;
	root->key=lmax->key;
	root->value=lmax->value;
    if(lmax->parent->left==lmax)
		lmax->parent->left=NULL;
	else 
		lmax->parent->right=NULL;
	delete lmax;
}

template <class K,class V>
void remove(bstree_node<K,V>* &root)
{
	if((root->left==NULL)&&(root->right==NULL))
		no_child_remove<K,V>(root,root->parent);
    else if((root->left!=NULL)&&(root->right!=NULL))
		two_child_remove<K,V>(root);
	else
		one_child_remove<K,V>(root,root->parent);
}

int main()
{
/*
 tree_node<char> d('d');
 tree_node<char> e('e');
 tree_node<char> f('f');
 tree_node<char> b('b',&d,&e);
 tree_node<char> c('c',&f);
 tree_node<char> a('a',&b,&c);
 */
 bstree_node<int,string>* f=new bstree_node<int,string>(12,"12");
 bstree_node<int,string>* g=new bstree_node<int,string>(37,"37");
 bstree_node<int,string>* d=new bstree_node<int,string>(10,"10",NULL,f);
 bstree_node<int,string>* e=new bstree_node<int,string>(25,"25",NULL,g);
 bstree_node<int,string>* b=new bstree_node<int,string>(13,"13",d,e);
 bstree_node<int,string>* c=new bstree_node<int,string>(51,"51");
 bstree_node<int,string>* a=new bstree_node<int,string>(38,"38",b,c); 
 //cout<<find(&a,25)<<endl;
 f->parent=d;
 g->parent=e;
 e->parent=b;
 d->parent=b;
 b->parent=a;
 c->parent=a;
/*
 insert<int,string>(a,11,"11");
 insert<int,string>(a,8,"8");
 inorder1<int,string>(a);
 cout<<endl;
*/
//remove<int,string>(pd);
  remove<int,string>(a);
  inorder1<int,string>(a);
 /*
 preorder<char>(&a);
 cout<<endl;
 inorder<char>(&a);
 cout<<endl;
 postorder<char>(&a);
 cout<<endl;
 tree_node<char>* tc=copy(&a);
 inorder(tc);
 */
 /*
 tree_node<char>* tc=copy(&a);
 clear(tc);
 cout<<tc->data<<endl;
 */
// inorder(&a);
  return 0;
}

