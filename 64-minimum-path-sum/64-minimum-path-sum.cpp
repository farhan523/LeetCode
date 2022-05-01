class Solution
{
    vector<vector < int>> matrix;
    int r;
    int c;
    int getDistance(vector<vector < int>> &grid, int row, int column)
    {
        if (row == r and column == c)
        {
            return grid[row][column];
        }

        if (matrix[row][column] != -1)
            return matrix[row][column];
        int r1;
        int r2;
        if (row < r and column < c)
        {
            r1 = getDistance(grid, row + 1, column);
            r2 = getDistance(grid, row, column + 1);
            matrix[row][column] = grid[row][column] + min(r1,r2);
                return matrix[row][column];
            
        }
        if(row + 1 > r and column + 1 <= c){
            matrix[row][column] = grid[row][column] + getDistance(grid, row, column + 1);
            return matrix[row][column];
        }
        if(row + 1 <= r and column + 1 > c){
            matrix[row][column] = grid[row][column] + getDistance(grid, row+1, column);
            return matrix[row][column];
        }
         return grid[row][column];                                                 
}                                                         
        public:
            int minPathSum(vector<vector < int>> &grid)
            {

                vector<vector < int>> vec(grid.size(), vector<int> (grid[0].size(), -1));
                
                matrix = vec;
                
                r = grid.size() - 1;
                c = grid[0].size() - 1;
               return getDistance(grid,0,0);
            }
    };