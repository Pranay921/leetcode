class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1,maxWater=0;
        while(i!=j){
            int minHeight=min(height[i],height[j]);
            int width=j-i;
            int totalWaterTrapped=minHeight*width;
            maxWater=max(maxWater,totalWaterTrapped);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxWater;
    }
};