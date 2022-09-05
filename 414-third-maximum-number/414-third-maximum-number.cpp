class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()<3){
            return *max_element(nums.begin(),nums.end());
        }
        
        sort(nums.begin(),nums.end());
        int ans=1;
        for(int i=nums.size()-1 ; i>=1 ; i--){
            if(nums[i]!=nums[i-1]){
                ans++;
            }
            if(ans==3){
                return nums[i-1];
            }
        }
        return nums[nums.size()-1];
    }
};