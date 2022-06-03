class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0] == target)
                return true;
            if(matrix[i][0] > target)
                break;
            if(matrix[i][0] <= target and matrix[i][matrix[i].size() -1] >= target){
                bool res =  binary_search(matrix[i].begin(),matrix[i].end(),target);
                if(res)
                    return res;
            }
                
        }
        return false;
    }
};