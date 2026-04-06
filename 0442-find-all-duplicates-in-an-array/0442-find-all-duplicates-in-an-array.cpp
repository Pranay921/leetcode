class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        vector<int> freq(nums.size()+1,-1);
        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]]!=-1){
                result.push_back(nums[i]);
            }
            else{
                freq[nums[i]]++;
            }
        }
        return result;
    }
};