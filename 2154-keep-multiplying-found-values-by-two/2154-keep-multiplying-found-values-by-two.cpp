class Solution
{
    public:
        int findFinalValue(vector<int> &nums, int original)
        {
            sort(nums.begin(), nums.end());
            bool res;
            while (true)
            {
                res = binary_search(nums.begin(), nums.end(), original);
                cout << res;
                if (res)
                    original *= 2;
                else
                    return original;
            }
            return 1;
        }
};