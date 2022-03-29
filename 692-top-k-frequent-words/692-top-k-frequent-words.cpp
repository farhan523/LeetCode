typedef pair<int, string> Max;
class Solution
{
    struct Compare
    {
        bool operator()(Max &a, Max &b)
        {
            if(a.first != b.first)
                return a <b;
            if(a.second < b.second)
                return false;
            else
                return true;
            
        }
    };
    public:
        vector<string> topKFrequent(vector<string> &words, int k)
        {
            unordered_map<string, int> mp;
            priority_queue<Max, vector<Max>, Compare> pq;
            vector<string> res;
            for (auto x: words)
            {
                auto it = mp.find(x);
                if (it == mp.end())
                {
                    mp.insert({ x,
                        1 });
                }
                else
                {
                    it->second++;
                }
            }
            for (auto x: words)
            {
                auto it = mp.find(x);
                if (it != mp.end())
                {
                    pq.push({ it->second,
                        it->first });
                    mp.erase(it);
                }
            }
            while( k > 0){
                res.push_back(pq.top().second);
                pq.pop();
                k--;
            }
            return res;
        }
};