class Solution {
public:
    void bfs(int row,int col,vector<vector<int>> &visited,vector<vector<char>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=true;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int r=q.front().first;
            int c =q.front().second;
            q.pop();
            vector<int> delRow = {-1, 0, 1, 0};
            vector<int> delCol = {0, 1, 0, -1};
            for(int k = 0; k < 4; k++){
                int nRow = r + delRow[k];
                int nCol = c + delCol[k];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m &&
                grid[nRow][nCol]=='1' && !visited[nRow][nCol]){
                    visited[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return count;
    }
};