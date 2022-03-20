class Solution {
public:
    
    int binarySearch(vector<int>& arr,int l,int r,int x){
        
               if (r >= l) {
                int mid = l + (r - l) / 2;

                // If the element is present at the middle
                // itself
                if (arr[mid] == x)
                    return mid;

                // If element is smaller than mid, then
                // it can only be present in left subarray
                if ((arr[mid] > x && arr[l] <= x) && l != r)
                    return binarySearch(arr, l, mid - 1, x);

                // Else the element can only be present
                // in right subarray
                 if(arr[r] >= x &&  r -l >1)
                        return binarySearch(arr, mid + 1, r, x);
                   if (arr[l] < x && arr[r] > x)
                        return l + 1;
                    else if(arr[l] > x)
                        return l;
                     else if(arr[r] < x )
                        return r + 1;
                        return l + 1;
            }
        
            if(arr[0] < x)
                return 1;
            return 0;
        
        
      
       
    }
    
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0] > target)
            return 0;
        if(nums[nums.size() -1] < target)
                return nums.size();
        auto it = lower_bound(nums.begin(),nums.end(),target);
        cout<<(it-nums.begin());
      return (it - nums.begin());
    }
};