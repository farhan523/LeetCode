class Solution
{
    public:
        void sortColors(vector<int> &nums)
        {
            int num1 = 0;
            int num0 = 0;
            int num2 = 0;
            for(int x : nums){
                if(x == 0)num0++;
                else if(x == 1) num1++;
                else num2++;
            }
            int i = 0;
            while(num0 > 0){
                nums[i++] = 0;
                num0--;
            }
            while(num1 > 0){
                nums[i++] = 1;
                num1--;
            }
            while(num2 > 0){
                nums[i++] = 2;
                num2--;
            }
        }
};