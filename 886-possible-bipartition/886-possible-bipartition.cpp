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
                if(visited[list[top][i]] == visited[top] )return false;
                if (visited[list[top][i]] == -1)
                {
                    visited[top] == 1 ? visited[list[top][i]] = 2 : visited[list[top][i]] = 1;
                    q.push(list[top][i]);
                }
               
            }
        }

        return true;
    }

    public:
        bool possibleBipartition(int n, vector<vector < int>> &graph)
        {
            vector<int> visited(n + 1, -1);
            vector<int> temp;
            int size = n + 1;
           std::vector<std::vector<int>> list(n+1, temp);
            for (int i = 0; i <graph.size(); i++)
            {

                list[graph[i][0]].push_back(graph[i][1]);
                 list[graph[i][1]].push_back(graph[i][0]);
            }
            for (int i = 1; i <= n; i++)
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