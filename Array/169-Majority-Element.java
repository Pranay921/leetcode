class Solution {
    public int majorityElement(int[] nums) {
        if(nums.length==1) return nums[0];
        if(nums.length==0) return -1;
        int majority=nums[0],count=1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]==majority){
                count++;
            }
            else{
                count--;
                if(count==0){
                    majority=nums[i];
                    count=1;
                }
            }
        }
        return majority;
    }
}