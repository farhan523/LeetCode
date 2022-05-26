class Solution
{
    public:
        vector<vector < int>> findDifference(vector<int> &nums1, vector<int> &nums2)
        {
            vector<vector < int>> res;
            vector<int> res1;
            vector<int> res2;
            unordered_set<int> st(nums1.begin(), nums1.end());
            for (int i = 0; i < nums2.size(); i++)
            {
                auto it = st.find(nums2[i]);
                if (it == st.end())
                {
                    res2.push_back(nums2[i]);
                }
                st.insert(nums2[i]);
            }

            unordered_set<int> st2(nums2.begin(), nums2.end());
            for (int i = 0; i < nums1.size(); i++)
            {
                auto it = st2.find(nums1[i]);
                if (it == st2.end())
                {
                    res1.push_back(nums1[i]);
                }
                st2.insert(nums1[i]);
            }

            res = { res1,
                res2
            };
            return res;
        }
};