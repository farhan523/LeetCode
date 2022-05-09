class Solution
{
     vector<vector<int>>dp;
    int count(vector<int> &coins, int amount, int i)
    {
        if (amount == 0)
            return 0;
        if (i == coins.size())
        {

            return 1e8;
        }
    
        if ( dp[i][amount] != -1)
            return dp[i][amount];
        int tex1 = 1e8;
        tex1 = count(coins, amount, i + 1);
        if (coins[i] > amount)
            return tex1;
        else
        {

            int tex2 = 1 + count(coins, amount - coins[i], i);
            int j = min(tex1, tex2);
            dp[i][amount] = j;
            
            return j;
        }
        return 1;
    }
    public:
        int coinChange(vector<int> &coins, int amount)
        {
            
            int n = coins.size();
            vector<vector<int>>matrix(n+1,vector<int>(amount+1,-1));
            dp = matrix;
            cout<<dp[0].size();
            int ans = count(coins, amount, 0);
            if (ans == 1e8 + 1 or ans == 1e8)
            {
                return -1;
            }
            return ans;
        }
};