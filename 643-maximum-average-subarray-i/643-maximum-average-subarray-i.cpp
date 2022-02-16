class Solution {
public:
   double findMaxAverage(vector<int>& nums, int k) {
        int fast = 0;
        int slow = 0;
        double sum = 0;
        double maxAverage = INT32_MIN;
        while(fast < nums.size()){
            sum += nums[fast];
            
            if(fast + 1 - slow == k){
                if(sum / k > maxAverage)
                    maxAverage = sum / k;
                sum -= nums[slow];
                slow++;
            }
            fast++;
        }
        return maxAverage;
    }
};