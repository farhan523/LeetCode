class Solution
{
    public:
        string longestCommonPrefix(vector<string> &strs)
        {
            if (strs.size() == 1)
                return strs[0];
            int end = strs[0].size();
            int start = 0;
            for (int i = 1; i < strs.size(); i++)
            {
                int k = 0;
                while (k < strs[0].size() and k < strs[i].size() and strs[0][k] == strs[i][k] and k < end)
                    k++;
                end = k;
            }
            string res;
            for (int i = 0; i < end; i++)
                res.push_back(strs[0][i]);
            return res;
        }
};