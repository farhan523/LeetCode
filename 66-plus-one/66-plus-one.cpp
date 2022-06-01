class Solution
{
    public:
        vector<int> plusOne(vector<int> &digits)
        {
            vector<int> res;
            if (digits[digits.size() - 1] != 9)
            {
                digits[digits.size() - 1]++;
                return digits;
            }
            if (digits.size() == 1)
            {
                digits.clear();
                digits = { 1,
                    0
                };
                return digits;
            }
            int k = digits.size() - 1;
            while (k >= 0 and digits[k] == 9)
            {
                digits[k] = 0;
                k--;
            }
            if (k >= 0)
                digits[k]++;
            else
            {
                digits.insert(digits.begin(), 1);
            }
            return digits;
        }
};