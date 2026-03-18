// class Solution {
// public:
//     void DFS(int u,vector<bool> &visited,vector<vector<int>> &isConnected){
//         visited[u]=true;
//         // for(int i:isConnected[u]){
//         //     if(!visited[i]){
//         //         DFS(i,visited,isConnected);
//         //     }
//         // }//aise adjancy list mein check karte hain lekin yaha par adjacency matrix hain 
//         for(int i=0;i<isConnected.size();i++){
//             if(isConnected[u][i]==1 && !visited[i]){
//                  DFS(i,visited,isConnected);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int count=0;
//         vector<bool> visited(isConnected.size(),false);
//         for(int i=0;i<isConnected.size();i++){
//             if(!visited[i]){
//                 count++;
//                 DFS(i,visited,isConnected);
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:
    void DFS(int u,vector<bool> &visited,vector<vector<int>> &isConnected){
        visited[u]=true;
        for(int v:isConnected[u]){
            if(!visited[v]){
                DFS(v,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjList(isConnected.size());
        int rows=isConnected.size();
        int cols=isConnected[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(isConnected[i][j]==1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<bool> visited(adjList.size(),false);
        for(int i=0;i<adjList.size();i++){
            if(!visited[i]){
                count++;
                DFS(i,visited,adjList);
            }
        }
        return count;
    }
};