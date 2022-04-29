class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         bool isZero = false;
        bool isOne = false;
        int product = 1;
        int numberOfZero = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1)
                isOne = true;
            if(0 == nums[i]){
                 isZero = true;
                numberOfZero++;
                continue;
            }
               
            product *= nums[i];
        }
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0 and !isZero and numberOfZero < 2){
                res.push_back(product / nums[i]);
            }else if(nums[i] == 0 and product != 1 and numberOfZero < 2){
                res.push_back(product);
            }else if(nums[i] == 0 and isOne and numberOfZero < 2){
                res.push_back(product);
            }
            else
                res.push_back(0);
        }
        return res;
    }
};