class Solution
{
    public:
        bool findRotation(vector<vector < int>> &m, vector< vector< int>> &target)
        {
            int n = m.size();
            int k = 0;
            while (k++<=3)
            {
                for (int i = 0; i < n; ++i)
                {
                    reverse(m[i].begin(), m[i].end());
                }
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n - i; ++j)
                    {
                        swap(m[i][j], m[n - 1 - j][n - 1 - i]);
                    }
                }
                if(m == target)
                    return true;
            }
            return false;
        }
};