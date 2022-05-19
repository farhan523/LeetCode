class Solution {
     vector<vector < int>> matrix;
    int r;
    int c;
    int getDistance(int row, int column)
    {
        if (row == r and column == c and matrix[row][column] != -2)
        {
            return 1;
        }
        if (matrix[row][column] == -2)
            return 0;
        
        if (matrix[row][column] != -1)
            return matrix[row][column];
        int r1;
        int r2;
        if (row < r and column < c)
        {
            r1 = getDistance(row + 1, column);
            r2 = getDistance(row, column + 1);
            matrix[row][column] = r1 + r2;
            return matrix[row][column];
        }
        if (row + 1 > r and column + 1 <= c)
        {
            matrix[row][column] = getDistance(row, column + 1);
            return matrix[row][column];
        }
        if (row + 1 <= r and column + 1 > c)
        {
            matrix[row][column] = getDistance(row + 1, column);
            return matrix[row][column];
        }
        return 0;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j] == 0)
                    obstacleGrid[i][j] = -1;
                else
                    obstacleGrid[i][j] = -2;
            }
        }
        matrix = obstacleGrid;
        r = n - 1;
        c = m - 1;
        return getDistance(0, 0);
    }
};