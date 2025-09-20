class Solution {
public:
    bool canJump(vector<int>& nums) {
        // int n = nums.size();
        // if (n == 0) return false;
        // int first = nums[0];
        // if (n == 1 && nums[0] == 0) return true;
        // if (first == 0) return false;

        // int index = 0;
        // for (int i = 0; i < n; i++) {
        //     index = index + nums[i];

        //     if(index >= n) break;  // ✅ prevent out-of-range access

        //     if (index + 1 == n && nums[index] == 0) return true;

        //     if (index < n && nums[index] == 0 && index != n) {
        //         index = index - 1;
        //         if (index < 0) return false;  // extra safety
        //         index = index + nums[index];

        //         // ✅ boundary check before accessing nums[index]
        //         if (index >= n) return true;
        //         if (index < n && nums[index] == 0) return false;
        //     }

        //     if (index < n && nums[index] == 0 && index != n) return false;
        // }
        // return true;
        int maxreach=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxreach) return false;
            maxreach=max(maxreach,i+nums[i]);
        }
        return true;
    }
};
