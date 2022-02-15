class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int maxPrise = 0;
      
        for(int i = prices.size() - 1;i>=0;i--){
          
                if(prices[i] < maxPrise && maxPrise - prices[i] > profit)
                    profit = maxPrise - prices[i];
                
                if(maxPrise < prices[i]){
                    maxPrise = prices[i];
                
                    
            }
            
        }
        return profit;
    }
};