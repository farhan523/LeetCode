class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it = lower_bound(arr.begin(),arr.end(),x);
        
        int index = it - arr.begin();
        vector<int> res;
        int a = index-1;
        int b = index;
        while(a>=0 && b<arr.size() && res.size() < k){
            if(abs(arr[a] - x) < abs(arr[b] - x) || (abs(arr[a] - x) == abs(arr[b] - x) && arr[a] < arr[b] )){
                res.push_back(arr[a--]);
                
            }else{
                res.push_back(arr[b++]);
            }
        }
        
        while(res.size() < k && b < arr.size()){
            res.push_back(arr[b++]);
        }
        while(res.size() < k && a >=0){
            res.push_back(arr[a--]);
        }
        
       sort(res.begin(),res.end());
        return res;
    }
};