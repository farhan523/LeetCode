class Solution
{
    vector<vector < int>> result;
    set<int> st;
    void permutation(vector<int> &nums, vector<int> &res)
    {
        if (res.size() == nums.size())
        {
            result.push_back(res);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (st.find(nums[i]) == st.end())
            {
                st.insert(nums[i]);
                res.push_back(nums[i]);
                permutation(nums, res);
                st.erase(nums[i]);
                res.pop_back();
            }
        }
    }
    public:
        vector<vector < int>> permute(vector<int> &nums)
        {
            vector<int> res;
            permutation(nums, res);
            return result;
        }
};