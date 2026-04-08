class Solution {
public:
    void DFS(int i,vector<bool> &visited,vector<vector<int>> &adjList){
        visited[i]=true;
        for(int j:adjList[i]){
            if(!visited[j]){
                DFS(j,visited,adjList);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& nums) {
        vector<vector<int>> adjList(nums.size());
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i][j]==1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int c=0;
        vector<bool> visited(nums.size(),false);
        for(int i=0;i<adjList.size();i++){
            if(!visited[i]){
                c++;
                DFS(i,visited,adjList);
            }
        }
        return c;
    }
};