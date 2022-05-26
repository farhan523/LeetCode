class Solution
{
    public:
        vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
        {
            set<int> st(nums2.begin(), nums2.end());
            set<int> used;
            vector<int> res;
            for (int i = 0; i < nums1.size(); i++)
            {
                if (st.find(nums1[i]) != st.end() and used.find(nums1[i]) == used.end())
                {
                    res.push_back(nums1[i]);
                    used.insert(nums1[i]);
                }
            }
            return res;
        }
};