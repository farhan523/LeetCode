class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;
        while(left < right){
            int mid = left + (right - left) / 2;
           if(nums[mid] == target ||  nums[left] == target || nums[right] == target) 
               return true;
            if(nums[left] < nums[right]){
                if(target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }else if(nums[left] == nums[right]){
                left++;
                right--;
            }else{
                if(nums[left] < nums[mid] && target < nums[mid] && target >= nums[left] || (nums[mid] <= nums[right] && (target < nums[mid] || target > nums[right])))
                    right = mid -1;
                else 
                    left = mid + 1;
            }
                     }
        return nums[left] == target ? true : false;
    }
};