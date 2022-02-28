class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> res( r , vector<int> (c, 0));
        if(r * c != mat.size() * mat[0].size())
            return mat;
        vector<int>tmp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                tmp.push_back(mat[i][j]);
            }
        }
        int count = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                res[i][j] = tmp[count++];
            }
        }
        return res;
    }
};