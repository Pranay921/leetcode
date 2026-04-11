class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        vector<int> inOrder(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(auto it: graph[i]){
                adj[it].push_back(i);
                inOrder[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<inOrder.size();i++){
            if(inOrder[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            topo.push_back(top);
            for(auto it:adj[top]){
                inOrder[it]--;
                if(inOrder[it]==0) q.push(it);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};