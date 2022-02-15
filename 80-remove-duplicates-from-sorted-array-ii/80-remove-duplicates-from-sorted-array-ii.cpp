class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current = 0;
        int rate = 0;
         for(int i=0;i<nums.size() - 1;i++){
             current++;
            if(i + 1 == nums.size() - 1 && nums[i] == nums[i+1]){
                current++;
                
            }
             
            if(nums[i] != nums[i+1] || i + 1 == nums.size() - 1 && nums[i] == nums[i+1]){
                int j = i;
                while(current > 2){
                    nums[j] = INT_MAX;
                    rate++;
                    current--;
                    j--;
                }
                current = 0;
                continue;
            }
           
        }
        sort(nums.begin(),nums.end());
        return nums.size() - rate;
    }
};