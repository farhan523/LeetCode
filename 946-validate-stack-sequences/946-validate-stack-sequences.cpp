class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=1;
        int j =0;
        stack<int>stk;
        stk.push(pushed[0]);
        while(i<pushed.size()){
            while(j<popped.size() && stk.top() == popped[j]){
                stk.pop();
                j++;
                if(stk.empty())
                    break;
            }
            stk.push(pushed[i++]);
            
        }
        while(!stk.empty()){
            if(stk.top() != popped[j])
                return false;
            j++;
            stk.pop();
        }
        return true;
    }
};