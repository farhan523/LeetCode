class Solution
{

    bool isCycle = false;
    vector<vector < bool>> visited;
    int row;
    int col;
    void depthFirstSearch(vector<vector < char>> &grid, int r, int c, int pr, int pc)
    {
        if (visited[r][c])
        {
            isCycle = true;
            return;
        }
        visited[r][c] = true;
        if (r + 1 < row and r + 1 != pr and grid[r + 1][c] == grid[r][c])
            depthFirstSearch(grid, r + 1, c, r, c);
        if (c + 1 < col and c + 1 != pc and grid[r][c + 1] == grid[r][c])
            depthFirstSearch(grid, r, c + 1, r, c);
        if (r - 1 >= 0 and r - 1 != pr and grid[r - 1][c] == grid[r][c])
            depthFirstSearch(grid, r - 1, c, r, c);
        if (c - 1 >= 0 and c - 1 != pc and grid[r][c - 1] == grid[r][c])
            depthFirstSearch(grid, r, c - 1, r, c);
    }

    public:
        bool containsCycle(vector<vector < char>> &grid)
        {
            this->row = grid.size();
            this->col = grid[0].size();

            std::vector<std::vector < bool>> matrix(row, std::vector<bool> (col, false));
            visited = matrix;

            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[i].size(); j++)
                {
                    if (!visited[i][j])
                    {
                        depthFirstSearch(grid, i, j, -1, -1);
                    }
                }
            }
            return isCycle;
        }
};