#include <vector>
using namespace std;
class set_node
{
public:
	int key;
    set_node* flag;
	set_node* next;
	set_node(int c,set_node* f,set_node* n);
};

class set
{
public:
	set_node* head;
	set_node* tail;
    int size;
	set(set_node* h,set_node* t, int s);
};

set* make_set(vector<set*>& vs,int c);
set* find_set(vector<set*>& vs,int c);
void set_union(vector<set*>& vs,int c1,int c2);
void print(vector<set*>& vs);