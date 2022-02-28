class Solution {
public:
    int subtractProductAndSum(int n) {
        string str; 
         str = to_string(n);
        int prod = 1,sum = 0;
        for(char x : str){
            sum += x - '0';
            prod*= x - '0';
        }
        return prod - sum;
    }
};