class Solution {
public:
    bool isThree(int n) {
        
            int gcd = 1;
            for (int i = 2; i <= n; i++)
            {
                if (n % i == 0)
                        gcd++;
            }
            return gcd == 3 ? true : false;
    }
};