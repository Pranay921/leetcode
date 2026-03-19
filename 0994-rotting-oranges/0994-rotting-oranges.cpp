class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> visited(grid.size(),vector<bool> (m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        int time=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(time,t);
            vector<int> neighR={-1,0,1,0};//top right bottom left
            vector<int> neighC={0,1,0,-1};//top right bottom left
            for(int i=0;i<4;i++){
                int rr=r+neighR[i];
                int cc=c+neighC[i];
    if(rr>=0 && rr<n && cc>=0 && cc<m && !visited[rr][cc] && grid[rr][cc]==1)            {
                    visited[rr][cc]=true;
                    q.push({{rr,cc},t+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};