class Solution {
    vector<vector < int>> matrix;
    int r;
    int c;
    int getDistance( int row, int column)
    {
        if (row == r and column == c)
        {
            return 1;
        }

        if (matrix[row][column] != -1)
            return matrix[row][column];
        int r1;
        int r2;
        if (row < r and column < c)
        {
            r1 = getDistance( row + 1, column);
            r2 = getDistance(row, column + 1);
            matrix[row][column] = r1 + r2;
            return matrix[row][column];
        }
        if (row + 1 > r and column + 1 <= c)
        {
            matrix[row][column] =  getDistance(row, column + 1);
            return matrix[row][column];
        }
        if (row + 1 <= r and column + 1 > c)
        {
            matrix[row][column] =  getDistance(row + 1, column);
            return matrix[row][column];
        }
        return 0;
    }
public:
    int uniquePaths(int m, int n) {
         vector<vector < int>> vec(m, vector<int> (n, -1));

            matrix = vec;

            r = m - 1;
            c = n - 1;
            return getDistance(0, 0);
    }
};