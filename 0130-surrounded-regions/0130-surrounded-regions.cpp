class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        queue<pair<int,int>> q;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1){
                    if(board[i][j]=='O'){
                        visited[i][j]=true;
                        q.push({i,j});
                    }
                }
            }
        }
        vector<int> rr={-1,0,1,0};
        vector<int> cc={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newR=r+rr[i];
                int newC=c+cc[i];
                if(newR>=0 && newR<board.size() && newC>=0 && newC<board[0].size() && board[newR][newC]=='O' && !visited[newR][newC]){
                    visited[newR][newC]=true;
                    q.push({newR,newC});
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(!visited[i][j]){
                    board[i][j]='X';
                }
                else{
                    board[i][j]='O';
                }
            }
        }
    }
};