class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s=0,maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            s=s+nums[i];
            maxsum=max(maxsum,s);
            if(s<=0){
                s=0;
            }
        }
        return maxsum;
    }
};