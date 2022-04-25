class Solution {
public:
    int tribonacci(int n) {
         if(n == 0 || n == 1) return n;
        if(n == 2) return 1;
        int num0 = 0;
        int num1 = 1;
        int num2 = 1;
        int num3;
        for(int i = 3;i<=n;i++){
            num3 = num0 + num1 + num2;
            num0 = num1;
            num1 = num2;
            num2 = num3;
        }
        return num3;
    }
};