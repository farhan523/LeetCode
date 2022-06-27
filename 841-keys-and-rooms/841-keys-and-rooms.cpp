class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>roomKeys;
        set<int>visited;
        visited.insert(0);
        roomKeys.push(0);
        while(!roomKeys.empty()){
            int size = roomKeys.size();
            for(int i=0;i<size;i++){
                int front = roomKeys.front();
                for(int j=0;j<rooms[front].size();j++){
                    if(visited.find(rooms[front][j]) == visited.end()){
                        visited.insert(rooms[front][j]);
                        roomKeys.push(rooms[front][j]);
                    }
                  
                }
                  roomKeys.pop();
            }
        }
        return visited.size() == rooms.size();
    }
};