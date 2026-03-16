class Solution {
public:
    bool helper(int source,int dest,vector<vector<int>> &edges,vector<bool> &visited){
        if(source==dest) return true;
        visited[source]=true;
        // vector<int> neighbours=edges[source];
        for(int i:edges[source]){
            if(!visited[i]){
                if(helper(i,dest,edges,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);         // FIX: create adjacency list

        for(auto &e:edges){                 // FIX: convert edge list to adjacency list
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return helper(source,destination,adj,visited);
    }
};