class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>stk;
        for(auto  x : s){
            if(!stk.empty() and stk.top() == x)
                stk.pop();
            else
                stk.push(x);
        }
        string res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};