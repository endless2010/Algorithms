#include <vector>

class Matrix
{
  public:
   Matrix(int r,int c,int initial=0);
   int get(int i,int j); 
   void show();
   void set(int i,int j,int val);
  private:
	 int row;
	 int col;
	 std::vector<int*> v;
};
