class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>mp;
         vector<string> result;
        for(int i=0;i<list1.size();i++)
            mp.insert({list1[i],i});
        int minSum = INT_MAX;
         for(int i=0;i<list2.size();i++){
             auto it = mp.find(list2[i]);
             if(it != mp.end()){
                 if(it->second + i < minSum){
                     minSum = it->second + i;
                    result.clear();
                     result.push_back(list2[i]);
                 }else if(it->second + i == minSum){
                      result.push_back(list2[i]);
                 }
             }
         }
           return result; 
    }
};