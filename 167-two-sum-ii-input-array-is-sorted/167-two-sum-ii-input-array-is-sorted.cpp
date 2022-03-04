class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(int i =0;i<numbers.size();i++){
            auto it = mp.find(numbers[i]);
            if(it == mp.end()){
                mp.insert({target - numbers[i],i});
                
            }else{
                res.push_back(it->second + 1);
                res.push_back(i + 1);
                return res;
            }
            
        }
        return res;
    }
};