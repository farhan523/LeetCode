class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        while( i < nums.size() and nums[i] < 0 and k > 0){
                nums[i] = -nums[i];
            k--;
            i++;
        }
        bool isOdd = k % 2 != 0;
        sort(nums.begin(),nums.end());
        if(i < nums.size() and isOdd or k > 0 and isOdd)
                nums[0] = -nums[0];
        int sum = 0;
        for(int x : nums)
                sum += x;
        return sum;
    }
};