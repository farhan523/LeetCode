class Solution {
    queue<pair<int,int>>que;
    vector<vector<int>>matrix;
    int row;
    int col;
    int endR,endC;
    int count =0;
    bool reached = false;
    bool diagonalMove(int r, int c)
    {
        if (r + 1 < endR and c + 1 < endC and matrix[r+1][c+1] == 0)
            return true;
        return false;
    }
    
    bool nextRow(int r,int c){
         if (r + 1 < endR  and matrix[r+1][c] == 0)
            return true;
        return false;
    }
    
    bool nextCol(int r ,int c){
        if (c +1  < endC and matrix[r][c+1] == 0)
            return true;
        return false;
    }
    
    bool diagonal2(int r,int c){
        if (r - 1 >= 0 and c + 1 < endC and matrix[r-1][c+1] == 0)
            return true;
        return false;
    }
    
    bool previousRow(int r,int c){
         if (r - 1 >= 0  and matrix[r-1][c] == 0)
            return true;
        return false;
    }
    
    bool diagonal3(int r,int c){
         if (r - 1 >= 0 and c - 1 >= 0 and matrix[r-1][c-1] == 0)
            return true;
        return false;
    }
    
    bool previousCol(int r,int c){
         if (c - 1 >= 0  and matrix[r][c-1] == 0)
            return true;
        return false;
    }
    

    bool diagonal4(int r,int c){
         if (r + 1 < row and c - 1 >=0 and matrix[r+1][c-1] == 0)
            return true;
        return false;
    }
    
    void breadthFirstSearch(int r,int c){
        
        if(r == row-1 and c == col-1){
            reached = true;
            return;
        }
        if(diagonalMove(r,c)){
             que.push({r+1,c+1});
            matrix[r+1][c+1] = 2;
        }
           
        if(nextRow(r,c)){
            que.push({r+1,c});
             matrix[r+1][c] = 2;
        }
            
        if(nextCol(r,c)){
            que.push({r,c+1});
            matrix[r][c+1] = 2;
        }
            
        if(diagonal2(r,c)){
             que.push({r-1,c+1});
            matrix[r-1][c+1] = 2;
        }
           
        if(diagonal4(r,c)){
            que.push({r+1,c-1});
               matrix[r+1][c-1] = 2;
        }
            
        if(previousRow(r,c)){
            que.push({r-1,c});
             matrix[r-1][c] = 2;
        }
            
        if(previousCol(r,c)){
             que.push({r,c-1});
             matrix[r][c-1] = 2;
        }
           
        if(diagonal3(r,c)){
             que.push({r-1,c-1});
             matrix[r-1][c-1] = 2;
        }
           
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         row = endR =  grid.size();
         col = endC =  grid.size();
        if(grid[0][0] != 0 || grid[row-1][col-1] != 0)
            return -1;
        que.push({0,0});
            count++;
            matrix = grid;
            matrix[0][0] = 2;
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                if(que.front().first == row-1 && que.front().second == col-1)
                    return count;
                breadthFirstSearch(que.front().first,que.front().second);
                que.pop();
               
            }
             if(reached)
                    return count;
            count++;
            
        }
        
        return -1;
    }
};