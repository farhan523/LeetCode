class Solution {
public:
    string convertToBase7(int num) {
        string res;
        bool isLess = false;
        if(num < 0)
            isLess = true;
        num = abs(num);
        while(num >= 7){
            int n = num % 7;
            num = num / 7;
            res += to_string(n);
        }
        
        res +=  to_string(num);
        if(isLess)
            res += "-";
        reverse(res.begin(),res.end());
        
        return res;
    }
};