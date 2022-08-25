class Solution
{
    vector<bool> visited;
    int longestCycleNum = -1;
    int cyclicNode = -1;
    int depthFirstSearch(vector<int> &edges, int current)
    {
        if (visited[current] == true)
        {
            cyclicNode = current;
            return 1;
        }
        if (edges[current] == -1)
        {
            return 0;
        }


            visited[current] = true;
        int res = depthFirstSearch(edges, edges[current]);
        if (current == cyclicNode)
        {
            if (res > longestCycleNum)
                longestCycleNum = res;
        }
        return res + 1;
    }

    public:
        int longestCycle(vector<int> &edges)
        {
            vector<bool> visited2(edges.size(), false);
            visited = visited2;

            for (int i = 0; i < edges.size(); i++)
            {
                if (visited[i] == false and edges[i] != -1)
                {
                    depthFirstSearch(edges, i);
                }
            }

            return longestCycleNum;
        }
};