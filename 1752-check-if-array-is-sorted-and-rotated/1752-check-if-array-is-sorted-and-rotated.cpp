class Solution {
public:
    bool check(vector<int>& nums) {
        int c=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                c++;
                if(c>1) return false;
            }
        }
        if(nums[0]<nums[nums.size()-1]) c++;
        return (c>1)?false :true;
    }
};