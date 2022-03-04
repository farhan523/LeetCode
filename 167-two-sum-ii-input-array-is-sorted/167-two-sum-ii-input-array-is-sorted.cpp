class Solution
{
    public:
        vector<int> twoSum(vector<int> &numbers, int target)
        {

            vector<int> res;
            int lPtr = 0;
            int rPtr = numbers.size() - 1;
            while (lPtr < rPtr)
            {
                if (numbers[lPtr] + numbers[rPtr] == target)
                {
                    res.push_back(lPtr + 1);
                    res.push_back(rPtr + 1);
                    return res;
                }
                else if (numbers[rPtr] > target || numbers[rPtr] + numbers[lPtr] > target)
                    rPtr--;
                else
                {
                    lPtr++;
                }
            }
            return res;
        }
};