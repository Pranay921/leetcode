class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int p=1,maxproduct=INT_MIN;
        // for(auto i:nums){
        //     p=p*i;
        //     maxproduct=max(maxproduct,p);
        //     if(p<=0 && i+1<nums.size() && nums[i+1]>=0){
        //         p=1;
        //     }
        // }
        // return maxproduct;
        int prefix=1,suffix=1,maxprefix=INT_MIN,maxsuffix=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
            prefix=prefix*nums[i];
            maxprefix=max(maxprefix,prefix);
            suffix=suffix*nums[nums.size()-1-i];
            maxsuffix=max(maxsuffix,suffix);
        }
        return (int)max(maxprefix,maxsuffix);
    }
};