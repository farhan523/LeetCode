class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vector2;
        map<int, int> mp;
        for(int i=0 ; i<nums.size();i++){
                
                map<int, int>::iterator  it = mp.find(nums[i]);
                if(it != mp.end()){
                    vector2.push_back(it->second);
                    vector2.push_back(i);
                    return vector2;
                }else{
                    mp.insert({target-nums[i],i});
                }
                        
            
        }
        return vector2;
    };  
};