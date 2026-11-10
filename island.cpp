// group members : long, ming, hamza
//
// Coding by long
//
// Intuitive solution
#include<vector>
using std::vector;
#include<limits>
#include<iostream>
int countIsland(vector<vector<bool>>& searched, vector<vector<int>>& grid, size_t x, size_t y);
int max(int a ,int b)
{
	return (a>b)?a:b;
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
	int maxCount = std::numeric_limits<int>::min();
	size_t colsize = grid.size();
	size_t rowsize = grid[0].size();
	vector<vector<bool>> searched(colsize,vector<bool>(rowsize,false))   ; 
	for(size_t i =0; i < colsize;i++)
	{
		for(size_t j =0; j< rowsize; j++)
		{
			if(searched[i][j])
			{
				continue;
			}
			if(grid[i][j] == 1)
			{
				maxCount = max(maxCount,countIsland(searched,grid,i,j))	;
			}
		}
	}
	if(maxCount == std::numeric_limits<int>::min()) maxCount = 0;
	return maxCount;
}
int countIsland(vector<vector<bool>>& searched, vector<vector<int>>& grid, size_t x, size_t y)
{
	// if(searched[x][y] || grid[x][y] == 0 || x>=grid.size() || y>= grid[0].size() || x<0 || y<0 )
	// {
	// 	return 0;
	// }
	// use demorgran to handle out of bound error (segmentation fault), only realized that after ran the codes with above condition
	if(!(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && !searched[x][y] && grid[x][y] ==1))
	{
		return 0; 
	}
	// std::cout<<"i:" <<x <<"\t j:" <<y <<'\n';
	int count =0;
	count+=1;
	searched[x][y]= true;
	count+= countIsland(searched,grid,x,y+1);
	count+= countIsland(searched,grid,x+1,y);
	count+= countIsland(searched,grid,x,y-1);
	count+= countIsland(searched,grid,x-1,y);
	return count;

}
int main()
{
	vector<vector<int>> g = { {0,0,0,0,0},
				  {1,1,1,1,1}};
	std::cout<< maxAreaOfIsland(g)<<'\n';
	g = {{1,1,1,0,0},
	     {0,1,1,1,0}};

	std::cout<< maxAreaOfIsland(g)<<'\n';
	vector<vector<int>> g2 ={{0,1,1,1,0,0,0,0,0,0},
				 {1,1,1,0,1,1,0,0,1,1},
				 {0,0,0,0,0,1,0,0,1,1},
				 {0,0,0,0,0,1,1,1,1,1}};

	std::cout<< maxAreaOfIsland(g2)<<'\n';
				
	return 0;
}
