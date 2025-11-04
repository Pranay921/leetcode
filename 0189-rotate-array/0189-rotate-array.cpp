class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //brute
        // for(int i=0;i<k;i++){
        // int temp=nums[nums.size()-1];
        //     for(int j=nums.size()-2;j>=0;j--){
        //         nums[j+1]=nums[j];
        //     }
        // nums[0]=temp;
        // }

        //better
         int n = nums.size();
        k = k % n;
        vector<int> temp(k);
        int j = 0;

        for (int i = n - k; i < n; i++) {
            temp[j] = nums[i];
            j++;
        }
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
        
       
    }
};