class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>subset;
        vector<int>aux;
        subset.push_back(aux);
        aux.push_back(nums[0]);
        subset.push_back(aux);
        int size ;
        for(int i=1;i<nums.size();i++){
            size = subset.size();
            for(int k=0;k<size;k++){
                aux = subset[k];
                aux.push_back(nums[i]);
                subset.push_back(aux);
            }
        }
        return subset;
    }
};