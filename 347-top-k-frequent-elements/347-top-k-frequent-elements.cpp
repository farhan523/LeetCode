class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         map<int, int> freq;
        for(int i=0;i<nums.size();i++){
            map<int, int>::iterator itr;
             itr = freq.find(nums[i]);
            if(itr == freq.end()){
                freq.insert({ nums[i], 1 });
            }else{
                itr->second++;
            }
        }
        vector<int> freqValues;
         for (auto itr = freq.begin(); itr != freq.end(); itr++) {
                freqValues.push_back(itr->second);
        
         }
      
            sort(freqValues.begin(), freqValues.end(), greater<int>());

        vector<int>result;
        for(int i=0;i<k;i++){
            for (auto itr = freq.begin(); itr != freq.end(); itr++) {
                if(itr->second == freqValues[i]){
                    result.push_back(itr->first);
                    freq.erase(itr);
                }
                    
                
         }
        }
        return result;
    }
};