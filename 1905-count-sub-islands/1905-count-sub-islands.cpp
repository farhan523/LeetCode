class Solution {
    vector<vector < int>> grid1;
    bool markAdjacent(vector<vector < int>> &grid, int sr, int sc)
    {
        if (grid[sr][sc] == 0
            or grid[sr][sc] == 2)
            return true;
        
        if(grid1[sr][sc] == 0 or grid1[sr][sc] == 2)
            return false;
        grid[sr][sc] = 2;
        grid1[sr][sc] = 2;
        bool r1 = true,r2 = true,r3 = true,r4 =true;
        if (sr + 1 < grid.size())
            r1 =  markAdjacent(grid, sr + 1, sc);
        if (sr - 1 >= 0)
            r2 =  markAdjacent(grid, sr - 1, sc);
        if (sc + 1 < grid[0].size())
            r3 = markAdjacent(grid, sr, sc + 1);
        if (sc - 1 >= 0)
            r4 = markAdjacent(grid, sr, sc - 1);
        return (r1 & r2 & r3 & r4);
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid) {
            int count = 0;
            this->grid1 = grid1;
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[i].size(); j++)
                {
                    if (grid[i][j] == 1 and grid1[i][j] == 1)
                    {
                         bool res = markAdjacent(grid, i, j);
                        if(res == true)
                            count++;
                    }
                }
            }
            return count;
    }
};