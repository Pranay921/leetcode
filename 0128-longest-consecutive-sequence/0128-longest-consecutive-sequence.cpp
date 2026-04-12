class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int maxL=0;
        int i=0,j=0;
        while(j<nums.size()-1){
            if(nums[j]==nums[j+1]){
                j++;
                i++;
            }
            else if(nums[j]+1==nums[j+1]){
                j++;
            }
            else{
                maxL=max(maxL,j-i+1);
                j++;
                i=j;
            }
        }
        maxL=max(maxL,j-i+1);
        return maxL;
    }
};