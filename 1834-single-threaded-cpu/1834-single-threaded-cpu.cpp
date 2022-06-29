class Solution
{
    priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq2;
    vector<int> res;
    unsigned long long int count;
    void insertArrivedProcess(vector<vector < int>> &tasks)
    {
        while (!pq2.empty() and pq2.top().first <= count)
        {
            pq.push({ tasks[pq2.top().second][1],
                pq2.top().second });
            pq2.pop();
        }
    }

    public:
        vector<int> getOrder(vector<vector < int>> &tasks)
        {
           	

            for (int i = 0; i < tasks.size(); i++)
            {
                pq2.push({ tasks[i][0],
                    i });
            }
            cout << pq2.top().first;
            count = pq2.top().first;
            while (!pq2.empty() and pq2.top().first <= count)
            {
                pq.push({ tasks[pq2.top().second][1],
                    pq2.top().second });
                pq2.pop();
            }

            while (!pq.empty())
            {
                res.push_back(pq.top().second);
                count += pq.top().first;
                pq.pop();
                if (!pq2.empty())
                {
                    while (pq2.top().first > count and pq.empty())
                        count++;
                    insertArrivedProcess(tasks);
                }
            }

            return res;
        }
};