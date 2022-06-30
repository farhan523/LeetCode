class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        if(mat.size()==1)
            return mat[0][0];
        if(mat.size() % 2 != 0){
            int n = mat.size() / 2 ;
            cout<<n;
            sum -= mat[n][n];
        }
        
        int r = 0;
        int c = 0;
        while(r < mat.size()){
            sum += mat[r][c];
            r += 1;
            c += 1;
        }
        
        r = 0;
        c = mat.size()-1;
        while(r < mat.size()){
           sum += mat[r][c];
            r += 1;
            c -= 1;
        }
        return sum;    
    }
};