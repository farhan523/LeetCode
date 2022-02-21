class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
            unordered_map<int,int>mp;
        vector<int>result;
        for(int x:nums){
            auto it = mp.find(x) ;
            if(it == mp.end()){
                mp.insert({x,1});
            }else{
                it->second++;
            }
            
        }
         for(int x:nums){
            auto it = mp.find(x) ;
           if(it != mp.end() && it->second > (nums.size() / 3)){
               result.push_back(it->first);
               mp.erase(it);
           }
             
            
        }
        return result;
    
    }
};