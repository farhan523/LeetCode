#include<stack>
class Solution {
public:
    bool isOpen(char s){
        if(s == '(' || s == '{' || s == '[')
            return true;
        return false;
    }
    
    bool isValidPair(char s,char s1){
        if( s == ')' && s1 == '(')
            return true;
         if( s == '}' && s1 == '{')
            return true;
         if( s == ']' && s1 == '[')
            return true;
        return false;
    }
    
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            if(isOpen(s[i]))
                stk.push(s[i]);
            else{
                if(stk.size()== 0)
                    return false;
                else{
                    if(isValidPair(s[i],stk.top())){
                        stk.pop();
                    }else{
                        return false;
                    }
                    
                }
            }
        }
        if(stk.empty())
            return true;
        return false;
    }
};