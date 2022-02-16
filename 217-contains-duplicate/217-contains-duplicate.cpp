class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        set<int>::iterator it;
        for(int i=0;i<nums.size();i++){
            it = s.find(nums[i]);
            if(it == s.end())
                s.insert(nums[i]);
            else
                return true;
        }
        return false;
    }
};