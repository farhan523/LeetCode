class Solution
{
    public:
        int countWords(vector<string> &words1, vector<string> &words2)
        {
            unordered_map<string, int> mp;
            unordered_map<string, int> mp2;
            for (int i = 0; i < words1.size(); i++)
            {
                auto it = mp.find(words1[i]);
                if (it == mp.end())
                {
                    mp.insert({ words1[i],
                        1 });
                }
                else
                {
                    it->second++;
                }
            }
            
            for (int i = 0; i < words2.size(); i++)
            {
                auto it = mp2.find(words2[i]);
                if (it == mp2.end())
                {
                    mp2.insert({ words2[i],
                        1 });
                }
                else
                {
                    it->second++;
                }
            }
            
            vector<string>res;
            for (int i = 0; i < words2.size(); i++)
            {
                auto it = mp2.find(words2[i]);
                auto it2 = mp.find(words2[i]);
                if(it != mp2.end() and it2 != mp.end() and it->second == 1 and it2->second == 1)
                        res.push_back(words2[i]);
            }
            
            
            return res.size();
        }
};