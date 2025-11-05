class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if(arr.size()==1 || arr.size()==0) return {-1};
        vector<int> right(arr.size());
        right[arr.size()-1]=-1;
        for(int i=arr.size()-2;i>=0;i--){
            right[i]=max(arr[i+1],right[i+1]);
        }
        return right;
    }
};