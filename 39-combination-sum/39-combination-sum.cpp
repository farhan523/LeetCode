class Solution {
    vector<vector<int>>res;
    vector<int> cand;
        
    void getSum(vector<int>& temp,int target,int index){
        if(target == 0){
             res.push_back(temp);
            return;
        }
        
        
        for(int i=index;i<cand.size();i++){
            if(target >= cand[i]){
                target -= cand[i];
                temp.push_back(cand[i]);
                getSum(temp,target,i);
                target += cand[i];
                temp.pop_back();
            }
        }
           
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        cand = candidates;
        vector<int> temp;
        getSum(temp,target,0);
        return res;
    }
};