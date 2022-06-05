class Solution
{
    int count = 0;

    void markAdjacent(vector<vector < int>> &grid, int sr, int sc)
    {
        if (grid[sr][sc] == 0 or grid[sr][sc] == 2)
            return;
        grid[sr][sc] = 2;
        count++;
        if (sr + 1 < grid.size())
            markAdjacent(grid, sr + 1, sc);
        if (sr - 1 >= 0)
            markAdjacent(grid, sr - 1, sc);
        if (sc + 1 < grid[0].size())
            markAdjacent(grid, sr, sc + 1);
        if (sc - 1 >= 0)
            markAdjacent(grid, sr, sc - 1);
    }

    public:
        int maxAreaOfIsland(vector<vector < int>> &grid)
        {
            int maxArea = 0;
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[i].size(); j++)
                {
                    if (grid[i][j] == 1)
                    {
                        markAdjacent(grid, i, j);
                        maxArea = max(maxArea, count);
                        count = 0;
                    }
                }
            }
            return maxArea;
        }
};