class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>s1;
       
        for(int x:nums1){
            if(s1.find(x) == s1.end()){
                s1.insert(make_pair(x,1));
            }else{
                s1.find(x)->second++;
            }
        }
        
        vector<int>result;
        for(int i=0;i<nums2.size();i++){
               if(s1.find(nums2[i]) != s1.end()){
                   result.push_back(nums2[i]);
                   if(s1.find(nums2[i])->second == 1)
                       s1.erase(nums2[i]);
                   else
                       s1.find(nums2[i])->second--;
               }   
                
        }
        return result;
    }
};