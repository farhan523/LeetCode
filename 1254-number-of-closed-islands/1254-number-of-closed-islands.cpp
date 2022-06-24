class Solution {
    bool  isClosedIsland = true;
    int row;
    int col;
    
    void depthFirstSearch(vector<vector<int>>& grid,int r,int c){
        if(grid[r][c] == 1 || grid[r][c] == 2)
            return;
        if(r + 1 >= row || c + 1 >= col || r-1 < 0 || c-1 < 0)
            isClosedIsland = false;
        grid[r][c] = 2;
        if(r+1 < row)
            depthFirstSearch(grid,r+1,c);
        if(c + 1 < col)
            depthFirstSearch(grid,r,c+1);
        if(r-1 >= 0)
            depthFirstSearch(grid,r-1,c);
        if(c-1 >=0)
            depthFirstSearch(grid,r,c-1);
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        row = grid.size();
        col = grid[0].size();
        for(int i =1;i<grid.size()-1;i++){
            for(int j = 1;j<grid[0].size() - 1;j++){
                if(grid[i][j] != 2 and grid[i][j] != 1){
                    depthFirstSearch(grid,i,j);
                     if(isClosedIsland)
                            count++;
                    isClosedIsland = true;
                }
                    
               
            }
        }
        return count;
    }
};