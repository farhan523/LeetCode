#include<stack>
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n =  k % nums.size();
        vector<int>res;
        int start = nums.size() - n;
        while(start < nums.size())
            res.push_back(nums[start++]);
        start = 0;
        while(start < nums.size() - n){
            res.push_back(nums[start++]);
        }
        nums = res;
    }
};