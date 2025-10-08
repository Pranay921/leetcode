class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(height.size());
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }

        vector<int> right(height.size());
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        int watertrapped=0;
        for(int i=0;i<n;i++){
            int maxheight=min(left[i],right[i]);
            watertrapped+=maxheight-height[i];
        }
        return watertrapped;
    }
};