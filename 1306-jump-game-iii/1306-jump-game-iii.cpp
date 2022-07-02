class Solution
{
    queue<int> que;
    unordered_set<int> st;
    public:
        bool canReach(vector<int> &arr, int start)
        {
            if (arr[start] == 0)
                return true;
           que.push(start);
            st.insert(start);

            while (!que.empty())
            {
                if (arr[que.front()] == 0)
                    return true;
                start = que.front();
                if (start + arr[start] < arr.size() and st.find(start + arr[start]) == st.end())
                {
                    st.insert(start + arr[start]);
                    que.push(start + arr[start]);
                }

                if (start - arr[start] >= 0 and st.find(start - arr[start]) == st.end())
                {
                    st.insert(start - arr[start]);
                    que.push(start - arr[start]);
                }

                que.pop();
            }
            return false;
        }
};