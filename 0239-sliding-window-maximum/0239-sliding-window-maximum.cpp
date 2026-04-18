class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int> result;
        // for(int i = 0; i <= nums.size() - k; i++){
        //     int j = i, maxNum = INT_MIN;
        //     while(j < i + k){
        //         if(nums[j] > maxNum) maxNum = nums[j];
        //         j++;
        //     }
        //     result.push_back(maxNum);
        // }
        // return result;

        //2nd
        // vector<int> result;
        // for(int i=0;i<=nums.size()-k;i++){
        //     int maxNum=INT_MIN;
        //     for(int j=i;j<i+k;j++){
        //         if(nums[j]>maxNum) maxNum=nums[j];
        //     }
        //     result.push_back(maxNum);
        // }
        // return result;

        //3rd
        multiset<int> s;
        vector<int> result;
        for(int i=0;i<k;i++){
            s.insert(nums[i]);
        }
        result.push_back(*s.rbegin());
        for(int i=k;i<nums.size();i++)
        {
            s.erase(nums[i-k]);
            s.insert(nums[i]);
            result.push_back(*s.rbegin());
        }
        return result;
        
        //4th
        // vector<int> result;
        // int i=0,j=0;
        // while(i<=nums.size()-k){
        //     int maxEl=INT_MIN;
        //     j=i;
        //     while(j<i+k){
        //         maxEl=max(maxEl,nums[j]);
        //         j++;
        //     }
        //     result.push_back(maxEl);
        //     i++;
        // }
        // return result;
    }
};
