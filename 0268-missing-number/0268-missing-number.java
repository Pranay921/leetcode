class Solution {
    public int missingNumber(int[] nums) {
        // Arrays.sort(nums);
        int size=nums.length+1;
        int sum=size*(size-1)/2;
        int sum2=0;
        for(int i=0;i<nums.length;i++){
            sum2=sum2+nums[i];
        }
        return sum-sum2;
    }
}