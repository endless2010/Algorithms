class graph_node 
{
public:
	int key;
	graph_node* next;
	graph_node(int k,graph_node* n=0);  
};

class graph
{
public:
    graph(int n);
	graph(int* array,int row,int col);
	~graph();
	 int get(int i,int j);
     void print(bool show_matrix=true);
	 bool is_directed(){return directed;}
     int get_number(){return number;}
	 graph_node** get_adj(){return adj;}
private:
	int number;
	int* matrix;
	bool directed;
	graph_node** adj;
	void build_adj();
};	