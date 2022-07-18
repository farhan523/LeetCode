class Solution
{
    public:
        int countAsterisks(string s)
        {
            int count = 0;
            bool so = false;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '*'
                    and!so)
                    count++;
                if (s[i] == '|')
                    so ? so = false : so = true;
            }
            return count;
        }
};