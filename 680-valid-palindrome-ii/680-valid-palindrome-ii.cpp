class Solution
{
    bool isPalindrome(string s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    public:
        bool validPalindrome(string s)
        {
            int l = 0;
            int r = s.size() - 1;
            int count = 0;
            while (l < r)
            {
                if (s[l] != s[r])
                {
                    if (isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1))
                        return true;
                    return false;
                }
                l++;
                r--;
            }
            return true;
        }
};