class Solution
{
    public:
        vector<int> twoSum(vector<int> &numbers, int target)
        {

            vector<int> res;
            int lPtr = 0;
            int rPtr = numbers.size() - 1;
            int sum;
            while (lPtr < rPtr)
            {
                 sum = numbers[lPtr] + numbers[rPtr];
                if ( sum == target)
                {
                    res.push_back(lPtr + 1);
                    res.push_back(rPtr + 1);
                    return res;
                }
                else if (numbers[rPtr] > target || sum > target)
                    rPtr--;
                else
                {
                    lPtr++;
                }
            }
            return res;
        }
};