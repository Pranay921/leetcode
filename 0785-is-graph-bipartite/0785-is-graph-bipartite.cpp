class Solution {
public:
    bool BFS(int u,vector<bool> &visited,vector<vector<int>> &grid,vector<int> &color){
        queue<int> q;
        q.push(u);
        visited[u]=true;
        color[u]=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            vector<int> neighbours=grid[x];
            for(int z:neighbours){
                if(!visited[z]){
                    visited[z]=true;
                    color[z]=!color[x];
                    q.push(z);
                }
                else{
                    if(color[z]==color[x]) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(),false);
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                if(!BFS(i,visited,graph,color))return false;
            }
        }
        return true;
    }
};