class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target && result.size() < 1) 
                result.push_back(i);
            if(result.size() == 1 && nums[i] != target)
                result.push_back(i-1);
            
        }
        if(result.size() == 1 && nums.size() ==1)
            result.push_back(result[0]);
        if(result.size() == 1)
            result.push_back(nums.size() - 1);
        
        if(result.size() == 0){
             result.push_back(-1);
             result.push_back(-1);
        }
        return result;
    }
};