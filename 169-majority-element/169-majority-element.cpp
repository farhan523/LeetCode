class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
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
           if(it->second > (nums.size() / 2)){
               return it->first;
           }
             
            
        }
        return 1;
    }
};