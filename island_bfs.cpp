#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using std::vector;

int countIsland(vector<vector<bool>>& searched,
                const vector<vector<int>>& grid,
                int row, int col)
{
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    std::queue<std::pair<int, int>> waiting;
    waiting.push({row, col});
    searched[row][col] = true;

    int rowChange[] = {0, 1, 0, -1};
    int colChange[] = {1, 0, -1, 0};

    while (!waiting.empty())
    {
        int currentRow = waiting.front().first;
        int currentCol = waiting.front().second;
        waiting.pop();
        count++;

        for (int direction = 0; direction < 4; direction++)
        {
            int nextRow = currentRow + rowChange[direction];
            int nextCol = currentCol + colChange[direction];

            if (nextRow >= 0 && nextRow < rows &&
                nextCol >= 0 && nextCol < cols &&
                !searched[nextRow][nextCol] &&
                grid[nextRow][nextCol] == 1)
            {
                searched[nextRow][nextCol] = true;
                waiting.push({nextRow, nextCol});
            }
        }
    }

    return count;
}

int maxAreaOfIsland(const vector<vector<int>>& grid)
{
    if (grid.empty() || grid[0].empty())
    {
        return 0;
    }

    int rows = grid.size();
    int cols = grid[0].size();
    int maxCount = 0;

    vector<vector<bool>> searched(rows, vector<bool>(cols, false));

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == 1 && !searched[row][col])
            {
                int count = countIsland(searched, grid, row, col);

                if (count > maxCount)
                {
                    maxCount = count;
                }
            }
        }
    }

    return maxCount;
}

int main()
{
    vector<vector<int>> g = {{1, 1},
                             {0, 1}};
    std::cout << maxAreaOfIsland(g) << '\n';

    g = {{0, 0},
         {0, 0}};
    std::cout << maxAreaOfIsland(g) << '\n';

    g = {{1}};
    std::cout << maxAreaOfIsland(g) << '\n';

    g = {{1, 0},
         {0, 1}};
    std::cout << maxAreaOfIsland(g) << '\n';

    g = {{1, 1},
         {1, 1}};
    std::cout << maxAreaOfIsland(g) << '\n';

    return 0;
}
