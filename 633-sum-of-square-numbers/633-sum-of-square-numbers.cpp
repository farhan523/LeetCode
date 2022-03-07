class Solution {
public:
    bool judgeSquareSum(int c) {
       unordered_map<long long, long long> s;
        int n = c;
    for (long i = 0; i * i <= n; ++i) {
 
        // store square value in hashmap
        s[i * i] = 1;
        if (s.find(n - i * i) != s.end()) {
           
            return true;
        }
    }
    return false;
        
    }
};