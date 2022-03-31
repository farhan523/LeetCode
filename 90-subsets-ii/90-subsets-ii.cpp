class Solution
{
    vector<vector < int>> subset;
    vector<int> aux;
    set<vector<int>>st;
    void subSets(vector<int> &nums, int index)
    {
        if (index == nums.size())
        {
            if(st.find(aux) == st.end()){
                 subset.push_back(aux);
                 st.insert(aux);
            }
           
            return;
        }

        subSets(nums, index + 1);
        aux.push_back(nums[index]);
        subSets(nums, index + 1);
        aux.pop_back();
    }

    public:
        vector<vector < int>> subsetsWithDup(vector<int> &nums) {
            sort(nums.begin(),nums.end());
            subSets(nums,0);
            return subset;
        }
};