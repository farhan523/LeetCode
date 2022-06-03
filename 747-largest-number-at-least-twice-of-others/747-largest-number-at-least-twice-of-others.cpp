class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        vector<int>bing = nums;
        sort(nums.begin(),nums.end());
         if(nums[nums.size() - 1] >= nums[nums.size() - 2] * 2){
             for(int i=0;i<bing.size();i++){
                 if(bing[i] == nums[nums.size() - 1])
                     return i;
             }
         }
        return -1;
    }
};