class Solution
{
    vector<vector < int>> dp;

    int count(vector<int> &coins, int amount, int i)
    {
        if (amount == 0)
            return 1;
        if (i == coins.size())
            return 0;
        if (dp[i][amount] != -1)
            return dp[i][amount];
        int r1 = 0;
        if (coins[i] <= amount)
            r1 = count(coins, amount - coins[i], i);

        int r2 = count(coins, amount, i + 1);
        dp[i][amount] = r1 + r2;
        return dp[i][amount];
    }
    public:
        int change(int amount, vector<int> &coins)
        {
            
            int n = coins.size();
            vector<vector < int>> matrix(n + 1, vector<int> (amount + 1, -1));
            dp = matrix;
            int ans = count(coins, amount, 0);
            return ans;
        }
};