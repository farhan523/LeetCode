class Solution {
public:
    bool isPowerOfThree(int n) {
         if(n <=0 )
            return false;
       int b = log10(n) / log10(3);
        cout<<b;
        if(pow(3,b) == n)
            return true;
        return false;
    }
};