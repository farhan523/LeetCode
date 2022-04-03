class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int slow = 0;
        int fast = 1;
        int count = 1;
        int soFarGreat = INT_MIN;
        while(fast < nums.size()){
            if(nums[fast] > nums[fast - 1]){
                count++;
            }else{
                if(count > soFarGreat)
                    soFarGreat = count;
                count = 1;
            }
            fast++;
        }
        if(count > soFarGreat)
                    soFarGreat = count;
        return soFarGreat;
    }
};