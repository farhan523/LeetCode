class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int li;
        for(int i=0;i<matrix.size();i++){
             li = matrix[i].size() - 1;
            if(matrix[i][li] >= target){
                for(int j=0;j<=li;j++){
                    if(matrix[i][j] == target)
                        return true;
                }
                return false;
            }
        }
        return false;
    }
};