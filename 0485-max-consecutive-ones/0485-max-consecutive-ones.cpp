class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size()==1 && nums[0]==1) return 1;
        if(nums.size()==1 && nums[0]==0) return 0;
        int maxc=0,c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                c++;
                maxc=max(c,maxc);
            }
            else{
                c=0;
            }
        }
        return maxc;
    }
};