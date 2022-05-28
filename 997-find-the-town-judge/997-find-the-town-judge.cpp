class Solution
{
    public:
        int findJudge(int n, vector<vector < int>> &trust)
        {
            if (n == 1 and trust.size() == 0)
                return 1;
            set<int> people;
            unordered_map<int, int> mp;

            for (int i = 0; i < trust.size(); i++)
                people.insert(trust[i][0]);
            if (people.size() != n - 1)
                return -1;
            for (int i = 0; i < trust.size(); i++)
            {
                auto it = mp.find(trust[i][1]);
                if (it != mp.end())
                    it->second++;
                else
                    mp.insert({ trust[i][1],
                        1 });
            }

            for (int i = 0; i < trust.size(); i++)
            {
                auto it = mp.find(trust[i][1]);
                if (it != mp.end() and it->second == people.size())
                    return it->first;
            }
            return -1;
        }
};