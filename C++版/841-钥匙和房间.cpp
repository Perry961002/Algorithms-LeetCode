class Solution {
public:
    void dfs(int roomId, vector<vector<int>>& rooms, vector<bool>& visited){
        //从当前房间开始深搜
        visited[roomId] = true;
        for(auto nextRoom : rooms[roomId]){
            if(!visited[nextRoom])
                dfs(nextRoom, rooms, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int count = rooms.size();
        vector<bool> visited(count, false);
        visited[0] = true;
        for(auto room : rooms[0])
            dfs(room, rooms, visited);
        for(int i=0;i<count;i++)
            if(!visited[i])
                return false;
        return true;
    }
};