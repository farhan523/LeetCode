class Solution {
    vector<vector<int>>matrix;
    vector<vector<int>>res;
    vector<int>temp;
    int target;
    int reached = false;
    
    void traverse(int src){
        
        
        for(int i=0;i<matrix[src].size();i++){
            temp.push_back(src);
                if(matrix[src][i] == target){
                    temp.push_back(target);
                    reached = true;
                  
                }
            if(reached){
                res.push_back(temp);
                reached = false;
               temp.pop_back();
                temp.pop_back();
                continue;
            }
            traverse(matrix[src][i]);
            temp.pop_back();
            
    }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        matrix = graph;
        target = graph.size() -1;
        traverse(0);
        return res;
    }
};