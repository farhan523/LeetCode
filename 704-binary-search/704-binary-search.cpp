class Solution
{
    public:

        int binarySearch(vector<int> &nums, int left, int right, int target)
        {
            if (left > right)
                return -1;
            int midpoint = (left + right) / 2;
            if (nums[midpoint] == target)
                return midpoint;
            if (target > nums[midpoint])
                return binarySearch(nums, midpoint + 1, right, target);
            return binarySearch(nums, left, midpoint - 1, target);
        }
    int search(vector<int> &nums, int target)
    {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};