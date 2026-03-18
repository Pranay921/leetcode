class Solution {
public:
    void DFS(int u,vector<bool> &visited,vector<vector<int>> &isConnected){
        visited[u]=true;
        // for(int i:isConnected[u]){
        //     if(!visited[i]){
        //         DFS(i,visited,isConnected);
        //     }
        // }//aise adjancy list mein check karte hain lekin yaha par adjacency matrix hain 
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[u][i]==1 && !visited[i]){
                 DFS(i,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        vector<bool> visited(isConnected.size(),false);
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                count++;
                DFS(i,visited,isConnected);
            }
        }
        return count;
    }
};