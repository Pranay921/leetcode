class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,s=0;
        int minL=INT_MAX;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum<target) return 0;
        while(j<nums.size()){
            s+=nums[j];
            while(s>=target){
                s-=nums[i];
                minL=min(minL,j-i+1);
                i++;
            }
            j++;
        }
        return minL;
    }
};