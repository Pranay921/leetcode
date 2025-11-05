class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int s=nums[0],maxSum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                s+=nums[i];
            }
            else{
                s=nums[i];
            }
                maxSum=max(maxSum,s);
        }
        return maxSum;
    }
};