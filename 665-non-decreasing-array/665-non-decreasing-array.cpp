class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
       int count = 0;
       for(int i = 1;i<nums.size();i++){
            if(nums[i] < nums[i-1] and (i-1 == 0 || nums[i-2] <= nums[i] )){
                nums[i-1] = nums[i];
                count++;
                i--;
            }else if(nums[i] < nums[i-1]){
                nums[i] = nums[i-1];
                count++;
                i--;
            }
           if(count > 1)
               return false;
       } 
        return true;
    }
};