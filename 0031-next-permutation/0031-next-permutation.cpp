class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int circle_index=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                circle_index=i;
                break;
            }
        }
        int swap_index=-1;
        if(circle_index!=-1){
            for(int i=nums.size()-1;i>circle_index;i--){
                if(nums[i]>nums[circle_index]){
                    swap_index=i;
                    break;
                }
            }
            swap(nums[circle_index],nums[swap_index]);
            reverse(nums.begin()+circle_index+1,nums.end());
        }
        else{
            reverse(nums.begin(),nums.end());
        }
    }
};