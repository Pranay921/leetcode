class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<int> rr={-1,0,1,0};
        vector<int> cc={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int j=0;j<m;j++){
                matrix[r][j]=0;
            }
            for(int j=0;j<n;j++){
                matrix[j][c]=0;
            }
        }
    }
};