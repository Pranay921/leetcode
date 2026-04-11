class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inOrder(numCourses,0);
        for(auto e:prerequisites){
            adj[e[1]].push_back(e[0]);
            inOrder[e[0]]++;
        }
        int c=0;
        queue<int> q;
        for(int i=0;i<inOrder.size();i++){
            if(inOrder[i]==0) q.push(i);
        }
        while(!q.empty()){
            int top=q.front();
            q.pop();
            c++;
            for(auto it: adj[top]){
                inOrder[it]--;
                if(inOrder[it]==0) q.push(it);
            }
        }
        if(c==numCourses) return true;
        return false;
    }
};