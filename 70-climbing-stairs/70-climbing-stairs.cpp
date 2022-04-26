class Solution
{
    int N;
    unordered_map<int, int> mp;
    int count(int n)
    {
        if (n == N)
            return 1;
        if (n > N)
            return 0;
        int count1 = 0, count2 = 0;
        if (mp.find(n + 1) == mp.end())
        {
            count1 = count(n + 1);
            mp.insert({ n + 1,
                count1 });
        }
        else
        {
            count1 = mp.find(n + 1)->second;
        }

        if (mp.find(n + 2) == mp.end())
        {
            count2 = count(n + 2);
            mp.insert({ n + 2,
                count1 });
        }
        else
        {
            count2 = mp.find(n + 2)->second;
        }
        return count1 + count2;
    }
    public:
        int climbStairs(int n)
        {
            N = n;
            return count(0);
        }
};