class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        int revIndex=n-k;
        reverse(nums.begin()+revIndex,nums.end());
        reverse(nums.begin(),nums.begin()+revIndex);
        reverse(nums.begin(),nums.end());
    }
};