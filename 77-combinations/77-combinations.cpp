class Solution
{
    vector<vector < int>> result;
    vector<int> res;
 
    void combinations(vector<int> num, int index,int k)
    {
        if (index > num.size())
            return;
      
        
        
        for (int i = index; i < num.size(); i++)
        {
            res.push_back(num[i]);
           
           k--;
            if(k==0){
                result.push_back(res);
                res.pop_back();
                k++;
            }else{
                combinations(num,i+1,k);
                res.pop_back();
                k++;
            }
           
        }
       
    }
    public:
        vector<vector < int>> combine(int n, int k)
        {
            vector<int> num;
            
            for (int i = 1; i <= n; i++)
                num.push_back(i);
            combinations(num, 0,k);
            return result;
        }
};