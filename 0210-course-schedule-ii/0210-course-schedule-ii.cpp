class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topo;
        vector<vector<int>> adj(numCourses);
        vector<int> inOrder(numCourses,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            inOrder[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<inOrder.size();i++){
            if(inOrder[i]==0) q.push(i);
        }

        while(!q.empty()){
            int top=q.front();
            q.pop();
            topo.push_back(top);
            for(auto it:adj[top]){
                inOrder[it]--;
                if(inOrder[it]==0) q.push(it);
            }
        }
        if(topo.size()==numCourses) return topo;
        return {};
    }
};