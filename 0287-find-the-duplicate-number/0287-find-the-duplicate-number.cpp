class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++){
            if(set.contains(nums[i])){
                return nums[i];
            }
            else{
                set.insert(nums[i]);
            }
        }
        return -1;
    }
};