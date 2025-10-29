class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        return helper(source, destination, adj, vis);
    }

    bool helper(int src, int dest, vector<vector<int>>& edges, vector<bool> &vis) {
        if(edges.size()==1) return true;
        vis[src] = true;
        vector<int> neighbours = edges[src];
        for (auto u : neighbours) {
            if (u == dest) return true;
            if (!vis[u] && helper(u, dest, edges, vis)) return true;
        }
        return false;
    }
};
