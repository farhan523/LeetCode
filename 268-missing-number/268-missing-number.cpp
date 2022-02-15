class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(), nums.end());
        std::unordered_set<int>::iterator it;
        for(int i=0;i<nums.size();i++){
            it = s.find(i);
            if(it == s.end())
                return i;
        }
        return nums.size();
    }
};