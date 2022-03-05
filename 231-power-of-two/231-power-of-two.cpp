class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <=0 )
            return false;
       int b = log(n) / log(2);
        if(pow(2,b) == n)
            return true;
        return false;
    }
};