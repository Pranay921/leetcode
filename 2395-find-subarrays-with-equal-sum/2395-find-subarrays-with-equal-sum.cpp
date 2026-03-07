class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        int s=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            s=nums[i]+nums[i+1];
            if(mp.count(s)){
                return true;
            }
            mp[s]++;
        }
        return false;
    }
};