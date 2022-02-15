class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int length = INT_MAX;
        int slow = 0;
        int fast = 0;
        int sum = 0;
        while(fast < nums.size()){
           sum += nums[fast];
            while(sum >= target ){
                if(fast - slow < length)
                    length = fast - slow + 1;
                sum -= nums[slow++];
            }
            fast++;
        }
        return length == INT_MAX ? 0 : length;
    }
};