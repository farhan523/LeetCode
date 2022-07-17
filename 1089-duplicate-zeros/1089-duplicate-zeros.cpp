class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int>res;
        for(int x:arr){
            if(x == 0){
                res.push_back(0);
            }
            if(res.size() == arr.size()){
                arr = res;
                break;
            }
               
            res.push_back(x);
        }
      for(int i=0;i<arr.size();i++)
                arr[i] = res[i];
    }
};