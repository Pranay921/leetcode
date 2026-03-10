class Solution {
public:
    bool checker(vector<vector<int>>& matrix,int i,int target){
        int m=matrix[i].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[i][mid]==target){
                return true;
            }
            else if(target>matrix[i][mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if(checker(matrix,i,target)){
                return true;
            }
        }
        return false;
    }
};