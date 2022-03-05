class Solution
{
    public:
        bool isPowerOfThree(int n)
        {
            if (n <= 0)
                return false;
            int b = log10(n) / log10(3);
            cout << b;
            return pow(3, b) == n;
              
        }
};