class Solution
{
     vector<vector < int>> subset;
    vector<int>aux;
    void subSets(vector<int> &nums,int index){
        if (index == nums.size()){
            subset.push_back(aux);
            return;
        }
                
        subSets(nums,index + 1);
        aux.push_back(nums[index]);
        subSets(nums,index+1);
        aux.pop_back();
    }
    
    public:
        vector<vector < int>> subsets(vector<int> &nums)
        {
           subSets(nums,0);
            return subset;
          
            
        }
};