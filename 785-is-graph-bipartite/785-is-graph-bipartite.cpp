class Solution
{
    queue<int> q;
    bool bipitrate(vector<vector < int>> &list, int index, vector< int > &visited)
    {
        visited[index] = 1;
        q.push(index);

        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            for (int i = 0; i < list[top].size(); i++)
            {
                if (visited[list[top][i]] == -1)
                {
                    visited[top] == 1 ? visited[list[top][i]] = 2 : visited[list[top][i]] = 1;
                    q.push(list[top][i]);
                }
                else
                {
                    bool res = visited[list[top][i]] == visited[top] ? true : false;
                    if (res)
                        return false;
                }
            }
        }

        return true;
    }

    public:
        bool isBipartite(vector<vector < int>> &graph)
        {
            vector<int> visited(graph.size(), -1);
            vector<int> temp;
            vector<vector < int>> list
            {
                graph.size(), temp
            };
            for (int i = 0; i < graph.size(); i++)
            {
                for (int j = 0; j < graph[i].size(); j++)
                {
                    list[i].push_back(graph[i][j]);
                }
            }
            for (int i = 0; i < graph.size(); i++)
            {
                if (visited[i] == -1)
                {
                    bool res = bipitrate(list, i, visited);
                    if (!res)
                        return false;
                }
            }
            return true;
        }
};