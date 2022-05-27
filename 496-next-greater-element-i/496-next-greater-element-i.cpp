class Solution
{
    public:
        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &num2)
        {
           stack<int>stk;
            unordered_map<int,int>mp;
            mp.insert({num2[num2.size() -1],-1});
            stk.push(num2[num2.size()-1]);
            for(int i = num2.size()-2;i>=0;i--){
                while(stk.size() > 0 and stk.top() < num2[i])
                        stk.pop();
                if(!stk.empty())
                    mp.insert({num2[i],stk.top()});
                else
                    mp.insert({num2[i],-1});
                stk.push(num2[i]);
            }
            
            vector<int>res;
            
            for(int i=0;i<nums1.size();i++){
                res.push_back(mp.find(nums1[i])->second);
            }
            return res;
        }
};