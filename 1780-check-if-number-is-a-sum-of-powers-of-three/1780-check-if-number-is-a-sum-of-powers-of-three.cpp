class Solution {
public:
    bool checkPowersOfThree(int n) {
       
       vector<int>temp;
       int count = 0;
            while (n >= 1)
            {
               if(n % 3 > 1)
                   return false;
                n = n / 3;
            }
     return true;   
    }
};