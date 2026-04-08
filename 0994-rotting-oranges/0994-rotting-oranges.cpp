class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        vector<int> rr={-1,0,1,0};
        vector<int> cc={0,1,0,-1};
        int maxCount=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int count=q.front().second;
            q.pop();
            maxCount=max(maxCount,count);
            for(int i=0;i<4;i++)
            {
                int newR=r+rr[i];
                int newC=c+cc[i];
                if(newR>=0 && newR<grid.size() && newC>=0 && newC<grid[0].size() && !visited[newR][newC] && grid[newR][newC]==1){
                    // grid[newR][newC]=2;
                    visited[newR][newC]=true;
                    q.push({{newR,newC},count+1});
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return maxCount;
    }
};