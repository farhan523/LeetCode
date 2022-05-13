class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       vector<int>temp;
        for(int i=0;i<=nums.size();i++){
            temp.push_back(i);
        }
        temp[0] = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= nums.size() and nums[i] >= 0){
                temp[nums[i]] = -1;
            }
        }
       
        for(int i = 0;i<temp.size();i++){
            if(temp[i] == i)
                return i;
        }
        return temp.size();
    }
};