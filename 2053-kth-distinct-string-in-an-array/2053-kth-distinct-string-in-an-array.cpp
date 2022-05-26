class Solution
{
    public:
        string kthDistinct(vector<string> &arr, int k)
        {
            unordered_map<string, int> mp;
            for (int i = 0; i < arr.size(); i++)
            {
                auto it = mp.find(arr[i]);
                if (it == mp.end())
                {
                    mp.insert({ arr[i],
                        1 });
                }
                else
                {
                    it->second++;
                }
            }
            for (int i = 0; i < arr.size(); i++)
            {
                auto it = mp.find(arr[i]);
                if (it != mp.end() and it->second == 1 and k == 1)
                    return arr[i];
                if (it != mp.end() and it->second == 1)
                    k--;
            }
            return "";
        }
};