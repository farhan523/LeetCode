class Solution
{
    int count = 1;
    queue<pair<int, int>> next;
    int row;
    int col;
    bool exit = false;
    void breadthFirstSearch(vector<vector < char>> &maze, int r, int c)
    {
        if (c + 1 >= col || r + 1 >= row || c - 1 < 0 || r - 1 < 0)
        {
            exit = true;
            return;
        }
        if (maze[r + 1][c] != '/'
            and maze[r + 1][c] != '+')
        {
            next.push({ r + 1,
                c });
            maze[r + 1][c] = '/';
        }
        if (maze[r][c + 1] != '/'
            and maze[r][c + 1] != '+')
        {
            next.push({ r,
                c + 1 });
            maze[r][c + 1] = '/';
        }
        if (maze[r - 1][c] != '/'
            and maze[r - 1][c] != '+')
        {
            next.push({ r - 1,
                c });
            maze[r - 1][c] = '/';
        }
        if (maze[r][c - 1] != '/'
            and maze[r][c - 1] != '+')
        {
            next.push({ r,
                c - 1 });
            maze[r - 1][c] = '/';
        }
    }

    public:
        int nearestExit(vector<vector < char>> &maze, vector< int > &entrance)
        {
            row = maze.size();
            col = maze[0].size();

            int r = entrance[0], c = entrance[1];
            maze[r][c] = '/';
            if (r + 1 < row and maze[r + 1][c] != '+')
            {
                next.push({ r + 1,
                    c });
                maze[r + 1][c] = '/';
            }
            if (c + 1 < col and maze[r][c + 1] != '+')
            {
                next.push({ r,
                    c + 1 });
                maze[r][c + 1] = '/';
            }
            if (r - 1 >= 0 and maze[r - 1][c] != '+')
            {
                next.push({ r - 1,
                    c });
                maze[r - 1][c] = '/';
            }
            if (c - 1 >= 0 and maze[r][c - 1] != '+')
            {
                next.push({ r,
                    c - 1 });
                maze[r][c - 1] = '/';
            }
            if (next.size() == 0)
                return -1;
            while (!next.empty())
            {
                int size = next.size();
                for (int i = 0; i < size; i++)
                {
                    breadthFirstSearch(maze, next.front().first, next.front().second);
                    next.pop();
                }
                if (exit == true)
                    return count;
                count++;
            }
            return -1;
        }
};