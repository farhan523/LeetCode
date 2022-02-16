class Solution {
public:
   int lengthOfLongestSubstring(string s)
{
    set<char> tmp;
    int longestSize = 0;
    int soFar = 0;
    int fast = 0;
    int slow = 0;
    while (fast < s.size())
    {
        if (tmp.find(s[fast]) != tmp.end())
        {
            if (soFar > longestSize)
                longestSize = soFar;
            while (slow < fast)
            {
                if (s[slow] == s[fast])
                {

                    slow++;

                    break;
                }
                tmp.erase(s[slow]);
                slow++;
                soFar--;
            }
        }
        else
        {
            tmp.insert(s[fast]);
            soFar++;
        }
        fast++;
    }
    if (soFar > longestSize)
        longestSize = soFar;
    return longestSize;
}
};