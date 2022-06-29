class Solution {
    set<int> terminalNode;
    set<int>visitedNode;
    vector<int>safeNodeRes;
    set<int>safeNode;
    bool reached = false;
    void depthFirstSearch(vector<vector<int>>& graph,int node){
         if(terminalNode.find(node) != terminalNode.end()){
            reached = true;
            return;
        }
        if(visitedNode.find(node) != visitedNode.end() and safeNode.find(node) != safeNode.end()){
            reached = true;
            return; 
        }else if(visitedNode.find(node) != visitedNode.end()){
            reached = false;
            return;
        }
           
       
            
        
        visitedNode.insert(node);
        for(int i=0;i<graph[node].size();i++){
            reached = false; 
            depthFirstSearch(graph,graph[node][i]);
           
              
                if(!reached)
                    return;
                   
        }
         safeNodeRes.push_back(node);
        safeNode.insert(node);
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        for(int i=0;i<graph.size();i++){
            if(graph[i].size() == 0)
                terminalNode.insert(i);
            
        }
        for(int i=0;i<graph.size();i++){
            if(terminalNode.find(i) != terminalNode.end())
                continue;
            depthFirstSearch(graph,i);
             reached = false;
            
        }
         for(int i=0;i<graph.size();i++){
            if(terminalNode.find(i) != terminalNode.end()){
                safeNodeRes.push_back(i);
            }
                
           
            
        }
        
        sort(safeNodeRes.begin(),safeNodeRes.end());
        return safeNodeRes;
    }
};