class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOne = 0;
        int soFarMax = 0;
        for(int x:nums){
            if(x == 1){
                soFarMax++;
            }else{
                if(soFarMax > maxOne)
                    maxOne = soFarMax;
                soFarMax = 0;
            }
        }
         if(soFarMax > maxOne)
                maxOne = soFarMax;
        return maxOne;
    }
};