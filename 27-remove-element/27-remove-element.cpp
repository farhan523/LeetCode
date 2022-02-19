class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int end = nums.size() - 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == val){
                count++;
                while(end >= 0){
                    if(nums[end] != val){
                        nums[i] = nums[end];
                        end--;
                        break;
                    }
                    end--;
                }
            }
                
           
        }
        return nums.size() - count;
    }
};