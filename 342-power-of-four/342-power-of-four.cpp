class Solution {
public:
    bool isPowerOfFour(int n) {
         if(n <=0 )
            return false;
       int b = log10(n) / log10(4);
        cout<<b;
        if(pow(4,b) == n)
            return true;
        return false;
    }
};