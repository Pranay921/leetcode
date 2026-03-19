class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        queue<pair<int,int>> q;
        int original=grid[sr][sc];
        q.push({sr,sc});
        grid[sr][sc]=color;
        visited[sr][sc]=true;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            vector<int> rr={-1,0,1,0};
            vector<int> cc={0,1,0,-1};
            for(int i=0;i<4;i++){
                int neighbR=rr[i]+r;
                int neighbC=cc[i]+c;
                if(neighbR>=0 && neighbR<n && neighbC>=0 && neighbC<m && !visited[neighbR][neighbC] && grid[neighbR][neighbC]==original){
                    visited[neighbR][neighbC]=true;
                    q.push({neighbR,neighbC});
                    grid[neighbR][neighbC]=color;
                }
            }
        }
        return grid;
    }
};