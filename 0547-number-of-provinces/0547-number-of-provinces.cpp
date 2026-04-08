class Solution {
public:
    void DFS(int i,vector<bool> &visited,vector<vector<int>> &nums){
        visited[i]=true;
        for(int j=0;j<nums.size();j++){
            if(!visited[j] && nums[i][j]==1){
                DFS(j,visited,nums);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int c=0;
        vector<bool> visited(n,false);
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                c++;
                DFS(i,visited,isConnected);
            }
        }
        return c;
    }
};