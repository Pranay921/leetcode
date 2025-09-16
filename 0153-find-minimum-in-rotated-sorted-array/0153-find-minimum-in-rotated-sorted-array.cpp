class Solution {
public:
    int findMin(vector<int>& nums) {
        int index=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                index=i;
                break;
            }
        }
        if(index==-1) index=0;
        return nums[index];
    }
};