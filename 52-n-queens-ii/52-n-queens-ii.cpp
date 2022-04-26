class Solution
{
    public:
        set<int> col;
    vector<vector < int>> board
    {
        9,
        vector<int> (9, 0)
    };
    vector<vector < string>> result;
    vector<string> temp;
    int N;
    void place(string res, int queen, int rows)
    {
        if (temp.size() == N)
            result.push_back(temp);

        if (rows > N || queen == N)
            return;

        for (int i = 0; i < N; i++)
        {

            if (board[rows][i] == 0 && col.find(i) == col.end())
            {
                col.insert(i);
                board[rows][i]++;
                int nextRow = rows + 1;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (nextRow > N - 1) break;
                    board[nextRow++][j]++;
                }
                nextRow = rows + 1;
                for (int j = i + 1; j < N; j++)
                {
                    if (nextRow > N - 1) break;
                    board[nextRow++][j]++;
                }
                res[i] = 'Q';
                temp.push_back(res);
                res[i] = '.';
                place(res, queen + 1, rows + 1);
                board[rows][i]--;
                nextRow = rows + 1;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (nextRow > N - 1) break;
                    board[nextRow++][j]--;
                }
                nextRow = rows + 1;
                for (int j = i + 1; j < N; j++)
                {
                    if (nextRow > N - 1) break;
                    board[nextRow++][j]--;
                }
                col.erase(i);
                res[i] = '.';
                temp.pop_back();
            }
        };
    }

    vector<vector < string>> solveNQueen(int n)
    {
        string s;

        for (int i = 0; i < n; i++)
            s.push_back('.');
        vector<string> res;
        for (int i = 0; i < n; i++)
            res.push_back(s);
        place(s, 0, 0);
        return result;
    }

    public:
         int totalNQueens(int n) 
        {
            N = n;
            solveNQueen(n);
             return result.size();
        }
};