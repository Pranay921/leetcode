class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> map;
        int missingNumber;
        for(int i=0;i<n;i++){
            missingNumber=target-nums[i];
            if(map.count(missingNumber)){
                return {map[missingNumber],i};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};