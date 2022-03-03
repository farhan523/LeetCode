class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        int count = 0;
        int slow = nums.size() - 1;
        int fast = nums.size() - 1;
        int prevDiff = nums[nums.size() - 1] - nums[nums.size() - 2];
        for(int i =nums.size() - 1;i >0;i--)
        {
            if(nums[i] - nums[i -1] == prevDiff && slow - fast >=1){
                count += slow - fast;
                fast--;
            }else if (nums[i] - nums[i -1] != prevDiff){
                prevDiff = nums[i] - nums[i - 1];
                 slow = fast;
                fast --;
            }else{
                fast--;
            }
            
        }  
        return count ;
    }
};